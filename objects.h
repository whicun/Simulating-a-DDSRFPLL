/*
 * InvKMT_objects.h
 *
 * Declaraciónes y definiciones utilizadas en el proyecto
 *
 *
 * Historico
 *
 * xx/xx/xx		creación
 *
 */

#define OBJ_CHAR	0		// Objeto entero de 8 bits
#define OBJ_U16		1		// Objeto entero de 16 bits con signo
#define OBJ_I16		2		// Objeto entero de 16 bits sin signo
#define OBJ_U32		3		// Objeto entero de 32 bits con signo
#define OBJ_I32		4		// Objeto entero de 32 bits sin signo
#define OBJ_FLOAT	5		// Objeto flotante
#define OBJ_BOOL	6		// Objeto boolean
#define OBJ_FECHA	7		// Objeto fecha dd/mm/aaaa
#define OBJ_HORA	8		// Objeto hora hh/mm
#define OBJ_STR		9		// Objeto string

#define FIN		0xFFFFFFFF	// Indica el fin de los arreglos "range"

//////////////////////////////////

//                   OID              Nro                    Descripcion
//            Hardware registers
#define  OID_HW_ID                    5000  // Hardeware ID
#define  OID_HW_TYPE                  5001  // Hardware Type
#define  OID_HW_FIRMWARE              5002  // Firmware
#define  OID_HW_RSV_3                 5003  // Reserved
#define  OID_HW_CRC_RAM               5004  // CRC RAM
#define  OID_HW_CRC_FLASH             5005  // CRC Flash

//                   DIO
#define  OID_DI_GROUP_01              5100  // Digital Inputs group 1
#define  OID_D0_GROUP_01              5101  // Digital Outputs group 1

//                  STATUS
#define  OID_STATUS_1                 5200  // System status 1
#define  OID_STATUS_2                 5201  // System status 2
#define  OID_STATUS_3                 5202  // System status 3

//                  Alarms
#define  OID_ALARM_1                  5300  // System alarms 1
#define  OID_ALARM_2                  5301  // System alarms 2
#define  OID_ALARM_3                  5302  // System alarms 3

//             INV measurements
#define  OID_INV_RMS_VOLTAGE_RS       5400  // INV RMS line voltage
#define  OID_INV_RMS_VOLTAGE_ST       5401  // INV RMS line voltage
#define  OID_INV_RMS_VOLTAGE_TR       5402  // INV RMS LINE voltage
#define  OID_INV_RMS_VOLTAGE_R        5403  // INV RMS phase voltage
#define  OID_INV_RMS_VOLTAGE_S        5404  // INV RMS phase voltage
#define  OID_INV_RMS_VOLTAGE_T        5405  // INV RMS phase voltage
#define  OID_BP_RMS_VOLTAGE_RS        5406  // BP RMS line voltage
#define  OID_BP_RMS_VOLTAGE_ST        5407  // BP RMS line voltage
#define  OID_BP_RMS_VOLTAGE_TR        5408  // V RMS line voltage
#define  OID_BP_RMS_VOLTAGE_R         5409  // BP RMS phase voltage
#define  OID_BP_RMS_VOLTAGE_S         5410  // BP phase voltage
#define  OID_BP_RMS_VOLTAGE_T         5411  // BP phase voltage
#define  OID_INV_RMS_CURRENT_R        5412  // INV RMS phase current
#define  OID_INV_RMS_CURRENT_S        5413  // INV RMS phase current
#define  OID_INV_RMS_CURRENT_T        5414  // INV RMS phase current
#define  OID_OUT_RMS_CURRENT_R        5415  // OUT RMS phase current
#define  OID_OUT_RMS_CURRENT_S        5416  // OUT RMS phase current
#define  OID_OUT_RMS_CURRENT_T        5417  // OUT RMS phase current
#define  OID_INV_VOLTAGE_DC           5418  // DC link voltage
#define  OID_INV_CURRENT_DC           5419  // DC link current
#define  OID_OUT_P                    5420  // Active power
#define  OID_OUT_Q                    5421  // Reactive power
#define  OID_OUT_PF                   5422  // Power Factor
#define  OID_OUT_ENERGY               5423  // Energy
#define  OID_INV_FREQ                 5424  // Frequency

//            System Parameters
#define  OID_INV_BASE_P               5500  // INV rated power
#define  OID_INV_BASE_V               5501  // INV rated voltage
#define  OID_INV_BASE_I               5502  // INV rated current
#define  OID_INV_BASE_FREQ            5503  // INV rated freq
#define  OID_OUT_BASE_V               5504  // OUT rated voltge
#define  OID_OUT_BASE_I               5505  // OUT rated current
#define  OID_BASE_VDC                 5506  // DC rated voltage
#define  OID_BASE_GAIN_VRS_BP         5507  // Gain bypass voltage meas RS
#define  OID_BASE_GAIN_VST_BP         5508  // Gain bypass voltage meas ST
#define  OID_BASE_GAIN_VTR_INV        5509  // Gain INV voltage meas RS
#define  OID_BASE_GAIN_VRS_INV        5510  // Gain INV voltage meas ST
#define  OID_BASE_GAIN_IR_INV         5511  // Gain INV current meas R
#define  OID_BASE_GAIN_IS_INV         5512  // Gain INV current meas S
#define  OID_BASE_GAIN_IR_OUT         5513  // Gain OUT current meas R
#define  OID_BASE_GAIN_IS_OUT         5514  // Gain OUT current meas S
#define  OID_BASE_GAIN_IT_OUT         5515  // Gain OUT current meas T
#define  OID_BASE_GAIN_VDC            5516  // Gain VDC
#define  OID_BASE_GAIN_ICC            5517  // Gain ICC U
#define  OID_BASE_OFFSET_VRS_BP       5518  // OFFSET bypass voltage meas RS
#define  OID_BASE_OFFSET_VST_BP       5519  // OFFSET bypass voltage meas ST
#define  OID_BASE_OFFSET_VTR_INV      5520  // OFFSET INV voltage meas RS
#define  OID_BASE_OFFSET_VRS_INV      5521  // OFFSET INV voltage meas ST
#define  OID_BASE_OFFSET_IR_INV       5522  // OFFSET INV current meas R
#define  OID_BASE_OFFSET_IS_INV       5523  // OFFSET INV current meas S
#define  OID_BASE_OFFSET_IR_OUT       5524  // OFFSET OUT current meas R
#define  OID_BASE_OFFSET_IS_OUT       5525  // OFFSET OUT current meas S
#define  OID_BASE_OFFSET_IT_OUT       5526  // OFFSET OUT current meas T
#define  OID_BASE_OFFSET_VDC          5527  // OFFSET VDC
#define  OID_BASE_OFFSET_ICC          5528  // OFFSET ICC
#define  OID_BASE_TRAFO_RATIO         5529  // TRAFO RATIO
#define  OID_BASE_SR_FREQ             5530  // Slew rate freq
#define  OID_T_DEAD                   5531  // Dead band time
#define  OID_T_ON                     5532  // IGBT on time
#define  OID_T_OFF                    5533  // IGBT off time
#define  OID_V_SAT                    5534  // IGBT saturation voltage
#define  OID_VD                       5535  // Diode forward voltage
#define  OID_PHASE_ADJUST             5536  // Reserved
#define  OID_EQUIPO		              5537  // Reserved
#define  OID_EQUIPO_HMI               5538  // Reserved

//       INV side controller parameters
#define  OID_CTRL_VINV_KP             5600  // INV Voltage Controller Proportional gain
#define  OID_CTRL_VINV_KI             5601  // INV Voltage Controller Integral gain
#define  OID_CTRL_VINV_REFSLOPE       5602  // Vinv Setpoint Ramp Slope
#define  OID_CTRL_VINV_SETPOINT       5603  // Vinv Controller Setpoint
#define	 OID_CTRL_IINV_KP			  5604	//	INV Current Controller Proportional gain
#define	 OID_CTRL_IINV_KI	          5605	//	INV Current Controller Integral gain
#define	 OID_INV_CTRL_PLL_KP		  5606	//	INV Current Controller Proportional gain
#define	 OID_INV_CTRL_PLL_KI          5607	//	INV Current Controller Integral gain
#define	 OID_INV_CTRL_ANGLE_SLOPE	  5608	//	INV angle slope tracking
#define	 OID_INV_CTRL_SINC_RANGE	  5609	//	INV sincronization range
#define	 OID_CTRL_HINV_KP			  5610	//	INV Harmonic Controller Proportional gain
#define	 OID_CTRL_HINV_KI			  5611	//	INV Harmonic Controller Integral gain
#define	 OID_INV_CTRL_ALARM			  5612	//	Alarm Control
#define	 OID_INV_CTRL_CONFIG		  5613	//	Configuration control

//	Protection parameters			
#define	OID_IGBT_SAT_TIME				5700	//	IGBT saturation time
#define	OID_LOW_VCC_LEVEL				5701	//	Low VCC level
#define	OID_LOW_VCC_TIME				5702	//	Low VCC time
#define	OID_LOW_VCC_HYST				5703	//	Low VCC Hysteresis
#define	OID_HIGH_VCC_LEVEL				5704	//	High VCC level
#define	OID_HIGH_VCC_TIME				5705	//	High VCC time
#define	OID_HIGH_VCC_HYST				5706	//	High VCC Hysteresis
#define	OID_BATT_BRK_OPENED_TIME		5707	//	Battery breaker opened time
#define	OID_OVER_TMP_PROT_TIME			5708	//	Overtemp portection time
#define	OID_VENT_FAILURE_TIME			5709	//	Fan Failure time
#define	OID_GRID_CTRL_SAT_TIME			5710	//	Grid control saturation time
#define	OID_OVR_LOAD_MIN				5711	//	Overload during one minute
#define	OID_OVR_LOAD_10MIN				5712	//	Overload during ten minutes
#define	OID_OVR_LOAD_HOLD				5713	//	Overl load hold
#define	OID_VERY_LOW_VCC_LEVEL			5714	//	Very low Vcc Level
#define	OID_VERY_LOW_VCC_TIME			5715	//	Very low Vcc Time
#define	OID_OUTPUT_FUS_OPND_TIME		5716	//	Output fusible opened time
#define	OID_INPUT_FUS_OPND_TIME			5717	//	Input fusible opened time
#define	OID_PWR_SUPPLY_FAIL_TIME		5718	//	Power Supply Failure Time
#define	OID_DYNAMIC_LIMIT				5719	//	Limite Dinamico
#define	OID_BASE_GAIN_VST_INV			5720	//	Reserved
#define	OID_BASE_GAIN_IT_INV			5721	//	Reserved
#define	OID_INV_PROT_RSV_9				5722	//	Reserved

//	Command registers			
#define	OID_COMMAND_CODE	5900	//	Command code
#define	OID_COMMAND_ONOFF	5901	//	On Off command
#define	OID_COMMAND_RSV_1	5902	//	Reserved
#define	OID_COMMAND_RSV_2	5903	//	Reserved
#define	OID_COMMAND_RSV_3	5904	//	Reserved
#define	OID_COMMAND_RSV_4	5905	//	Reserved

//	Test variables			
#define	OID_TEST_PWM_CMP1	6000	//	PWM test comparator 1
#define	OID_TEST_PWM_CMP2	6001	//	PWM test comparator 2
#define	OID_TEST_PWM_CMP3	6002	//	PWM test comparator 3
#define	OID_TEST_PWM_CMP4	6003	//	PWM test comparator 4
#define	OID_TEST_DO			6004	//	Test digital output

//      Estructura config
typedef struct {
	Uint16  hw_id                  ;  // Hardeware ID
	Uint16  hw_type                ;  // Hardware Type
	Uint16  hw_firmware            ;  // Firmware
	Uint16  hw_rsv_3               ;  // Reserved
	Uint16  hw_crc_ram             ;  // CRC RAM
	Uint16  hw_crc_flash           ;  // CRC Flash
	float   base_gain_vrs_bp       ;  // Gain bypass voltage meas RS
	float   base_gain_vst_bp       ;  // Gain bypass voltage meas ST
	float   base_gain_vtr_inv      ;  // Gain INV voltage meas RS
	float   base_gain_vrs_inv      ;  // Gain INV voltage meas ST
	float   base_gain_ir_inv       ;  // Gain INV current meas R
	float   base_gain_is_inv       ;  // Gain INV current meas S
	float   base_gain_ir_out       ;  // Gain OUT current meas R
	float   base_gain_is_out       ;  // Gain OUT current meas S
	float   base_gain_it_out       ;  // Gain OUT current meas T
	float   base_gain_vdc          ;  // Gain VDC
	float   base_gain_icc          ;  // Gain ICC U
	float   base_offset_vrs_bp     ;  // OFFSET bypass voltage meas RS
	float   base_offset_vst_bp     ;  // OFFSET bypass voltage meas ST
	float   base_offset_vtr_inv    ;  // OFFSET INV voltage meas RS
	float   base_offset_vrs_inv    ;  // OFFSET INV voltage meas ST
	float   base_offset_ir_inv     ;  // OFFSET INV current meas R
	float   base_offset_is_inv     ;  // OFFSET INV current meas S
	float   base_offset_ir_out     ;  // OFFSET OUT current meas R
	float   base_offset_is_out     ;  // OFFSET OUT current meas S
	float   base_offset_it_out     ;  // OFFSET OUT current meas T
	float   base_offset_vdc        ;  // OFFSET VDC
	float   base_offset_icc        ;  // OFFSET ICC
	float   base_trafo_ratio       ;  // TRAFO RATIO
	float   base_sr_freq           ;  // Slew rate freq
	float   base_t_dead            ;  // Dead band time
	float   base_t_on              ;  // IGBT on time
	float   base_t_off             ;  // IGBT off time
	float   base_v_sat             ;  // IGBT saturation voltage
	float   base_vd                ;  // Diode forward voltage
	float   phase_adjust           ;  // Reserved
	float   equipo	               ;  // Reserved
	float   equipo_hmi             ;  // Reserved
	float   ctrl_vinv_kp           ;  // INV Voltage Controller Proportional gain
	float   ctrl_vinv_ki           ;  // INV Voltage Controller Integral gain
	float   ctrl_vinv_refslope     ;  // Vdc Setpoint Ramp Slope
	float   ctrl_vinv_setpoint     ;  // Vdc Controller Setpoint
	float   ctrl_iinv_kp           ;  // INV Current Controller Proportional gain
	float   ctrl_iinv_ki           ;  // INV Current Controller Integral gain
	float   inv_ctrl_pll_kp        ;  // INV PLL Controller Proportional gain
	float   inv_ctrl_pll_ki        ;  // INV PLL Controller integral gain
	float   inv_ctrl_angle_slope   ;  // INV angle slope tracking
	float   inv_ctrl_sinc_range    ;  // INV sincronization range
	float   inv_ctrl_hinv_kp       ;  // INV Harmonic Controller Proportional gain
	float   inv_ctrl_hinv_ki       ;  // INV Harmonic Controller Integral gain
	Uint16  inv_ctrl_alarm         ;  // Alarm Control
	Uint16  inv_ctrl_config        ;  // Configuration control
	float   igbt_sat_time          ;  // IGBT saturation time
	float   low_vcc_level          ;  // Low VCC level
	float   low_vcc_time           ;  // Low VCC time
	float   low_vcc_hyst           ;  // Low VCC Hysteresis
	float   high_vcc_level         ;  // High VCC level
	float   high_vcc_time          ;  // High VCC time
	float   high_vcc_hyst          ;  // High VCC Hysteresis
	float   batt_brk_opened_time   ;  // Battery breaker opened time
	float   over_tmp_prot_time     ;  // Overtemp portection time
	float   vent_failure_time      ;  // Fan Failure time
	float   grid_ctrl_sat_time     ;  // Grid control saturation time
	float   ovr_load_min           ;  // Overload during one minute
	float   ovr_load_10min         ;  // Overload during ten minutes
	float   ovr_load_hold          ;  // Overl load hold
	float   very_low_vcc_level     ;  // Very low Vcc Level
	float   very_low_vcc_time      ;  // Very low Vcc Time
	float   outfus_opnd_time       ;  // Output fusible opened time
	float   infus_opnd_time        ;  // Input fusible opened time
	float   pwrsupply_fail_time    ;  // Power Supply Failure Time
	float   dynamic_limit          ;  // Limite dinamico
	float   base_gain_vst_inv      ;  // Reserved
	float   base_gain_it_inv       ;  // Reserved
	float   inv_prot_rsv_9         ;  // Reserved
} CONFIG;

//      Estructura vars
typedef struct {
	Uint16  di_group_01            ;  // Digital Inputs group 1
	Uint16  d0_group_01            ;  // Digital Outputs group 1
	Uint16  status_1               ;  // System status 1
	Uint16  status_2               ;  // System status 2
	Uint16  status_3               ;  // System status 3
	Uint16  alarm_1                ;  // System alarms 1
	Uint16  alarm_2                ;  // System alarms 2
	Uint16  alarm_3                ;  // System alarms 3
	float   inv_rms_voltage_rs     ;  // INV RMS line voltage
	float   inv_rms_voltage_st     ;  // INV RMS line voltage
	float   inv_rms_voltage_tr     ;  // INV RMS LINE voltage
	float   inv_rms_voltage_r      ;  // INV RMS phase voltage
	float   inv_rms_voltage_s      ;  // INV RMS phase voltage
	float   inv_rms_voltage_t      ;  // INV RMS phase voltage
	float   bp_rms_voltage_rs      ;  // BP RMS line voltage
	float   bp_rms_voltage_st      ;  // BP RMS line voltage
	float   bp_rms_voltage_tr      ;  // V RMS line voltage
	float   bp_rms_voltage_r       ;  // BP RMS phase voltage
	float   bp_rms_voltage_s       ;  // BP phase voltage
	float   bp_rms_voltage_t       ;  // BP phase voltage
	float   inv_rms_current_r      ;  // INV RMS phase current
	float   inv_rms_current_s      ;  // INV RMS phase current
	float   inv_rms_current_t      ;  // INV RMS phase current
	float   out_rms_current_r      ;  // OUT RMS phase current
	float   out_rms_current_s      ;  // OUT RMS phase current
	float   out_rms_current_t      ;  // OUT RMS phase current
	float   inv_voltage_dc         ;  // DC link voltage
	float   inv_current_dc         ;  // DC link current
	float   out_p                  ;  // Active power
	float   out_q                  ;  // Reactive power
	float   out_pf                 ;  // Power Factor
	float   out_energy             ;  // Energy
	float   inv_freq               ;  // Frequency
	float   inv_base_p             ;  // INV rated power
	float   inv_base_v             ;  // INV rated voltage
	float   inv_base_i             ;  // INV rated current
	float   inv_base_freq          ;  // INV rated freq
	float   out_base_v             ;  // OUT rated voltge
	float   out_base_i             ;  // OUT rated current
	float   base_vdc               ;  // DC rated voltage
	Uint16  command_code           ;  // Command code
	Uint16  command_onoff          ;  // On Off command
	Uint16  command_rsv_2          ;  // Reserved
	Uint16  command_rsv_3          ;  // Reserved
	Uint16  command_rsv_4          ;  // Reserved
	Uint16  test_pwm_cmp1          ;  // PWM test comparator 1
	Uint16  test_pwm_cmp2          ;  // PWM test comparator 2
	Uint16  test_pwm_cmp3          ;  // PWM test comparator 3
	Uint16  test_pwm_cmp4          ;  // PWM test comparator 4
	Uint16  test_do                ;  // Test digital output
} VARS;

typedef struct {
	float   out_pf                 ;  // Power Factor
	float   inv_base_p             ;  // INV rated power
	float   inv_base_v             ;  // INV rated voltage
	float   inv_base_i             ;  // INV rated current
	float   inv_base_freq          ;  // INV rated freq
	float   out_base_v             ;  // OUT rated voltge
	float   out_base_i             ;  // OUT rated current
	float   base_vdc               ;  // DC rated voltage
} VARS_RATED;


// Parámetros de configuración del sistema
extern CONFIG config;

// Variables del Sistema
extern VARS vars;

extern VARS_RATED vars_rated; //(COMPLETAR) SOLUCIONAR ESTO!!! Las variables de vars_rated deberian ir en la estructura config


