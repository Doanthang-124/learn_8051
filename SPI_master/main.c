#include <REGX51.H>

#define SPI_SCK  P2_0
#define SPI_MOSI P2_1
#define SPI_MISO P2_2
#define SPI_SS   P2_3

void SPI_Init()
{
   SPI_SCK  = 0;
   SPI_MISO = 1;
   SPI_SS = 1;
}

void SPI_Write_Byte(unsigned char b)
{
	unsigned char i;
	for(i = 0; i < 8; i++)
	 {
		
		 if(b&0x80 != 0)
		 {
			SPI_MOSI = 1;
		 }
		 else
		 {
		 	SPI_MISO = 0;
		 }
		 SPI_SCK = 1;
		 SPI_SCK = 0;
		 b <<= 1;
	 }
}
unsigned char SPI_Read()
{
	unsigned char i,b;

	for( i = 0 ; i < 8 ; i++)
	{	   
		b <<= 1;
		SPI_SCK = 1;
		if(SPI_MISO)
		 b |=0x01;
		SPI_SCK = 0;
	}
	return b;
}
void main()
{
	SPI_Init();
	SPI_SS = 0;
	SPI_Write_Byte(0x00);
	SPI_SS = 1;
 	while(1)
	{
			
	}
}