#include <LiquidCrystal.h>
const int rs = 13, en = 12, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int redLed = 9;
int greenLed = 10;
int buzzer = 11;
int smokeA0 = A0;
// Your threshold value
int sensorThres =100 ;

void setup() {
  
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("    WELCOME");
      lcd.setCursor(1,1);
      lcd.print("   GOODFELLAS");
      delay(10000);
      lcd.clear();
      
  
}
void loop() {
      float TestData = Serial.read();
  
  
  int analogSensor = analogRead(smokeA0); 
  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
   
 
    
   if (analogSensor <= sensorThres)
      { noTone(buzzer);
      digitalWrite(redLed, LOW);
      digitalWrite(greenLed, HIGH);
          delay(2000);
      lcd.clear();
        lcd.setCursor(3,0);
        
      lcd.print("FINDING CO ");
     
       lcd.setCursor(4,1);
      lcd.print("AND CO2.");
      
      delay(2000);
      lcd.clear();
      lcd.setCursor(3,0);
      lcd.print("FINDING CO ");
       lcd.setCursor(4,1);
      lcd.print("AND CO2..");
      delay(2000);
      lcd.clear();
      lcd.setCursor(3,0);
      lcd.print("FINDING CO ");
       lcd.setCursor(4,1);
      lcd.print("AND CO2...");
      delay(10000);
      lcd.clear();
      lcd.print("NOT DETECTED YET");
      delay(2000);
    }
    else
    {  lcd.clear();
      digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    lcd.setCursor(0,0); 
    lcd.print("    CO AND ");
    lcd.setCursor(0,1); 
    lcd.print(" CO2 DETECTED");
    tone(buzzer, 1000, 200);
    delay(100);
    }
 
}
