
#include "unity.h"

#include "DSP2833x_Device.h"

#include "InvKMT_structs.h"

#include "objects.h"
#include "TestDDSRFPLL.h"
#include "InvKMT_DDSRFPLL.h"

#include "data.h"

#include <stdio.h>

//============= Constants variables ===========//                          
const float Ts = TSAMPLE_GRID;                                             
const float Fs = FREQ_GRID_SAMPLE;                                         
const unsigned int N_MEDIOS = 3450;                                        

sParameters parameters = SYS_PARAMETERS_DEFAULTS;   
sDDSRFPLL2 Referencia = DDSRFPLL2_DEFAULTS;

 // Parámetros de configuración del sistema                                
 CONFIG config;                                                            
                                                                           
 // Variables del Sistema                                                  
 VARS vars;                                                                
 VARS_RATED vars_rated;                                                    

 //================= Constantes para los filtros ============//
const float coef_2000Hz[2]  = FILTER_COEF_2000HZ_20kHz;
const float coef_1000Hz[2]  = FILTER_COEF_1000HZ_20kHz;
const float coef_500Hz[2]   = FILTER_COEF_500HZ_20kHz;
const float coef_400Hz[2]   = FILTER_COEF_400HZ_20kHz;
const float coef_350Hz[2]   = FILTER_COEF_350HZ_20kHz;
const float coef_200Hz[2]   = FILTER_COEF_200HZ_20kHz;
const float coef_100Hz[2]   = FILTER_COEF_100HZ_20kHz;
const float coef_50Hz[2]    = FILTER_COEF_50HZ_20kHz;
const float coef_25Hz[2]    = FILTER_COEF_25HZ_20kHz;
const float coef_10Hz[2]    = FILTER_COEF_10HZ_20kHz;
const float coef_1Hz[2]     = FILTER_COEF_1HZ_20kHz;
const float coef_400_RAD_SEG[2] = FILTER_COEF_400_RAD_SEG_20kHz;
const float coef_800_RAD_SEG[2] = FILTER_COEF_800_RAD_SEG_20kHz;
//================= Fin Constantes para los filtros ============//

// Tipos de PLLs.                  
enum PLL_Type {                    
    PI_PLL    = 0,                 
    FAST_PLL  = 1,                 
};

enum PLL_Type PLL_type = PI_PLL;   

// DDSRFPLL internal variables
extern float omega;
extern float freq;
extern float vco;
extern float theta;
extern float sinth;
extern float costh;
extern float sin2th;
extern float cos2th;

void setUp(void)
{

    printf("SetUp text\n");
}

void tearDown(void)
{
    printf("tearDown text\n");
}

void test_ddsrfpll(void)
{

    for(int a = 0; a < 1; a++)
        for(int i = 0; i < LEN_Un; i++) 
        {
            // Acondiciona para que quede en pu y usar las mismas ganancias en los PLLs!
            Referencia.abc.a =  Ua[i];
            Referencia.abc.b =  Ub[i];
            Referencia.abc.c =  Uc[i]; 

            InvKMT_DDSRFPLL_Hybrid(&Referencia, PLL_type);
            printf("%f %f %f %f %f\n",Referencia.Qpf,Referencia.Dpf, Referencia.alfabeta.alfa, Referencia.alfabeta.beta, costh);

            if(vco > DOSPI){                          
                //StopCpuTimer0();                      
                vco = 0;                              
            }                                         
    }


TEST_ASSERT_TRUE(1);

}

int main(void)
{
 
 config.inv_ctrl_pll_kp = 6.00;
 config.inv_ctrl_pll_ki = 75.00;

UNITY_BEGIN();

RUN_TEST(test_ddsrfpll);

/*
for(int i = 0; i<1000; i++)
{
RUN_TEST(test_put_pop);

RUN_TEST(test_load_entire_buffer);
RUN_TEST(test_load_partial_buffer);
RUN_TEST(test_push_buffer);
}
RUN_TEST(test_circular_buffer_free);
//RUN_TEST(test_AverageThreeBytes_should_AverageHighValues);

*/

return UNITY_END();
}

//
// End of file.
//
