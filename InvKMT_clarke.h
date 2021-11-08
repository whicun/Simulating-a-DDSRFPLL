
#ifndef __CLARKE_H__
#define __CLARKE_H__

typedef struct{
        float a;
        float b;
        float c;
} sABC;

#define ABC_DEFAULTS {\                                
                        0,0,0}                         
                                                       
typedef struct{                         
        float alfa;                     
        float beta;                     
                                        
} sAlfaBeta;                            
                                        
#define ALFABETA_DEFAULTS {\            
                        0,0}            

void InvKMT_clarke(sABC *p_abc, sAlfaBeta *p_alfabeta);

#endif

// 
// End of file.
//
