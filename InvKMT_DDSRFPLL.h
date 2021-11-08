/*
 * This file dont exist on the original project
 */

#ifndef __INVKMT_DDSRFPLL_H__
#define __INVKMT_DDSRFPLL_H__

#include "DSP2833x_Device.h"

#include "InvKMT_parameters.h"

#include "InvKMT_clarke.h"
#include "InvKMT_park.h"
#include "InvKMT_PIfunc2.h"

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
    sABC        abc;                                                                           
    sAlfaBeta   alfabeta;                                                                      
    sDQ         dq;                                                                            
    float       Dpos;                                                                          
    float       Qpos;                                                                          
    float       Dneg;                                                                          
    float       Qneg;                                                                          
    float       Dp;                                                                            
    float       Qp;                                                                            
    float       Dn;                                                                            
    float       Qn;                                                                            
    float       Dpf;                                                                           
    float       Qpf;                                                                           
    float       Dnf;                                                                           
    float       Qnf;                                                                           
    float       Dp_1;                                                                          
    float       Qp_1;                                                                          
    float       Dn_1;                                                                          
    float       Qn_1;                                                                          
} sDDSRFPLL2;                                                                                  
                                                                                               
#define DDSRFPLL2_DEFAULTS {\                                                                  
            ABC_DEFAULTS,ALFABETA_DEFAULTS,DQ_DEFAULTS,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}                                                                                                     


 void InvKMT_DDSRFPLL(sDDSRFPLL2 *, sDDSRFPLL2 *);                                
 void InvKMT_Transform_and_Decoupling(sDDSRFPLL2 *c);                             
                                                                                  
 void InvKMT_DDSRFPLL_Hybrid(sDDSRFPLL2 *, Uint16);                               
 void InvKMT_Transform_and_Decoupling_Hybrid(sDDSRFPLL2 *);                       
                                                                                  
 void InvKMT_DDSRFPLL_ANALYSE(sDDSRFPLL *, Uint16 * );                            
#endif
