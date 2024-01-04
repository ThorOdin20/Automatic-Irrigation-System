#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
int val = 0 ;

void setup()
{
Serial.begin(9600);
lcd.init();
lcd.backlight();

pinMode(3,INPUT);
pinMode(4,OUTPUT);
digitalWrite(4,HIGH);

lcd.setCursor(0,0);
lcd.print("Irrigation System ");
}

void loop()
{

val = digitalRead(3);
Serial.println(val);
delay(1000);

if(val == 1 )
{
digitalWrite(4,LOW);
lcd.setCursor(0,1);
lcd.print(" PUMP ON ");
}
else
{
digitalWrite(4,HIGH);
lcd.setCursor(0,1);
lcd.print(" PUMP OFF ");
}
}