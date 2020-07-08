#include <16F887.h>
#fuses NOWDT,PUT,hs,NOPROTECT
#use delay(clock=20000000)
#byte portD=0x08
#byte portB=0x06
#byte portC=0x07
int angle=0;
int mode=0,i,a,old=0;
signed long delay1,delay2;
void tocdo(int a,int n)
{     
        int f;
        for (f=a;f<=n;f++) 
        {
            delay1=(1518+f*4.45);
            delay2=20000-delay1;
            output_high(pin_D1);
            delay_us(delay1);
            output_low(pin_D1);
            delay_us(delay2);
            delay_ms(1000);
        if(f>=n)
        {
            a=n;
            break;
        }
        } 
}
void duongnguoc(int a,int n)
{   
int f;
        for (f=a;f>=n;f--) 
        {
            delay1=(1518+f*4.45);
            delay2=20000-delay1;
            output_high(pin_D1);
            delay_us(delay1);
            output_low(pin_D1);
            delay_us(delay2);
            delay_ms(1000);
        if(f<=n)
        {
            a=n;
            break;
        }
        } 
   
}
void tocdoam(int a,int n)
{           
        int f;
        for (f=a;f<=n;f++) 
        {
            delay1=(1518-f*4.45);
            delay2=20000-delay1;
            output_high(pin_D1);
            delay_us(delay1);
            output_low(pin_D1);
            delay_us(delay2);
            delay_ms(1000);
        if(f>=n)
        {
            a=n;
            break;
        }
        }     
}
void tocdoamnguoc(int a,int n)
{
             int f;
        for (f=a;f>=n;f--) 
        {
            delay1=(1518-f*4.45);
            delay2=20000-delay1;
            output_high(pin_D1);
            delay_us(delay1);
            output_low(pin_D1);
            delay_us(delay2);
            delay_ms(1000);
        if(f<=n)
        {
            a=n;
            break;
        }
        }     
}
void main()
{
set_tris_b(255);
set_tris_D(0);
portd=0;
portB=0;
old=0;
while(true)
      {
     angle=portC;
 if(input(pin_A0)==1)
     {
                                if( input(pin_A1)==0)
                                {
                                       angle=portC;
                                       delay1=1518-angle*4.45;
                                       delay2=20000-delay1;
                                       output_high(pin_D1);
                                       delay_us(delay1);
                                       output_low(pin_D1);
                                       delay_us(delay2);
                                       old=angle;
                                }
                                else 
                                {
                                if(old<angle)
                                {
                                            tocdoam(old,angle);
                                            old=angle;
                                }
                                else if (old>angle)
                                {
                                             tocdoamnguoc(old,angle);
                                             old=angle;
                                }
                                }
     }  
    
 else  if(input(pin_A0)==0)
    {
                                           if(input(pin_A1)==0)
                                           {
                                                    angle=portC;
                                                   delay1=1518+angle*4.45;
                                                   delay2=20000-delay1;
                                                  output_high(pin_D1);
                                                   delay_us(delay1);
                                                   output_low(pin_D1);
                                                   delay_us(delay2);
                                                   old=angle;}
                                             else
                                             {
                                                               if (old<angle)
                                                               {
                                                               tocdo(old,angle);
                                                               old=angle;
                                                               }
                                                               else if(old>angle)
                                                               {
                                                               duongnguoc(old,angle);
                                                               old=angle;
                                                               }
                                             }
                                           }
   }
}
