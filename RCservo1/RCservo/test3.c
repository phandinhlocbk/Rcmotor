#include <16F887.h>
#use delay(clock=20000000)
#fuses HS,NOWDT,PUT,NOLVP,NOPROTECT,BROWNOUT
#byte PORTD=0x08
#byte PORTC=0x07
#byte PORTA=0x05
#byte PORTE=0x08
Char maso[13]={0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111,0b010111111,0b11111111,0b10010010};
int i,j,k,l=0,a,m;

#INT_RB
void RB_itr()
{
 if (input(pin_b4)==0)
 {
 i++;
 }
 if (input(pin_b5)==0)
 {
 j++;
 }
 
  if (input(pin_b6)==0)
 {
 k++;
 }
   if (input(pin_b7)==0)
 {
 l=i*10+j;
 if(k==11)
 {
   output_low(pin_E0);
 }
 else 
   output_high(pin_E0);
if(m==12)
{
 output_high(pin_E1);
}
else 
   output_low(pin_E1);

 }
}
#INT_EXT
void ngat()
{
m++;
}
void hienthi(int a,int b,int c,int d )
{

output_A(0b11111110);
output_D(~maso[b]);
delay_us(300);
output_A(0b11111101);
output_D(~maso[a]);
delay_us(300);
output_A(0b11111011);
output_D(maso[c]);
delay_us(300);
output_A(0b11110111);
output_D(maso[d]);
delay_us(300);
}
void main()
{
i=0;
j=0;
k=11;
m=11;
set_tris_b(255);
set_tris_D(0);
set_tris_A(0);
portd=0;
enable_interrupts(global);
enable_interrupts(INT_EXT);
enable_interrupts(INT_RB);
enable_interrupts(INT_RB4);
enable_interrupts(INT_RB5);
enable_interrupts(INT_RB6);
enable_interrupts(INT_RB7);
Ext_int_edge(H_to_L);
output_C(0b11111111);
set_tris_A(0x00);
set_tris_E(0x00);
while(1)
{
if (i>9)
i=0;
if (j>9)
j=0;
if (k>11)
k=10;
if (m>12)
m=11;
hienthi(i,j,k,m);
portC=l;
}
}
