#ifndef SCI_H
#define SCI_H


#define EMPTY   0
#define FULL    1

// http://www.ascii-codes.com/

#define ENQ   0x05
#define ACK   0x06
#define STX   0x02
#define ETX   0x03
#define XON   0x11
#define XOFF  0x13
#define EOT   0x04



void Sci_Init(void);

// SCI1 HC05 Bluetooth

void Sci1_Putchar(unsigned char ch);    
                                            
unsigned char Sci1_Gechar(void);

unsigned char new_messages(void);

unsigned char messages_count(void);

void Reset_FSM(void);

void sendsci(unsigned char);


// SCI0 HC12 Serial Port


void TERMIO_PutChar(char ch);

char TERMIO_GetChar(void);

#endif