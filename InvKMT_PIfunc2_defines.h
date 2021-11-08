
#ifndef __KMTINV_PIFUNC2_DEFINES_H__
#define __KMTINV_PIFUNC2_DEFINES_H__

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
                                                                                                                       
#endif

//
// End of file.
//
