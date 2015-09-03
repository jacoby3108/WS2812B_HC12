#ifndef RTI_H
#define RTI_H


void delayms(unsigned int dly);
void rti_init(void);

void rti_stop(void);

void rti_start(void); 

void Set_Timer_ms(unsigned int dly);
unsigned char Get_Timer_ms_Status(void);



void   Set_Party_Mode_On(void);
void   Set_Party_Mode_Off(void);




#endif