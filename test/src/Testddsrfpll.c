
#include "unity.h"

#include "DSP2833x_Device.h"

#include "InvKMT_structs.h"

#include "objects.h"
#include "TestDDSRFPLL.h"
#include "InvKMT_DDSRFPLL.h"

//============= Constants variables ===========//                          
const float Ts = TSAMPLE_GRID;                                             
const float Fs = FREQ_GRID_SAMPLE;                                         
const unsigned int N_MEDIOS = 3450;                                        

sParameters parameters = SYS_PARAMETERS_DEFAULTS;   

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


void setUp(void)
{
}

void tearDown(void)
{
}

/*
 * AS EXAMPLE... 
 
char array[ARRAY_LEN];
circular_buffer_handler cbh;

char texto[ARRAY_LEN];
void test_circular_buffer_initialization(void)
{

TEST_ASSERT_NOT_NULL_MESSAGE((cbh = circular_buffer_init((uint8_t *)array, ARRAY_LEN)),"cbh == NULL" );
TEST_ASSERT_EQUAL_UINT16_MESSAGE(ARRAY_LEN, circular_buffer_size(cbh), "Wrong buffer size");
}

void test_load_entire_buffer(void)
{
    char aux[ARRAY_LEN];

    for(int i = 0; i<ARRAY_LEN-1 ; i++)
	TEST_ASSERT_EQUAL_INT8_MESSAGE(0, circular_buffer_put(cbh, texto[i]),"No more space");

    TEST_ASSERT_EQUAL_UINT16_MESSAGE(ARRAY_LEN-1, circular_buffer_count(cbh), "Wrong length");
    TEST_ASSERT_EQUAL_INT8_MESSAGE(0, circular_buffer_drop(cbh, aux, ARRAY_LEN-1), "couldent dump");
    TEST_ASSERT_EQUAL_UINT16_MESSAGE(0, circular_buffer_count(cbh), "Wrong buffer size");
    TEST_ASSERT_UINT8_ARRAY_WITHIN_MESSAGE(0, texto, aux, ARRAY_LEN-1, aux);

}

void test_load_partial_buffer(void)
{
    char aux[ARRAY_LEN];

    for (int a = 1; a < ARRAY_LEN; a++)
    {
	for(int i = 0; i < a ; i++)
	    TEST_ASSERT_EQUAL_INT8_MESSAGE(0, circular_buffer_put(cbh, texto[i]),"No more space");

	TEST_ASSERT_EQUAL_UINT16_MESSAGE(a, circular_buffer_count(cbh), "Wrong length");
	TEST_ASSERT_EQUAL_INT8_MESSAGE(0, circular_buffer_drop(cbh, aux, a), "couldent dump");
	TEST_ASSERT_EQUAL_UINT16_MESSAGE(0, circular_buffer_count(cbh), "Wrong buffer size");
	TEST_ASSERT_UINT8_ARRAY_WITHIN_MESSAGE(0, texto, aux, a, aux);
    }

}

void test_push_buffer(void)
{
    char aux[ARRAY_LEN];

    while(0 == circular_buffer_put(cbh, 'a'))
    {;}

    for(int i = 0; i < ARRAY_LEN-1; i++)
	circular_buffer_push(cbh, texto[i]);


    TEST_ASSERT_EQUAL_INT8_MESSAGE(0, circular_buffer_drop(cbh, aux, ARRAY_LEN -1 ), "couldent dump");
    TEST_ASSERT_EQUAL_UINT16_MESSAGE(0, circular_buffer_count(cbh), "Wrong buffer size");
    TEST_ASSERT_UINT8_ARRAY_WITHIN_MESSAGE(0, texto, aux, ARRAY_LEN-1, aux);
}

void test_put_pop(void)
{
    char aux;

    circular_buffer_reset(cbh);
    for(int a = 0; a < 100 ; a++)
    {
	for(int i = 0; i < ARRAY_LEN; i++)
	{
	    TEST_ASSERT_EQUAL_INT8_MESSAGE(0, circular_buffer_put(cbh, texto[i]),"No more space");
	    TEST_ASSERT_EQUAL_INT8_MESSAGE(0, circular_buffer_pop(cbh, (uint8_t *) &aux), "pop");
	    TEST_ASSERT_EQUAL_CHAR_MESSAGE(texto[i],aux,"asd");

	}
    }
}

void test_circular_buffer_free(void)
{
TEST_ASSERT_NULL_MESSAGE(circular_buffer_free(&cbh), "cbh != NULL" );
}

*/

int main(void)
{

UNITY_BEGIN();

/*
RUN_TEST(test_circular_buffer_initialization);
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
