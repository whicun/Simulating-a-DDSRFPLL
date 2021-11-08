/******************************************************************************
*                                                                             *
*    file     : InvKMT_structs.h	                                    	  *
*    project  : Inversor KMT												  *	
*    authors  : Sergio A. Varón												  *
*                                                                             *
*******************************************************************************
*    description: definición de estructuras y valores "Default"				  *
*																			  *
*******************************************************************************
* Version 1.0 	03/02/12													  *																			  
*******************************************************************************/


#ifndef _INVKMT_STRUCTS_H_
#define _INVKMT_STRUCTS_H_

//#include <stdio.h>
#include <stddef.h>
#include "DSP2833x_Device.h"     // DSP281x Headerfile Include File

#include "InvKMT_PIfunc2.h"

/*
typedef struct{
		float a;
		float b;
		float c;
} sABC;

#define ABC_DEFAULTS {\
						0,0,0}

typedef struct{
		float alfa;
		float beta;

} sAlfaBeta;

#define ALFABETA_DEFAULTS {\
						0,0}

typedef struct{
		float d;
		float q;
		float sin;
		float cos;
} sDQ;

#define DQ_DEFAULTS {\
						0,0,0,0}
*/

typedef struct {
	float alfa;
	float beta;
	float alfa_1;
} sAlfaBetafilt;

#define ALFABETA_FILT_DEFAULTS	{0.0, 0.0, 0.0}

typedef struct{

	float Vca_inv;
	float Vab_inv;
	float Vbc_inv;
	float Va_inv;
	float Vb_inv;
	float Vc_inv; 
	float Vab_bp;
	float Vbc_bp;
	float Vca_bp;
	float Va_bp;
	float Vb_bp;
	float Vc_bp;
	float Ia_inv;
	float Ib_inv;
	float Ic_inv;
	float Ia_sal;
	float Ib_sal;
	float Ic_sal;
	float Vdc;
	float Icc;
	float P;
	float Q;
	float S;
	float FP;
	float energy;
	Uint16 new_data;
}sMeas;

#define RMS_DEFAULTS	{\
						0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}

//================================//
typedef struct{
	float CH_1;
	float CH_2;
	float CH_3; //(FK)
	float CH_4;
	float CH_5;
	float CH_6;
	float CH_7;
	float CH_8;
	float CH_9;
	float CH_10;
	float CH_11;
	float CH_12;
	float CH_13;
	float CH_14;
	float CH_15;
	float CH_16;
}sChannel_adc;

#define MEDIOS_DEFAULTS		{\
							0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}

#define CHANNEL_DEFAULTS	{\
	 						0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
//=================================//


typedef struct{

	float Vab_inv;
	float Vbc_inv;
	float Vca_inv;
	float Va_inv;
	float Vb_inv;
	float Vc_inv; 
	float Vab_bp;
	float Vbc_bp;
	float Vca_bp;
	float Va_bp;
	float Vb_bp;
	float Vc_bp;
	float Ia_inv;
	float Ib_inv;
	float Ic_inv;
	float Ia_sal;
	float Ib_sal;
	float Ic_sal;
	float Vdc;
	float Icc;

}sSignal_red;

#define SIGNAL_RED_DEFAULTS	{\
  						0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}


/*
typedef struct {
	float feedback;
	float setpoint;
	float error;
	float prop;
	float integr;
	float Kp;
	float Ki;
	float Kc;
	float output;
	float outMin;
	float outMax;
	float preSat;
	float satError;
	float integr_init;
	float feedforward;
	Uint16 enab;
	} sPI;

#define PI_I_INV_DEFAULTS {\
						0, 0, 0, 0, 0, PI_I_INV_KP, PI_I_INV_KI, PI_I_INV_KC, 0,\
						PI_I_INV_OUTMIN, PI_I_INV_OUTMAX, 0, 0, 0, 0, 0}

#define PI_U_INV_DEFAULTS {\
						0, 0, 0, 0, 0, PI_U_INV_KP, PI_U_INV_KI, PI_I_INV_KC, 0,\
						PI_I_INV_OUTMIN, PI_I_INV_OUTMAX, 0, 0, 0, 0, 0} 



#define PI_I_GEN_DEFAULTS {\
					    0, 0, 0, 0, 0, PI_I_GEN_KP, PI_I_GEN_KI, PI_I_GEN_KC, 0,\
					    PI_I_GEN_OUTMIN, PI_I_GEN_OUTMAX, 0, 0, 0, 0, 0}

#define PI_M_DEFAULTS {\
						0, 0, 0, 0, 0, PI_M_KP, PI_M_KI, PI_M_KC, 0,\
						PI_M_OUTMIN, PI_M_OUTMAX, 0, 0, 0, 0, 0} 

#define PI_VGRID_DEFAULTS {\
						0, 0, 0, 0, 0, PI_VGRID_KP, PI_VGRID_KI, PI_VGRID_KC, 0,\
						PI_VGRID_OUTMIN, PI_VGRID_OUTMAX, 0, 0, 0, 0, 0} 


#define PI_PLL_GRID_DEFAULTS {\
						0, 0, 0, 0, 0, PI_PLL_GRID_KP, PI_PLL_GRID_KI, PI_PLL_GRID_KC,\
						0,PI_PLL_GRID_OUTMIN , PI_PLL_GRID_OUTMAX, 0, 0, 0, 0, 0}

#define PI_SLOW_PLL_GRID_DEFAULTS {0, 0, 0, 0, 0, PI_PLL_GRID_KP_SLOW, PI_PLL_GRID_KI_SLOW, PI_PLL_GRID_KC_SLOW,\
						0,PI_PLL_GRID_OUTMIN_SLOW, PI_PLL_GRID_OUTMAX_SLOW, 0, 0, 0, 0, 0}

#define PI_FAST_PLL_GRID_DEFAULTS {0, 0, 0, 0, 0, PI_PLL_GRID_KP_FAST, PI_PLL_GRID_KI_FAST, PI_PLL_GRID_KC_FAST,\
						0,PI_PLL_GRID_OUTMIN_FAST , PI_PLL_GRID_OUTMAX_FAST, 0, 0, 0, 0, 0} 

*/

typedef struct {
	float Un;
	float Un_1;
	float Yn;
	} sFilter1st;

#define FILTER_DEFAULTS {\
						0,0,0}


#define FILTER_COEF_2000HZ_20kHz {\
								0.509525449494429,0.245237275252786}

#define FILTER_COEF_1000HZ_20kHz {\
								0.726542528005361,0.136728735997319}

#define FILTER_COEF_900HZ_20kHz {\
								0.750821238038765,0.124589380980618}

#define FILTER_COEF_750HZ_20kHz {\
								0.788336434585093,0.105831782707454}

#define FILTER_COEF_500HZ_20kHz {\
								0.854080685463467,0.072959657268267}

#define FILTER_COEF_400HZ_20kHz {\
								0.881618592363189,0.059190703818405}
								
#define FILTER_COEF_350HZ_20kHz {\
								0.895674708370473,0.052162645814764} 

#define FILTER_COEF_200HZ_20kHz {\
								0.939062505817492,0.030468747091254} 

#define FILTER_COEF_100HZ_20kHz {\
								0.969067417193793,0.015466291403103} 

#define FILTER_COEF_50HZ_20kHz {\
								0.984414127416097,0.007792936291952}

#define FILTER_COEF_25HZ_20kHz {\
								0.992176700177507,0.003911649911247} 

#define FILTER_COEF_10HZ_20kHz {\
								0.996863331833438,0.001568334083281} 

#define FILTER_COEF_1HZ_20kHz {\
								0.999685890072330,0.000157054963835168} 

#define FILTER_COEF_400_RAD_SEG_20kHz {\
								0.980197366244355,0.009901316877822} 

#define FILTER_COEF_800_RAD_SEG_20kHz {\
								0.960779186677066,0.019610406661467} 

//	==> y(k)= b1/b0 * y(k-1) - b2/b0 * y(k-2) + ki_xH * {a1/b0 * in(k) - a2/b0 * in(k-2)}
typedef struct {
	float En;
	float En_1;
	float En_2;
	float Yn;
	float Yn_1;
	float Yn_2;	
} sHFilter;

#define HFILTER_DEFAULTS {\
						0,0,0,0,0,0}

//	coef[5]= {a1, a2, b0, b1, b2}

// Coheficientes para 50 Hz
#define H1TH_50Hz_FILTER_COEF_20kHz {\
										0.002000000000000, 0.002000000000000, 4.002246740110027, 7.999506519779946, 3.998246740110028} 

#define H3TH_50Hz_FILTER_COEF_20kHz {\
										0.002000000000000, 0.002000000000000, 4.004220660990245, 7.995558678019510, 4.000220660990245} 

#define H5TH_50Hz_FILTER_COEF_20kHz {\
										0.002000000000000, 0.002000000000000, 4.008168502750681, 7.987662994498638, 4.004168502750681} 

#define H7TH_50Hz_FILTER_COEF_20kHz {\
										0.002000000000000, 0.002000000000000, 4.014090265391334, 7.975819469217331, 4.010090265391335} 

#define H9TH_50Hz_FILTER_COEF_20kHz {\
										0.002000000000000, 0.002000000000000, 4.021985948912206, 7.960028102175588, 4.017985948912206} 

#define H11TH_50Hz_FILTER_COEF_20kHz {\
										0.002000000000000, 0.002000000000000, 4.031855553313295, 7.940288893373410, 4.027855553313295} 

// Coheficientes para 60 Hz
#define H1TH_60Hz_FILTER_COEF_20kHz {\
										0.002000000000000, 0.002000000000000, 4.002355305758439, 7.999289388483121, 3.998355305758439} 

#define H3TH_60Hz_FILTER_COEF_20kHz {\
										0.002000000000000, 0.002000000000000, 4.005197751825953, 7.993604496348094, 4.001197751825953} 

#define H5TH_60Hz_FILTER_COEF_20kHz {\
										0.002000000000000, 0.002000000000000, 4.010882643960980, 7.982234712078039, 4.006882643960981} 

#define H7TH_60Hz_FILTER_COEF_20kHz {\
										0.002000000000000, 0.002000000000000, 4.019409982163522, 7.965180035672957, 4.015409982163521} 

#define H9TH_60Hz_FILTER_COEF_20kHz {\
										0.002000000000000, 0.002000000000000, 4.030779766433576, 7.942440467132847, 4.026779766433577} 

#define H11TH_60Hz_FILTER_COEF_20kHz {\
										0.002000000000000, 0.002000000000000, 4.030779766433576, 7.942440467132847, 4.026779766433577} // (COMPLETAR) Estan mal estos valores

/*
typedef struct {
	float Up;
	float Ui;
	float Uout;
	float freq;
	float omega;
	float sinth;
	float costh;
	float sin2th;
	float cos2th;
	float vco;
	float theta;
	float alfa;
	float beta;
	float Dpos;
	float Qpos;
	float Dneg;
	float Qneg;
	float Dp;
	float Qp;
	float Dn;
	float Qn;
	float Dpf;
	float Qpf;
	float Dnf;
	float Qnf;
	float Dp_1;
	float Qp_1;
	float Dn_1;
	float Qn_1;
	sPI PI_pll;

} sDDSRFPLL;

#define DDSRFPLL_DEFAULTS {\
			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, PI_PLL_GRID_DEFAULTS}

typedef struct {
	sABC		abc;
	sAlfaBeta	alfabeta;
	sDQ			dq;
	float		Dpos;
	float		Qpos;
	float		Dneg;
	float		Qneg;
	float		Dp;
	float 		Qp;
	float 		Dn;
	float 		Qn;
	float 		Dpf;
	float 		Qpf;
	float 		Dnf;
	float 		Qnf;
	float 		Dp_1;
	float 		Qp_1;
	float 		Dn_1;
	float 		Qn_1;
} sDDSRFPLL2;

#define DDSRFPLL2_DEFAULTS {\
			ABC_DEFAULTS,ALFABETA_DEFAULTS,DQ_DEFAULTS,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
*/

typedef struct{
	float Vin;			// Input: Input voltage in pu
	float freq;			// Output: Fundamental Frequency
	float theta;		// Output: Theta Thyristor 1
	float Kp;			// Parameter: PI Proportional Gain
	float Ki;			// Parameter: PI Integral Gain
	float Kc;			// Parameter: PI Anti windup Gain
	float Up;			// Variable: PI Proportional Output
	float Ui;			// Variable: PI Integrall Output
	float Out;			// Variable: PI Output
	float OutPresat;	// Variable: PI Pre Saturated Output
	float OutMax;		// Parameter: PI Minimum Otput
	float OutMin;		// Parameter: PI Minimum Otput
	float Err;			// Variable: PI Error
	Uint16 enab;
} sPLL;
// wn = 2*pi*1 Vs = 1.0

#define SPLL_DEFAULTS {\
					  0,0,0,PI_SPLL_KP,PI_SPLL_KI,PI_SPLL_KC,0,0,0,0,PI_SPLL_GRID_OUTMAX,PI_SPLL_GRID_OUTMIN,0,0} 


typedef struct{

	unsigned int EmergencyFlag :1;
	unsigned int GridPulsesOn :1;
	unsigned int run_Grid :1;
	unsigned int run_Gen :1;
	unsigned int run_Logic :1;
	unsigned int run_Comm :1;
	unsigned int first_scan:1;
}sFlags;

#define FLAGS_DEFAULTS {0,0,0,0,0,0,1}

typedef struct{
	float P_inv_nom;

	float V_inv_nom;	
	float V_inv_nom_max;
	float V_inv_nom_min;

	float I_inv_nom;	

	float freq_inv_nom;
	float freq_inv_min;   // Frecuencia minima
	float freq_inv_max;   // Fracuencia maxima

	float ang_def;        //  Desfasaje de angulo entre referencia interna y entrada de señal.
	float angle_slope;    //  INV angle slope tracking
	float sinc_range;     //  INV sincronization range

	float V_out_nom;	
	float I_out_nom;	
	float Vdc_nom;

	float Gain_Vab_bp;
	float Gain_Vbc_bp;
	float Gain_Vca_inv;
	float Gain_Vab_inv;
//	float Gain_Vbc_inv; //(FK)
	float Gain_Ia_inv;
	float Gain_Ib_inv;
	float Gain_Ia_sal;
	float Gain_Ib_sal;
	float Gain_Ic_sal;
	float Gain_Vdc;
	float Gain_Icc;

	float Offset_Vab_bp;
	float Offset_Vbc_bp;
	float Offset_Vca_inv;
	float Offset_Vab_inv;
	float Offset_Ia_inv;
	float Offset_Ib_inv;
	float Offset_Ia_sal;
	float Offset_Ib_sal;
	float Offset_Ic_sal;
	float Offset_Vdc;
	float Offset_Icc;
	float Trafo_Ratio;
} sParameters;

#define SYS_PARAMETERS_DEFAULTS {\
						P_INV_NOM, V_INV_NOM, DELTA_V_INV_NOM, DELTA_V_INV_NOM, I_INV_NOM, FREQ_INV_NOM, FREQ_INV_MIN, FREQ_INV_MAX,\
						ANG_DESF, DELTA_OMEGA_ERR, SYNC_RANGE, V_OUT_NOM, I_OUT_NOM, VDC_NOM,\
						GAIN_VRS_BP, GAIN_VST_BP, GAIN_VTR_INV, GAIN_VRS_INV,\
						GAIN_INV_IR, GAIN_INV_IS, GAIN_OUT_IR, GAIN_OUT_IS, GAIN_OUT_IT, GAIN_VDC,\
						GAIN_ICC, OFFSET_VRS_BP, OFFSET_VST_BP, OFFSET_VRS_INV, OFFSET_VST_INV,\
						OFFSET_INV_IR, OFFSET_INV_IS, OFFSET_OUT_IR, OFFSET_OUT_IS, OFFSET_OUT_IT,\
						OFFSET_VDC, OFFSET_ICC, TRAFO_RATIO}

/*
#define SYS_PARAMETERS_DEFAULTS {\
						P_INV_NOM, V_INV_NOM, I_INV_NOM, FREQ_INV_NOM, V_OUT_NOM, I_OUT_NOM,\
						VDC_NOM, GAIN_VRS_BP, GAIN_VST_BP, GAIN_VTR_INV, GAIN_VRS_INV,\
						GAIN_INV_IR, GAIN_INV_IS, GAIN_OUT_IR, GAIN_OUT_IS, GAIN_OUT_IT, GAIN_VDC,\
						GAIN_ICC, OFFSET_VRS_BP, OFFSET_VST_BP, OFFSET_VRS_INV, OFFSET_VST_INV,\
						OFFSET_INV_IR, OFFSET_INV_IS, OFFSET_OUT_IR, OFFSET_OUT_IS, OFFSET_OUT_IT,\
						OFFSET_VDC, OFFSET_ICC, TRAFO_RATIO}
*/

struct DATA_BITS {       // bits   description

   Uint16 bit0 : 1;          // 0 bit0
   Uint16 bit1 : 1;          // 1 bit1
   Uint16 bit2 : 1;          // 2 bit2
   Uint16 bit3 : 1;          // 3 bit3
   Uint16 bit4 : 1;          // 4 bit4
   Uint16 bit5 : 1;          // 5 bit5
   Uint16 bit6 : 1;          // 6 bit6
   Uint16 bit7 : 1;          // 7 bit7
   Uint16 bit8 : 1;          // 8 bit8
   Uint16 bit9 : 1;          // 9 bit9
   Uint16 bit10 : 1;         // 10 bit10
   Uint16 bit11 : 1;         // 11 bit11
   Uint16 bit12 : 1;         // 12 bit12
   Uint16 bit13 : 1;         // 13 bit13
   Uint16 bit14 : 1;         // 14 bit14
   Uint16 bit15 : 1;         // 15 bit15
};


typedef union{
   Uint16            all;
   struct DATA_BITS  bit;
}DATA;

typedef struct{

	Uint16 Ta;
	Uint16 Tb;
	Uint16 Tc;
	Uint16 mod_method;

} sSvm;

#define SVPWM_DEFAULTS {\
  						0,0,0,0} 
#define DPWM1_DEFAULTS {\
  						0,0,0,0} //(FK) (AQUI) 


typedef struct{
	float final;
	float actual;
	float delta;
} sRamp;

#define RAMP_DEFAULTS {\
  						0,0,0}

#define RAMP_M_DEFAULTS {\
  						M_SETPOINT,0,RAMP_M_SLOPE*TSAMPLE_GRID}

#define RAMP_VGRID_DEFAULTS {\
  							 V_INV_NOM,0,RAMP_VGRID_SLOPE*TSAMPLE_GRID}

#define RAMP_VGRID_DEFAULTS_B {\
		  						5.0,0,RAMP_VGRID_SLOPE*TSAMPLE_GRID}

#define RAMP_ANGLE_DEFAULTS {\
  						 0,0,RAMP_ANGLE_SLOPE*TSAMPLE_GRID}

							   

typedef struct{

	float  igbt_sat_time;
	float  low_Vcc_level;
	Uint32 low_Vcc_time;
	float low_Vcc_hyst;
	float high_Vcc_level;
	Uint32 high_Vcc_time;
	float high_vcc_hyst;
	Uint32 batt_brk_opended_time;
	Uint32 over_tmp_prot_time;
	Uint32 vent_failure_time;
	Uint32 grid_ctrl_sat_time;
	float over_load_1min;
	float over_load_10min;
	float over_load_hold;
	float very_low_Vcc_level;
	Uint32 very_low_Vcc_time;
	Uint32 outfus_opnd_time;
	Uint32 infus_opnd_time;
	Uint32 pwrsupply_fail_time;

} sProt_limits;


#define PROT_LIMITS_DEFAULTS {\
							  IGBT_SAT_TIME_CNTR, LOW_VCC_LEVEL, LOW_VCC_TIME_CNTR, LOW_VCC_HYST,\
							  HIGH_VCC_LEVEL, HIGH_VCC_TIME_CNTR, HIGH_VCC_HYST,BATT_BRK_OPENED_TIME_CNTR,\
							  OVER_TMP_PROT_TIME_CNTR, VENT_FAILURE_TIME_CNTR, GRID_CTRL_SAT_TIME_CNTR,\
							  OVR_LOAD_1MIN, OVR_LOAD_10MIN, OVR_LOAD_HOLD,VERY_LOW_VCC_LEVEL,VERY_LOW_VCC_TIME_CNTR,\
							  OUTPUT_FUS_OPND_TIME_CNTR, INPUT_FUS_OPND_TIME_CNTR, PWRSUPPLY_FAIL_TIME_CNTR}



typedef struct {
	Uint16 div_freq;
	Uint16 Positive_Slope;
	Uint16 Graphs;
	float trigger_threshold;
	float *p_Channel_1;
	float *p_Channel_2;
	float *p_Channel_3;
	float *trigger_variable;
	float old_trigger_variable;
	Uint16 num_pretrigger_samples;

	} sDataLog;

#define DATALOG_REG_DEFAULTS {\
							1, 1, 1, 0.01, 0, 0, 0, 0, 0, 55}  



typedef struct {
	float error_sync_axis_d;
	float error_sync_axis_q;
	float setpoint;
	float error;
	float prop;
	float integr;
	float Kp;
	float Ki;
	float Kc;
	float output_D;
	float output_Q;
	float outMin;
	float outMax;
	float preSat;
	float satError;
	float integr_init;
	Uint16 enab;
	sPI PI_D_5th;
	sPI PI_Q_5th;
	sPI PI_D_7th;
	sPI PI_Q_7th;
} sHarmonics_filter;


#define HARMONICS_FILTER_DEFAULTS {\
						0, 0, 0, 0, 0, 0, 0.001, 0.05, 1, 0,0, -2.0, 2.0, 0, 0, 0, 0} 
#endif
