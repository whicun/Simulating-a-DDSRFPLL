/*
 * This file dont exist on the projects
 */

#ifndef __INVKMT_PIFUNC2_H__
#define __INVKMT_PIFUNC2_H__

#include "InvKMT_PIfunc2_defines.h"

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

Uint16 InvKMT_Pifunc2(sPI *reg);

#endif

// 
// End of file.
//
