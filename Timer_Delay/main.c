#include <REGX51.H>

void Delay_ms(unsigned int i)
{

	TMOD &= 0xF0;  // chon timer 0
	TMOD |= 0x01;
    do{
			TH0 = 0xFC;		// 2^16 - 1000
			TL0 = 0x18;
			TR0 = 1;	  // cho phep dem xung
		   	while(TF0 == 0); // doi co tran len 1
			TF0 = 0;  // xoa co tran
			TR0 = 0;
		i--;
	  }while(i!=0);

}
void main()
{

	P2_0 = 0;
 	while(1)
	{
	P2_0 = !P2_0;
	Delay_ms(1000);	
	}
}
