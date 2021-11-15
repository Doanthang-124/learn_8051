#include <REGX51.H>

unsigned int dem = 40000;

void main()
{
 TMOD = 0x20;
 TH1 = 6;
 TL1 = 6;
 TR1 = 1;
 while(1)
 {
 	if(TF1==1)
	{
	 TF1=0;
	 dem ++;
		 if(dem == 0)
		   {
			P2_1=!P2_1;
			dem = 40000;	
		   }
	}
 }
}

