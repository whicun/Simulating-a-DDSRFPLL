
#ifndef __PARK_H__
#define __PARK_H__

#include "InvKMT_clarke.h"

typedef struct{
        float d;
        float q;
        float sin;
        float cos;
} sDQ;

#define DQ_DEFAULTS {\
                        0,0,0,0}

void InvKMT_park(sAlfaBeta *p_alfabeta, sDQ* p_DQ);

#endif

// 
// End of file.
//
