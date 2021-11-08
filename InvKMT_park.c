/*===========================================================================
; Module Name: 	PARK					      
;
; Description:
;
;			id = ialfa * cos_teta + ibeta * sin_teta
;			iq = -ialfa *sin_teta + ibeta * cos_teta
;
;					|~~~~~~~~~~~~~~~~~|
;	park_d	o------>|		  		  |----->o  park_D
;	park_q	o------>|      PARK	  	  |
;	sin 	o------>|		  		  |----->o  park_Q
;	cos		o------>|_________________|
;
;	Note:	0 < theta_p < 7FFFh   (i.e. equivalent to   0 < theta_p < 360 deg  )
;=============================================================================*/
#include <math.h>
#include "InvKMT_park.h"

//#include "InvKMT_control_function_prototypes.h"// declaración de las funciones
#include "InvKMT_parameters.h"

#pragma CODE_SECTION(InvKMT_park, "ramfuncs");

void InvKMT_park(sAlfaBeta *p_alfabeta, sDQ* p_DQ)
{
	p_DQ->d = (p_alfabeta->alfa* p_DQ->cos + p_alfabeta->beta* p_DQ->sin);
	p_DQ->q = (p_alfabeta->beta* p_DQ->cos - p_alfabeta->alfa* p_DQ->sin);
}

// 
// End of file.
//
