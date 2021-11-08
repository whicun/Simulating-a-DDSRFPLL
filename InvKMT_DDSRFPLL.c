/******************************************************************************
*                                                                             *
*    file     : InvKMT_DSRFPLL.c					                      	  *	
*    project  : InvKMT.pjt													  *	
*    author  : Sergio A. Varón												  *
*                                                                             *
*******************************************************************************
*    description: Decoupled Sequence PLL									  *
*																			  *
*																			  *
*******************************************************************************
* Version 1.0 	08/02/12													  *	
*******************************************************************************/

#include "InvKMT_DDSRFPLL.h"

#include <math.h>

//#include "InvKMT_control_function_prototypes.h"
#include "objects.h"
//#include "InvKMT_parameters.h"
#include "InvKMT_structs.h"


/*
#ifdef UNLOCK_PLL
#pragma CODE_SECTION(InvKMT_DDSRFPLL_Hybrid,"ramfuncs");
#pragma CODE_SECTION(InvKMT_Transform_and_Decoupling_Hybrid,"ramfuncs");
#else
#pragma CODE_SECTION(InvKMT_DDSRFPLL,"ramfuncs");
#pragma CODE_SECTION(InvKMT_Transform_and_Decoupling,"ramfuncs");
#endif
#pragma CODE_SECTION(InvKMT_DDSRFPLL_ANALYSE,"ramfuncs");
*/

extern CONFIG config;
extern sParameters parameters;

extern float angle_adj;

extern const float Ts;
extern const float Fs;
extern const float coef_1Hz[2], coef_25Hz[2];
extern sProt_limits prot;
float freq_1 = 0;

float omega  = 0;
float freq   = 0;
float vco    = 0;
float theta  = 0;
float sinth  = 0;
float costh  = 0;
float sin2th = 0;
float cos2th = 0;

extern sPI PI_pll;

unsigned int entrada_sync = 0;

////////
float offset_pll = 0;
////////

void InvKMT_DDSRFPLL_Hybrid(sDDSRFPLL2 *referencia, Uint16 hab_pll_fast){

    // Transformadas y desacoples.
    InvKMT_Transform_and_Decoupling_Hybrid(referencia);

    //  Determinar el PLL a utilizar segun el desfasaje y la habilitacion de voltaje y frecuencia.
    if(hab_pll_fast){
        //  Sets PI del PLL.
        PI_pll.Kp = PI_PLL_GRID_KP_FAST;
        PI_pll.Ki = PI_PLL_GRID_KI_FAST;
        PI_pll.Kc = 1.0;
    }else{
        //  Sets PI del PLL.
        PI_pll.Kp = config.inv_ctrl_pll_kp;
        PI_pll.Ki = config.inv_ctrl_pll_ki;
        PI_pll.Kc = 1.0;
    }

    //  Sets PI del PLL.
    PI_pll.setpoint = 0;
    PI_pll.feedback = -(referencia->Qp);

    //  Ejecutar PI del PLL.
    InvKMT_Pifunc2(&PI_pll);

    omega = PI_pll.output + (parameters.freq_inv_nom + offset_pll) * DOSPI;

    // Frecuencia filtrada
    freq = (coef_1Hz[0] * freq) + coef_1Hz[1] * (omega * INVDOSPI + freq_1);
    freq_1 = omega * INVDOSPI;

    //  VCO
    vco = vco + Ts * omega;

    // Guardar valores anteriores para ser unsados en el proximo ciclo.
    theta = vco;
    sinth = sin(theta);
    costh = cos(theta);
    sin2th = sin(2 * theta);
    cos2th = cos(2 * theta);
}

void InvKMT_Transform_and_Decoupling_Hybrid(sDDSRFPLL2 *c){

    c->dq.sin = sinth;
    c->dq.cos = costh;

    //  Positive sequence
    InvKMT_clarke(&(c->abc), &(c->alfabeta));
    InvKMT_park(&(c->alfabeta), &(c->dq));
    c->Dpos = c->dq.d;
    c->Qpos = c->dq.q;

    //  Negative sequence
    c->dq.sin = -(c->dq.sin);
    InvKMT_park(&(c->alfabeta), &(c->dq));
    c->Dneg = c->dq.d;
    c->Qneg = c->dq.q;

    //  Decoulping of positive and negative sequences
    c->Dp = c->Dpos - c->Dnf * cos2th - c->Qnf * sin2th;
    c->Qp = c->Qpos + c->Dnf * sin2th - c->Qnf * cos2th;

    c->Dn = c->Dneg - c->Dpf * cos2th + c->Qpf * sin2th;
    c->Qn = c->Qneg - c->Dpf * sin2th - c->Qpf * cos2th;

    //  Low pass filter
    // Dp
    c->Dpf = (coef_25Hz[0] * c->Dpf) + coef_25Hz[1] * (c->Dp + c->Dp_1);
    c->Dp_1 = c->Dp;
    // Qp
    c->Qpf = (coef_25Hz[0] * c->Qpf) + coef_25Hz[1] * (c->Qp + c->Qp_1);
    c->Qp_1 = c->Qp;
    // Dn
    c->Dnf = (coef_25Hz[0] * c->Dnf) + coef_25Hz[1] * (c->Dn + c->Dn_1);
    c->Dn_1 = c->Dn;
    // Qn
    c->Qnf = (coef_25Hz[0] * c->Qnf) + coef_25Hz[1] * (c->Qn + c->Qn_1);
    c->Qn_1 = c->Qn;

    return;
}

void InvKMT_DDSRFPLL(sDDSRFPLL2 *inversor, sDDSRFPLL2 *referencia){
//	inversor->dq.sin = sinth;
//	inversor->dq.cos = costh;

	referencia->dq.sin = sinth;
	referencia->dq.cos = costh;

//	InvKMT_Transform_and_Decoupling(inversor);
	InvKMT_Transform_and_Decoupling(referencia);

	// PI controller
	switch(entrada_sync){
		case 0:
			PI_pll.setpoint = 0;
			PI_pll.feedback = -(referencia->Qp);
			break;
		case 1:
			PI_pll.setpoint = -(referencia->Qp);
			PI_pll.feedback = -(inversor->Qp);
			break;
	}
	InvKMT_Pifunc2(&PI_pll);

	omega = PI_pll.output + (parameters.freq_inv_nom + offset_pll) * DOSPI;

	// ------------- Frequency ------------------//
	// Filter freq
	freq = (coef_1Hz[0] * freq) + coef_1Hz[1] * (omega * 0.159154943 + freq_1);
	freq_1 = omega * 0.159154943;
	
	// ------------- VCO -----------------------//

	vco = vco + Ts * omega;

	// Guarda as variáveis para serem usadas no próximo ciclo
	theta  = vco;
	sinth  = sin(theta);
	costh  = cos(theta);
	sin2th = sin(2 * theta);
	cos2th = cos(2 * theta);
}

void InvKMT_Transform_and_Decoupling(sDDSRFPLL2 *c){
	
	InvKMT_clarke(&(c->abc), &(c->alfabeta));
	InvKMT_park(&(c->alfabeta), &(c->dq));
	c->Dpos	= c->dq.d;
	c->Qpos = c->dq.q;

	c->dq.sin = -(c->dq.sin);
	InvKMT_park(&(c->alfabeta), &(c->dq));
	c->Dneg	= c->dq.d;
	c->Qneg = c->dq.q;
	
	// Decoulping of positive and negcative sequences
	c->Dp = c->Dpos - c->Dnf * cos2th - c->Qnf * sin2th;
	c->Qp = c->Qpos + c->Dnf * sin2th - c->Qnf * cos2th;
	c->Dn = c->Dneg - c->Dpf * cos2th + c->Qpf * sin2th;
	c->Qn = c->Qneg - c->Dpf * sin2th - c->Qpf * cos2th;

	// Dp
	c->Dpf  = (coef_25Hz[0] * c->Dpf) + coef_25Hz[1] * (c->Dp + c->Dp_1);
	c->Dp_1 = c->Dp;
	// Qp
	c->Qpf  = (coef_25Hz[0] * c->Qpf) + coef_25Hz[1] * (c->Qp + c->Qp_1);
	c->Qp_1 = c->Qp;
	// Dn
	c->Dnf  = (coef_25Hz[0] * c->Dnf) + coef_25Hz[1] * (c->Dn + c->Dn_1);
	c->Dn_1 = c->Dn;
	// Qn
	c->Qnf  = (coef_25Hz[0] * c->Qnf) + coef_25Hz[1] * (c->Qn + c->Qn_1);
	c->Qn_1 = c->Qn;

	return;
}

void InvKMT_DDSRFPLL_ANALYSE(sDDSRFPLL *c, Uint16* fault_out){
	float temp;
	Uint16 fault = 0;

	// Testa se a tensão de eixo d da sequencia positiva é maior que 0
	if(c->Dpf < 0)
	{
		fault |= DSRF_FAULT_DPNEG;
	}
	
	// Testa se a tensao de eixo d de sequencia negativa é menor que 50% da de sequencia positiva	
	temp = fabs(c->Dpf * 0.5);
	if( (fabs(c->Qnf) > temp) || (fabs(c->Dnf) > temp) ) fault |= DSRF_FAULT_NHIGH;

	// Testa se a tensao de eixo q sequência positiva é menor que 0.10
	temp = fabs(c->Dpf * 0.3);
	if( fabs(c->Qpf) > temp ) fault |= DSRF_FAULT_QPHIGH;
	
	*fault_out = fault;
}

