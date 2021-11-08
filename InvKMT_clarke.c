/* Clarke Transform
*	Description: Converts balanced three phase quantities into balanced 
*				 two phase quadrature quantities.
*				(a,b,c) -> (d,q) Transformation
*				clark_d = clark_a
*				clark_q = (2 * clark_b + clark_a) / sqrt(3)
*
*			 		 |~~~~~~~~~~~~~~~~~|
*	clark_a	 o------>|		   		   |----->o  clark_d
*	clark_b	 o------>|     CLARKE      |
*	clark_c* o------>|		   		   |----->o  clark_q
*			 		 |_________________|
*/

#include "InvKMT_clarke.h"

//#include "InvKMT_structs.h"
#include "InvKMT_parameters.h"
//#pragma CODE_SECTION(InvKMT_clarke, "ramfuncs");

void InvKMT_clarke(sABC *p_abc, sAlfaBeta *p_alfabeta) {
   p_alfabeta->alfa = p_abc->a;

   p_alfabeta->beta = (2 * p_abc->b + p_abc->a)* INV_RAIZ3;
}

// 
// End of file.
//
