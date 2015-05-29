#ifndef SCI_H
#define SCI_H


#define EMPTY   0
#define FULL    1


void Sci_Init(void);



void Sci1_Putchar(char ch); 

char Sci1_Gechar(void);

char Sci1_RxStatus(void);  

char Sci1_GetQueueSatus(void);

char Sci1_GetQueueData(void);






void TERMIO_PutChar(char ch);

char TERMIO_GetChar(void);

#endif