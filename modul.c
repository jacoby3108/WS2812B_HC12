#include <stdio.h>

int i,j;



unsigned char data[8][9]={{'T',' ','f','t','h'},
						  {'h','n','o',' ','e'},	
						  {'e','w','x','r',' '},
						  {' ','o',' ','e','l'},	
						  {'q','r','j','v','a'},	
						  {'u','b','u','o','z','g'},
						  {'i',' ','m',' ','y','o'},	
						  {'c','k','p','s',' ','d'}};
						  
						  
unsigned char RowIndex[]={0,1,2,3,4,5,6,7,7,6,5,4,3,2,1,0};
unsigned char ColUpdat[]={0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1};
unsigned char col=0;	

void main(void)
  
{


	printf(" --- %d\n",sizeof(RowIndex)/sizeof(RowIndex[0]));

	i=0;
	for(j=0;j<44;j++){
	
			//printf("R= %d C= %d\n",RowIndex[i],col);		 
			putchar(data[RowIndex[i]][col]);
			
			col+=ColUpdat[i++];		// Update colum
			i&=0x0F;				// modulo arithmetic
	}

	printf("\n\n");
}  
