#include <lpc214x.h>
#include "LPC2148_delay.h"
#include "LPC2148_LCD_4_BIT_HEADER_FILE.h"

int Count=0;

int main()
{
	PINSEL0 = 0x00000000;
	IODIR0 = 0x3F0;
	
	Lcd_Intialization();
	
	Lcd_Command(0x80);
	Lcd_String("LYCA SOFT");

	while(1)
	{
		Lcd_Command(0xC0);
		Lcd_Data(Count+48);
		delay(1000);

		Count++;

		if(Count >= 10)
		{
			Count = 0;
		}
	}
}