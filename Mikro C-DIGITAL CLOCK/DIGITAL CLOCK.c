// Lcd pinout settings
sbit LCD_RS at RB0_bit;
sbit LCD_EN at RB1_bit;
sbit LCD_D7 at RB5_bit;
sbit LCD_D6 at RB4_bit;
sbit LCD_D5 at RB3_bit;
sbit LCD_D4 at RB2_bit;

// Pin direction
sbit LCD_RS_Direction at TRISB0_bit;
sbit LCD_EN_Direction at TRISB1_bit;
sbit LCD_D7_Direction at TRISB5_bit;
sbit LCD_D6_Direction at TRISB4_bit;
sbit LCD_D5_Direction at TRISB3_bit;
sbit LCD_D4_Direction at TRISB2_bit;
char S1,S2,M1,M2,H1,H2,J;
void ismail()
{
 lcd_out(1,3,":");lcd_out(1,6,":");
 delay_ms(500);
 lcd_out(1,3," ");lcd_out(1,6," ");
 delay_ms(500);
}
void main() 
{
  S1=S2=M1=M2=H1=H2=48;
  J=1;
  Lcd_Init();                        // Initialize LCD

  Lcd_Cmd(_LCD_CLEAR);               // Clear display
  Lcd_Cmd(_LCD_CURSOR_OFF);          // Cursor off

  for(;;)
  {
   ismail();
   S1++;
   if(S1==58){S1=48;S2++;}
   if(S2==54){S1=S2=48;M1++;}
   if(M1==58){M1=48;M2++;}
   if(M2==54){M1=M2=48;H1++;}
   if(H1==58){H1=48;H2++;}
   if(H2==50&&H1==52){H1=H2=48;J++;}
   if(J==1){Lcd_out(1, 10,"LUN");}
   if(J==2){Lcd_out(1, 10,"MAR");}
   if(J==3){Lcd_out(1, 10,"MER");}
   if(J==4){Lcd_out(1, 10,"JEU");}
   if(J==5){Lcd_out(1, 10,"VEN");}
   if(J==6){Lcd_out(1, 10,"SAM");}
   if(J==7){Lcd_out(1, 10,"DIM");}
   if(J==8){J=1;}
   Lcd_chr(1, 8, S1);Lcd_chr(1, 7, S2);Lcd_chr(1, 5, M1); Lcd_chr(1, 4, M2); Lcd_chr(1, 2, H1);Lcd_chr(1, 1, H2);
  }
}