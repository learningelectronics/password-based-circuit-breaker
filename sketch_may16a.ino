
#include <Keypad.h>
#include <LiquidCrystal.h>
const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
LiquidCrystal lcd(9, 10, 11, 12, 14, 15);
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {2, 3, 4,5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6, 7, 8}; //connect to the column pinouts of the keypad
   
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
char getpass[3];
char setpass1[3]={'4','8','9'};
char setpass2[3]={'5','8','0'};
void setup()
{
    pinMode(13,OUTPUT);
    digitalWrite(13,LOW);
     lcd.begin(16, 2);
     lcd.setCursor(0,0);
    lcd.print("Enter passward!");delay(10);
   lcd.setCursor(0,1);
}

  

  
void loop()
{ 
  int x=0;
  int x1=0;

   for(int i=0;i<3;)
  {  

  char key = keypad.getKey();
   if (key)
   {
    getpass[i]=key;
    lcd.print('*');
     i++;
   }
    
  }
  
     for(int i=0;i<3; i++)
  {    
    if(getpass[i]==setpass1[i])
    {
     x++;
     }
       if(getpass[i]==setpass2[i])
    {
     x1++;
     }
    
  }
  if(x==3) 
    {
       lcd.setCursor(0,0);
        lcd.print("passward match    ");
         lcd.setCursor(0,1);
       lcd.print("System is ON      ");
       digitalWrite(13,HIGH);   delay(1000);
     }
   
  else if(x1==3) 
    {
       lcd.setCursor(0,0);
       lcd.print("passward match    ");
       lcd.setCursor(0,1);
       lcd.print("System is OFF     ");
       digitalWrite(13,LOW);delay(1000);
     }
     else
     {
     lcd.setCursor(0,0);
      lcd.print("passward Not match   ");
     lcd.setCursor(0,1);
     lcd.print("Sorry Try again      ");delay(1000);
     }
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Enter passward!   ");delay(10);
     lcd.setCursor(0,1);


  }
