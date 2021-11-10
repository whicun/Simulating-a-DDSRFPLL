
#ifndef 	__INVKMT_PARAMETERS_H__
#define 	__INVKMT_PARAMETERS_H__

#define	N_SAMPLES			400
#define REC_N_SAMPLES		1.0/(N_SAMPLES)

// CONSTANTS DEFINITION
#define	RAIZ2				1.41421356
#define INV_RAIZ2			0.70710678
#define INV3				0.33333333
#define DOS_INV3			0.66666667
#define RAIZ3				1.73205080
#define INV_RAIZ3			0.57735026
#define INV_60				0.01666667
#define SQRT2_INV3			0.47140452	// sqrt(2)/3
#define SQRT_2_INV3			0.81649658	// sqrt(2/3)
#define INVPI				0.31830989	// 1/PI
#define INVDOSPI			0.15915494  // 1/(2*PI)
#define DOSPI				6.28318530  // 2*PI  
#define PI					3.14159265  // PI
#define RPM2RADSEG			0.104719
#define RAD2DEG				0.01745329
#define DEG2RAD				57.2957877
#define COS30				0.866025403
#define SIN30				0.5

#define MINIMUM_PULSE_TIME 		0  	// Minimum pulse width 900 = 6us*150MHz 

// FAULT CONSTANTS DEFINITION
#define FAULT_OK				0
#define FAULT_OVERVOLTAGE		0x0001
#define FAULT_UNDERVOLTAGE		0x0002
#define FAULT_GRID_OVERCURRENT	0x0004
#define FAULT_GRID_OVERTEMP		0x0008
#define FAULT_DRIVER			0x0010
#define	FAULT_PLL				0x0020
#define	FAULT_CHOPPER			0x0040
#define	FAULT_CHOPPER2			0x0080
//////////////////////////////////
#define	FAULT_GRID_OVR_VOLTAGE	0x0100
#define	FAULT_GRID_UND_VOLTAGE	0x0200
//////////////////////////////////
#define FAULT_GEN_OVERCURRENT	0x0400
#define FAULT_GEN_OVERTEMP		0x0800


#define NO_STATE				0x0000
#define INITIALIZING_ST			0x0001
#define STAND_BY_ST				0x0002
#define PREOPERATION_ST			0x0004
#define OPERATION_ST			0x0008
#define SYSTEM_OK_ST			0x0010


// PI Controllers saturation
#define NOT_SAT			0
#define POSITIVE_SAT	1
#define NEGATIVE_SAT	2

// DSRF-PLL FAULTS DEFINITION
#define DSRF_FAULT_OK 0
#define DSRF_FAULT_UND_FREQ 1
#define DSRF_FAULT_OVR_FREQ 2
#define DSRF_FAULT_DPNEG 4
#define DSRF_FAULT_NHIGH 8
#define DSRF_FAULT_QPHIGH 16


// PROTECTION LIMITS
#define IGBT_SAT_TIME			100e-6	//100 useg			
#define LOW_VCC_LEVEL			100.0 	// Volts
#define LOW_VCC_TIME			10.0 	// seg
#define LOW_VCC_HYST			5.0	 	// %	
#define HIGH_VCC_LEVEL			155.0	// Volts		
#define HIGH_VCC_TIME			10.0	// seg
#define HIGH_VCC_HYST			5.0		// %
#define BATT_BRK_OPENED_TIME	0.5		// seg
#define OVER_TMP_PROT_TIME		2.0		// seg
#define VENT_FAILURE_TIME		2.0		// seg
#define GRID_CTRL_SAT_TIME		0.1		// seg
#define OVR_LOAD_1MIN			150		// %
#define OVR_LOAD_10MIN			125		// %
#define OVR_LOAD_HOLD			105		// %
#define OUTPUT_FUS_OPND_TIME	2.0		// seg
#define INPUT_FUS_OPND_TIME		2.0		// seg
#define PWRSUPPLY_FAIL_TIME		2.0		// seg
#define VERY_LOW_VCC_LEVEL		0.0		// Volts // OJO!!! poner en unvalor real (COMPLETAR)
#define VERY_LOW_VCC_TIME		200e-3	// 200 mseg
/*#define OVER_CURRENT_LIMIT		3000.0	// Amps
#define DC_OVERVOLTAGE_LIMIT 	1200.0	// Volts
#define OVERTEMP_LIMIT			120.0	// oC
#define OVER_FREQ_LIMIT			60.0	// Hz
#define UNDER_FREQ_LIMIT		40.0	// Hz
#define OVER_SPEED_LIMIT		30.0	// rpm
#define OVER_SPEED_MOTOR_LIMIT  10.0	// rpm
#define OVER_GRID_VOLTAGE_LIMIT 850.0	// RMS phase voltage
#define UNDER_GRID_VOLTAGE_LIMIT 600.0 // RMS phase voltage
#define CURRENT_UNBAL_LIMIT 	100 	// 20700 = 3s = 3*6900;
#define CURRENT_UNBAL_TIMER		1.5*50	// 1.5s
//////////////////////////////////////
#define VOLTAGE_UNBAL_LIMIT		50		//Volts
#define VOLTAGE_UNBAL_TIMER		1.5*50	// 1.5s
////////////////////////////////////// 
*/

//DEFAULT VALUES AND OTHERS DEFINITIONS
#define P_INV_NOM				30.0	// kW
#define V_INV_NOM				220.0	// Volt
#define I_INV_NOM				(1000*P_INV_NOM*INV_RAIZ3/V_INV_NOM) // Amp
#define	FREQ_INV_NOM			50	// Hz (COMPLETAR) 50 Hz / 60 Hz
#define DELTA_FREQ_INV    		1.5//2.5     // Delta de frecuencia en Hz.
#define FREQ_INV_MIN      		(FREQ_INV_NOM - DELTA_FREQ_INV)   // Hz.
#define FREQ_INV_MAX      		(FREQ_INV_NOM + DELTA_FREQ_INV)   // Hz.

#define DELTA_V_INV_NOM   		0.1     // Porcentaje de desvio de la salida en Volt
#define DELTA_OMEGA_ERR   		0.01    // Grados.
#define ANG_DESF          		(-2.52) // Grados.
#define SYNC_RANGE        		0.01    // Grados.

#define V_OUT_NOM				64	// Volt
#define I_OUT_NOM				(1000*P_INV_NOM*INV_RAIZ3/V_OUT_NOM) //Amp

#define VDC_NOM					125.0	// Volt
#define GAIN_VRS_BP				1.72	//(FK)
#define GAIN_VST_BP				1.72	//(FK)
#define GAIN_VTR_INV			1.63	//(FK) // Vca_inv
#define GAIN_VRS_INV			1.605	//(FK) // Vab_inv
#define GAIN_INV_IR				1.85
#define GAIN_INV_IS				1.86
#define GAIN_OUT_IR				1.0
#define GAIN_OUT_IS				1.0
#define GAIN_OUT_IT				1.0
#define GAIN_VDC				1.88	//(FK)
#define GAIN_ICC				1.0
#define OFFSET_VRS_BP			0.0
#define OFFSET_VST_BP			0.0
#define OFFSET_VRS_INV			0.0
#define OFFSET_VST_INV			0.0
#define OFFSET_INV_IR			0.0
#define	OFFSET_INV_IS			0.0
#define OFFSET_OUT_IR			0.0
#define OFFSET_OUT_IS			0.0
#define OFFSET_OUT_IT			0.0
#define OFFSET_VDC				0.0
#define OFFSET_ICC				0.0
#define TRAFO_RATIO				(V_INV_NOM / V_OUT_NOM)

#define INV_TRAFO_RATIO			(1 / TRAFO_RATIO)
#define INV_TRAFO_RATIO_RAIZ3	(INV_TRAFO_RATIO * INV_RAIZ3)	// (1 / 3.25 * sqrt(3))

#define M_SETPOINT				1.0

#define FREQ_PWM				10000.0 // Frecuencia de PWM
#define	FREQ_GRID_SAMPLE		20000.0//6900.0
#define FREQ_LOGIC_SAMPLE		1725.0
#define FREQ_COMM_SAMPLE		1725.0
#define TSAMPLE_GRID			1.0/(FREQ_GRID_SAMPLE)
#define TSAMPLE_GEN				1.0/(FREQ_GEN_SAMPLE)
#define TSAMPLE_LOGIC			1.0/(FREQ_LOGIC_SAMPLE)
#define TSAMPLE_COMM			1.0/(FREQ_COMM_SAMPLE)


// TIME CONSTANTS (s)
#define STARTSEQ_TOUT		5

#define PLL_LOCKED_TIME		1.0
#define PLL_LOCKED_CNT		PLL_LOCKED_TIME*FREQ_GRID_SAMPLE

#define IGBT_SAT_TIME_CNTR			IGBT_SAT_TIME*FREQ_GRID_SAMPLE 			// cuentas de Ts
#define LOW_VCC_TIME_CNTR			LOW_VCC_TIME*FREQ_GRID_SAMPLE 			// cuentas de Ts
#define HIGH_VCC_TIME_CNTR			HIGH_VCC_TIME*FREQ_GRID_SAMPLE 			// cuentas de Ts
#define BATT_BRK_OPENED_TIME_CNTR	BATT_BRK_OPENED_TIME*FREQ_GRID_SAMPLE 	// cuentas de Ts
#define OVER_TMP_PROT_TIME_CNTR		OVER_TMP_PROT_TIME*FREQ_GRID_SAMPLE 	// cuentas de Ts
#define VENT_FAILURE_TIME_CNTR		VENT_FAILURE_TIME*FREQ_GRID_SAMPLE		// cuentas de Ts
#define GRID_CTRL_SAT_TIME_CNTR		GRID_CTRL_SAT_TIME*FREQ_GRID_SAMPLE		// cuentas de Ts
#define OUTPUT_FUS_OPND_TIME_CNTR	OUTPUT_FUS_OPND_TIME*FREQ_GRID_SAMPLE	// cuentas de Ts
#define INPUT_FUS_OPND_TIME_CNTR	INPUT_FUS_OPND_TIME*FREQ_GRID_SAMPLE	// cuentas de Ts
#define PWRSUPPLY_FAIL_TIME_CNTR	PWRSUPPLY_FAIL_TIME*FREQ_GRID_SAMPLE	// cuentas de Ts
#define VERY_LOW_VCC_TIME_CNTR		VERY_LOW_VCC_TIME*FREQ_GRID_SAMPLE		// cuentas de Ts


// CONTROLLERS DEFAULT VALUES
// Currente grid
#define PI_I_INV_KP			0.005 // Alternativo 0.5
#define PI_I_INV_KI			1.0 // Alternativo 24
#define PI_I_INV_KC			1.0
#define PI_I_INV_OUTMAX		60.0
#define PI_I_INV_OUTMIN	   -60.0

// Modulation Index control
#define PI_U_INV_KP			1.0
#define PI_U_INV_KI			300.0
#define PI_U_INV_KC			1.0
#define PI_U_INV_OUTMAX		500
#define PI_U_INV_OUTMIN	   -500
//#define RAMP_M_SLOPE	30 

// Modulation Index control
#define PI_M_KP			5.0
#define PI_M_KI			50.0
#define PI_M_KC			1.0
#define PI_M_OUTMAX		2500
#define PI_M_OUTMIN		-2500
#define RAMP_M_SLOPE	30

// Grid voltage control
#define PI_VGRID_KP			0.03
#define PI_VGRID_KI			0.1
#define PI_VGRID_KC			1.0
#define PI_VGRID_OUTMAX		1.0
#define PI_VGRID_OUTMIN		0.0

#define RAMP_VGRID_SLOPE	10
#define RAMP_ANGLE_SLOPE	4

// PLL grid
#define PI_PLL_GRID_KP		6.0//12.0   //(FK)//378.20322732549531993962238252599//0.34  // Kp = sqrt(2*Ki/Vs) // alternativo 0.38
#define PI_PLL_GRID_KI		75.0//150.0 //(FK)//71518.840579710144927536231884058//38.3 // Ki =  wc^2/Vs		// alternativo 2.53
#define PI_PLL_GRID_KC		1.0	  // and wc = 25Hz e Vs = 645
#define PI_PLL_GRID_OUTMIN	-20.0//357.0 //(FK)-1000
#define PI_PLL_GRID_OUTMAX	20.0//397.0 //(FK)1000

// PLL del inversor
#define PI_PLL_GRID_KP_SLOW		10.0//378.20322732549531993962238252599// //0.34  // Kp = sqrt(2*Ki/Vs) // alternativo 0.38
#define PI_PLL_GRID_KI_SLOW		100.0//71518.840579710144927536231884058//  //38.3 // Ki =  wc^2/Vs		// alternativo 2.53
#define PI_PLL_GRID_KC_SLOW		1.0	 // and wc = 25Hz e Vs = 645
#define PI_PLL_GRID_OUTMAX_SLOW	(DOSPI*(FREQ_INV_NOM + 3.0)) //334.0
#define PI_PLL_GRID_OUTMIN_SLOW	(DOSPI*(FREQ_INV_NOM - 3.0))//295.0 //(FK)-1000

////////////////////////////////////////////////////
// PLL del bypass
#define PI_PLL_GRID_KP_FAST			378.20322732549531993962238252599//0.34  // Kp = sqrt(2*Ki/Vs) // alternativo 0.38
#define PI_PLL_GRID_KI_FAST			71518.840579710144927536231884058//38.3 // Ki =  wc^2/Vs		// alternativo 2.53
#define PI_PLL_GRID_KC_FAST			1.0	 // and wc = 25Hz e Vs = 645
#define PI_PLL_GRID_OUTMAX_FAST		DOSPI*(FREQ_INV_NOM + 3.0)//295.0 //(FK)-1000
#define PI_PLL_GRID_OUTMIN_FAST		DOSPI*(FREQ_INV_NOM - 3.0)//295.0 //(FK)-1000 
////////////////////////////////////////////////////

// Single Phase PLL grid
#define PI_SPLL_KP			6.0		// 160	//0.34	// Kp = sqrt(2*Ki/Vs)	// alternativo 0.38
#define PI_SPLL_KI			75.0	// 3600	//38.3	// Ki =  wc^2/Vs		// alternativo 2.53
#define PI_SPLL_KC			1.0		// and wc = 25Hz e Vs = 645
#define PI_SPLL_GRID_OUTMAX	20.0	// 1000
#define PI_SPLL_GRID_OUTMIN	-20.0	// -1000

// Other slopes definition
#define RAMP_QGRID_SLOPE  	1000

// CHOSE IF PLOT WILL BE COPILED
#define PLOT_GRAPH			0

//	Utilizar PLL hibrido
//#define HYBRID_PLL

//	Utilizar desenganche por frecuencia.
#define UNLOCK_PLL

// Tiempos del sistema
#define TB_PERIOD     1L                  // Periodo de la base de tiempo = 50us
#define T_05_MS       (10L * TB_PERIOD)   // Cuentas equivalentes a 1 milisegundo
#define T_1_MS        (20L * TB_PERIOD)   // Cuentas equivalentes a 1 milisegundo
#define T_FAST_FALL_  (40L * T_1_MS)      // Tiempo para el calculo de caida rapida

//==========================================================================
// No more.
//==========================================================================
#endif

