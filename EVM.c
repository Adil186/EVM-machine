/*
 * EVM.c
 *
 * Created: 06-06-2018 06:09:19
 *  Author: Adil
 */ 


# include <avr/io.h>
# define F_CPU 8000000
# include <util/delay.h>
# include "lcd.h"
int i,j,k,l;
char w,x,y,z,t,s;
int main(void)
{   PORTA=0x00;
	DDRA=0x00;
	DDRC=0xFF;
	DDRB=0xFF;
	i=j=k=l=0;
	lcd_init();
	lcd_comm(0x83);
	lcd_string("Electronic");
	lcd_comm(0xC0);
	lcd_string("!Voting Machine!");
	_delay_ms(5000);
	lcd_comm(0x01);
    while(1)
    {
	  lcd_comm(0x80);
	  lcd_string("1.BJP");
	  lcd_comm(0x86);
	  lcd_string("2.CONGRESS");
	  lcd_comm(0xC0);
	  lcd_string("3.AAP");
	  lcd_comm(0xC6);
	  lcd_string("4.Others");
	  w=PINA&0x01;
	  x=PINA&0x02;
	  y=PINA&0x04;
	  z=PINA&0x08;
	  t=PINA&0x10;
	  s=PINA&0x20;
	  if(w==0x01)
	  {  
		  i=i+1;
		  _delay_ms(100);
		  lcd_comm(0x01);
		  lcd_comm(0x82);
		  lcd_string("Vote Accepted");
		  lcd_comm(0xC5);
		  lcd_string("BJP");
		  _delay_ms(500);
		  lcd_comm(0x01);
		  PORTB=0x01;
		  PORTC=0x01;
		  _delay_ms(100);
		  PORTB=0x00;
		  PORTC=0x00;
		    while(PINA&0x01);		  
	  }
	   if(x==0x02)
	   {
		   j=j+1;
		   _delay_ms(100);
		   lcd_comm(0x01);
		   lcd_comm(0x82);
		   lcd_string("Vote Accepted");
		    lcd_comm(0xC5);
		    lcd_string("CONGRESS");	   
		   _delay_ms(500);
		   lcd_comm(0x01);
		   PORTB=0x02;
		     PORTC=0x01;
			 _delay_ms(100);
			 PORTB=0x00;
			 PORTC=0x00;
			 if(j==5)
			 {
				 i++;
				 j--;
			 }
			  while(PINA&0x02);
	   }
	    if(y==0x04)
	    {
		    k=k+1;
		    _delay_ms(100);
		    lcd_comm(0x01);
			lcd_comm(0x82);
		    lcd_string("Vote Accepted");
			 lcd_comm(0xC5);
			 lcd_string("AAP");
		    _delay_ms(500);
		    lcd_comm(0x01);
			PORTB=0x04;
			 PORTC=0x01;
			 _delay_ms(100);
			 PORTB=0x00;
			 PORTC=0x00;					
	    }
		 if(z==0x08)
		 {
			 l=l+1;
			 _delay_ms(100);
			 lcd_comm(0x01);
			 lcd_comm(0x82);
			 lcd_string("Vote Accepted");
			 lcd_comm(0xC5);
			 lcd_string("Others");
			 _delay_ms(500);
			 lcd_comm(0x01);
			 PORTB=0x08;
			  PORTC=0x01;
			  _delay_ms(100);
			  PORTB=0x00;
			  PORTC=0x00;
		 }
		 if(t==0x10)
		 {
			 if(i>j)
			 {
				 if(i>k)
				 {
					 if (i>l)
					 {
						 lcd_comm(0x01);
						 lcd_string("Winner is BJP=");
						 lcd_number(i);
					     _delay_ms(500);
						 PORTB=0x20;
		                 PORTC=0x01;
						 _delay_ms(1000);
						 PORTB=0x00;
						 PORTC=0x00;
					 }
				 }
			 }
			 
				 else if(j>i)
				 {
					 if(j>k)
					 {
						 if (j>l)
						 {
						 
						lcd_comm(0x01);
						lcd_string("Winner is");
						lcd_comm(0xC5);
						lcd_string("CONGRESS=");
						lcd_number(j);
						_delay_ms(500); 
						 PORTB=0x20;
						 PORTC=0x01;
						 _delay_ms(1000);
						 PORTB=0x00;
						 PORTC=0x00;
					 }
				 }
				 }
				 else if(k>i)
				 {
					 if(k>j)
					 {
						 if(k>l)
						 {	 
					lcd_comm(0x01);
					lcd_string("Winner is AAP=");
					lcd_number(k);
					_delay_ms(500);
					 PORTB=0x20;
					 PORTC=0x01;
					 _delay_ms(1000);
					 PORTB=0x00;
					 PORTC=0x00;
				 }
					 }
				 }
				 else if(l>i)				 
				 {
					  if(l>j)
					 {
						 if(l>k)
						 {
					 lcd_comm(0x01);
					 lcd_string("Winner is");
					 lcd_comm(0xC5);
					 lcd_string("Others=");					 
					 lcd_number(l);
					 _delay_ms(500);
					  PORTB=0x20;
					  PORTC=0x01;
					  _delay_ms(1000);
					  PORTB=0x00;
					  PORTC=0x00;					 
				 }
					 }
				 }
				 else if(i==j||j==k||k==l||i==k||j==l||i==l)
				 {
					 lcd_comm(0x01);
					 lcd_comm(0x82);
					 lcd_string("!No Winner!");
					 _delay_ms(500);
					 lcd_comm(0x01);
					  PORTB=0x10;
					  PORTC=0x01;
					  _delay_ms(1000);
					  PORTB=0x00;
					  PORTC=0x00;
				 }
				 
			 }
			 if(s==0x20)
			 {   lcd_comm(0x01);
				 i=j=k=l=0;
				 lcd_string("!Resetting EVM!");
				 PORTB=0x40;
				 PORTC=0x01;
				 _delay_ms(1000);
				 PORTC=0x00;
				 lcd_comm(0x01);
				 
			 }
		 }
	 }