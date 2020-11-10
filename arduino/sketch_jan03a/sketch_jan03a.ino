int buzzer=13;
int i=1;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzer,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  tone(buzzer, 1000, 200);
  i+=1;
  delay(1000);
  noTone(buzzer);
  while(i>10){
  tone(buzzer, 1000, 200);
  delay(500);
  noTone(buzzer);
  i-=2;
}
Serial.println(i);
}
