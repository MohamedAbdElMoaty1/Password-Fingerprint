#include <Key.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(38,16,2);

byte pb1 = 10 ;
byte pb2 = 11 ;
byte pb3 = 12 ;
byte pb4 = 13 ;
byte pb5 = A0 ;
byte pb6 = A1 ;

byte y = 0 ;
byte z = 0 ;

char k[4][4]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}};

byte rpins[4]={2,3,4,5};
byte cpins[4]={6,7,8,9};
char key;
  
char pass[4]={'1','3','4','5'};
char pas[4]={}; 
  
Keypad mypad (makeKeymap(k),rpins,cpins,4,4);

byte i = 0 ;
byte counter = 0 ;
byte counterr = 0 ;

void setup() 
   {
  counterr=0;counter=0;i=0;y=0;
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Enter Password :"); 
pinMode(pb1,INPUT_PULLUP);
pinMode(pb2,INPUT_PULLUP);
pinMode(pb3,INPUT_PULLUP);
pinMode(pb4,INPUT_PULLUP);
pinMode(pb5,INPUT_PULLUP);
pinMode(pb6,INPUT_PULLUP);
    }

void loop() {
  key=mypad.getKey();
  if(key)
  {
    if(key!='D')
    {
lcd.setCursor(i,1);
lcd.print("*");
i++;
 pas[counter++]=key  ;
 if(i==4)i=0;      
    }
    else
    {
 for(byte x=0;x<=3;x++)
      {
   if (pass[x]==pas[x])
   {
     counterr++ ;  
   }  
       } 
  Serial.print(counterr) ;
      Serial.print(i) ;
      if(i==4)i=0;

      if(counterr >=4 && i==0)
      {        
lcd.clear(); 
lcd.setCursor(0,0);
lcd.print("User authorized");
delay(1500);        
lcd.clear(); 
lcd.print("Enter your finger");        
        
counterr=0;counter=0;i=0;y=0; 
      } // if 
     else
      {  
lcd.clear();   
lcd.setCursor(1,0);
lcd.print("Wrong Password");
delay(1500);
lcd.clear();
lcd.print("Enter your finger");        
counter=0;counterr=0;i=0;y=0;
       lcd.setCursor(0,0);
      }
     
    } /// else
    } /// if key 
  
  if(!digitalRead(pb1))
{
lcd.clear(); 
lcd.setCursor(0,0);
  lcd.print("The ID is : 1");
    delay(2000);
    lcd.clear();
    lcd.setCursor(0,0);
lcd.print("Enter password:");
}
if(!digitalRead(11))
{
lcd.clear(); 
lcd.setCursor(0,0);
  lcd.print("The ID is : 2");
    delay(2000);
    lcd.clear();
    lcd.setCursor(0,0);
lcd.print("Enter password:");
}
if(digitalRead(12) == 0)
{
lcd.clear(); 
lcd.setCursor(0,0);
  lcd.print("The ID is : 3");
    delay(2000);
    lcd.clear();
    lcd.setCursor(0,0);
lcd.print("Enter password:");
}        
if(digitalRead(13) == 0 )
{
lcd.clear(); 
lcd.setCursor(0,0);
  lcd.print("The ID is : 4");
    delay(2000);
    lcd.clear();
    lcd.setCursor(0,0);
lcd.print("Enter password:");
}
if(!digitalRead(pb5))
{
lcd.clear(); 
lcd.setCursor(0,0);
  lcd.print("The ID is : 5");
    delay(2000);
    lcd.clear();
    lcd.setCursor(0,0);
lcd.print("Enter password:");
}  
if(digitalRead(pb6) == 0)
{
lcd.clear(); 
lcd.setCursor(0,0);
  lcd.print("The ID is : 6");
    delay(2000);
    lcd.clear();
    lcd.setCursor(0,0);
lcd.print("Enter password:");
}
  
} //// loop



