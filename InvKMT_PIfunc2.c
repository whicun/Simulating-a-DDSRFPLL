/******************************************************************************
*                                                                             *
*    file     : InvKMT_PIfunc.c						                      	  *	
*    project  : Inversor KMT.pjt											  *	
*    authors  : Sergio A. Varon											  	  *
*                                                                             *
*******************************************************************************
*    description: En este programa implementa una función genérica para un 	  *
*				  controlador PI											  *
*																			  *
*******************************************************************************
* Version 1.0 	08/02/12													  *	
*******************************************************************************/

#include "DSP2833x_Device.h"
#include "InvKMT_PIfunc2.h"

#include "InvKMT_parameters.h"
#include <math.h>

//#include "InvKMT_control_function_prototypes.h"

//#pragma CODE_SECTION(InvKMT_Pifunc2,"ramfuncs");

sPI PI_pll = PI_PLL_GRID_DEFAULTS;

extern volatile unsigned int enab;
extern const float Ts;
char enable_wind_up = 0;


Uint16 InvKMT_Pifunc2(sPI *reg) {	
	Uint16 is_sat = 0;

	if(reg->enab == 1){
		reg->error  = reg->setpoint -  reg->feedback;
		reg->prop   = reg->Kp * reg->error;
#ifdef UNLOCK_PLL
		reg->integr = reg->integr + (reg->Ki * (reg->error * Ts)) + (reg->Kc * reg->satError);
#else
		reg->integr = reg->integr + reg->Ki * Ts * reg->error;
#endif
	}else{
		reg->error  = 0.0;
		reg->prop   = 0.0;
		reg->integr = reg->integr_init;
	}

	reg->preSat = reg->integr + reg->prop;
	
	if(reg->enab == 1){
		if(reg->preSat > reg->outMax){
			reg->output = reg->outMax;
			is_sat      = POSITIVE_SAT;
		}else if (reg->preSat < reg->outMin){
			reg->output = reg->outMin;	 
			is_sat      = NEGATIVE_SAT;
		}else{
			reg->output = reg->preSat;
			is_sat      = NOT_SAT;
		}	
	}else{
		// si el controlador esta deshabilitado, no hay saturacion
		reg->output = reg->preSat;
		is_sat      = 0;
	}

	reg->satError = reg->output - reg->preSat;

   //------------- función anti windup----------------//
	if(enable_wind_up == 1){
		if (reg->preSat!=reg->output)
			reg->integr = (reg->Kc* reg->output) - (reg->prop + reg->feedforward);
	}
	return is_sat;
}
