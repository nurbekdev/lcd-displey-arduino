int a;
int tugma=8;
#include <LiquidCrystal.h>
const int rs=4, en=6, d4=10 ,d5=11, d6=12, d7=13;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
#include <IRremote.h>
IRrecv pult(7);
decode_results natija;
void setup() {
   Serial.begin(9600);
  pult.enableIRIn();
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  Serial.begin(9600);
  pinMode(tugma,INPUT);
  lcd.begin(16,2);
  lcd.setCursor(1,0);
  lcd.print("O'zgaruvchilar");
   lcd.setCursor(0,1);
  lcd.print("Salfetka:");
  lcd.setCursor(12,1);
  lcd.print("ta");
}

void loop() {
  if(digitalRead(tugma)==1){while(digitalRead(tugma)==1){}a++;
  Serial.println(a);
  lcd.setCursor(9,1);
  lcd.print(a);
   digitalWrite(2,HIGH);
    delay(300);}
   
  else{digitalWrite(2,LOW);}
  if(a==10){
    digitalWrite(3,HIGH);}
    else{digitalWrite(3,0);}
    digitalWrite(5,HIGH);
    if (pult.decode(&natija)) {
   
    pult.resume();
    Serial.println(natija.value, DEC);
    if(natija.value==3810010651){ lcd.autoscroll();}
  }
}
