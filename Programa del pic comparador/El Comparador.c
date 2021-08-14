#include <16f877a.h>
#fuses hs,nowdt
#use delay(clock=20M)


#define use_portb_kbd TRUE
#include <lcd.c>
#include <kbd.c>
void main()
{
   
   char a;
   char b;

   

   int i=0;

   port_b_pullups (true);
   lcd_init ();
   kbd_init ();
   

   
   

   while(i<2)
   {
      a=0;
      b=0;
      lcd_gotoxy(1,1);
      printf(LCD_PUTC, "Agregar A");
      
      while (a==0)
      {
         lcd_gotoxy(1,2);
         a=kbd_getc();
         if (a!=0)
         {
            printf(lcd_putc, "a: %c", a);
         
            delay_ms(200);
            i++;
         
            printf(LCD_PUTC, "\f");
      
         }
         
      }
      lcd_gotoxy(1,1);
      printf(LCD_PUTC, "Agregar B");
     
      while (b==0)
      {
         lcd_gotoxy(1,2);
         b=kbd_getc();
         if (b!=0)
         {
            printf(lcd_putc, "b: %c", b);
         
            delay_ms(200);
            i++;
         
            printf(LCD_PUTC, "\f");
      
         }
      }
      if (a==b) {
         OUTPUT_HIGH(pin_c0);
         printf(lcd_putc, "Son iguales");
       }
       if (a>b) {
         OUTPUT_HIGH(pin_c1);
         printf(lcd_putc, "A es mayor");
       }
       if (a<b) {
         OUTPUT_HIGH(pin_c2);
         printf(lcd_putc, "b es mayor");
       }
      
   }
   lcd_gotoxy(1,2);
   printf(LCD_PUTC, "Fin del proceso");
   
}

