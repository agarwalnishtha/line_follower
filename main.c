#include <avr/io.h>
#include <avr/sfr_defs.h>
#define S bit_is_set
#define F bit_is_clear
// (1,0) is forward
// (0,1) is reverse
// (1,1) and (0,0) is halt

int main()
{
	DDRA = 0b00000000;
	DDRB = 0b00001111; //Setting first four pins to Output
	int left=0,right=0;
	while (1)
	{
		if (F(PINA,1)&&F(PINA,2)&&S(PINA,3)&&S(PINA,4)&&F(PINA,5)&&F(PINA,6))
		{
			PORTB = 0b00000101; //straight
			left=0;
			right=0;
		}
		else if (F(PINA,1)&&S(PINA,2)&&S(PINA,3)&&S(PINA,4)&&F(PINA,5)&&F(PINA,6))
		{
			PORTB = 0b00000101; //straight
			left=0;
			right=0;
		}
		else if (F(PINA,1)&&F(PINA,2)&&S(PINA,3)&&S(PINA,4)&&S(PINA,5)&&F(PINA,6))
		{
			PORTB = 0b00000101; //straight
			left=0;
			right=0;
		}
		else if (F(PINA,1)&&S(PINA,2)&&S(PINA,3)&&F(PINA,4)&&F(PINA,5)&&F(PINA,6))
		{
			PORTB = 0b00000001; //left
			left=1;
			right=0;
		}
		else if (S(PINA,1)&&S(PINA,2)&&S(PINA,3)&&F(PINA,4)&&F(PINA,5)&&F(PINA,6))
		{
			PORTB = 0b00000001; //left
			left=1;
			right=0;
		}
		else if (F(PINA,1)&&F(PINA,2)&&F(PINA,3)&&S(PINA,4)&&S(PINA,5)&&F(PINA,6))
		{
			PORTB = 0b00000100; //right
			left=0;
			right=1;
		}
		else if (F(PINA,1)&&F(PINA,2)&&F(PINA,3)&&S(PINA,4)&&S(PINA,5)&&S(PINA,6))
		{
			PORTB = 0b00000100;
			left=0;
			right=1; //right
		}
		else if (F(PINA,1)&&F(PINA,2)&&F(PINA,3)&&F(PINA,4)&&S(PINA,5)&&S(PINA,6))
		{
			PORTB = 0b00000110; // sharp right
			left=0;
			right=1;
		}
		else if (F(PINA,1)&&F(PINA,2)&&F(PINA,3)&&F(PINA,4)&&F(PINA,5)&&S(PINA,6))
		{
			PORTB = 0b00000110; //sharp right
			left=0;
			right=1;
		}
		else if(S(PINA,1)&&S(PINA,2)&&S(PINA,3)&&S(PINA,4)&&S(PINA,5)&&F(PINA,6))
		{
			PORTB = 0b00001001; //sharp left
			left = 1;
			right = 0;
			
		}
		else if(F(PINA,1)&&S(PINA,2)&&S(PINA,3)&&S(PINA,4)&&S(PINA,5)&&S(PINA,6))
		{
			PORTB = 0b00000110; //sharp right
			left = 0;
			right = 1;
			
		}
		else if (S(PINA,1)&&S(PINA,2)&&F(PINA,3)&&F(PINA,4)&&F(PINA,5)&&F(PINA,6))
		{
			PORTB = 0b00001001; //sharp left
			left=1;
			right=0;
		}
		else if (S(PINA,1)&&F(PINA,2)&&F(PINA,3)&&F(PINA,4)&&F(PINA,5)&&F(PINA,6))
		{
			PORTB = 0b00001001; //sharp left
			left=1;
			right=0;
		}
		else if (S(PINA,1)&&S(PINA,2)&&S(PINA,3)&&S(PINA,4)&&F(PINA,5)&&F(PINA,6))
		{
			PORTB = 0b00000001; // left
			left=1;
			right=0;
		}
		else if (F(PINA,1)&&F(PINA,2)&&S(PINA,3)&&S(PINA,4)&&S(PINA,5)&&S(PINA,6))
		{
			PORTB = 0b00000100; // right
			left=0;
			right=1;
		}
		else if (S(PINA,1)&&S(PINA,2)&&S(PINA,3)&&S(PINA,4)&&S(PINA,5)&&S(PINA,6))
		{
			PORTB = 0b00000000; //halt
			left=0;
			right=0;
		}
		else
		{
			if (left==1&&right==0)
			{
				PORTB = 0b00000001; // def left
			}
			if (left==0&&right==1)
			{
				PORTB = 0b00000100; //def right
			}
			else
			{
				PORTB = 0b00000101; //def straight
			}
		}
		
		
	}
	return 0;
}

