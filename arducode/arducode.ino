#include "DHT.h"

#define state_on 53
#define state_off 51
#define state_temp 49
#define DHTPIN 47
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
int data;
int rotate=0;
int temp;
int templed = 0;
String c = ",";
String garb = "TIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZITIZI";
void setup() {
  Serial.begin(9600);
  digitalWrite(state_on,LOW);
  digitalWrite(state_off,LOW);
  digitalWrite(state_temp,LOW);
  dht.begin();
}

void loop() {
  String h = String(dht.readHumidity(),DEC);
  String t = String(dht.readTemperature(),DEC);
  String full = garb+c+h+c+t;
  Serial.println(full);
  switch (rotate){
    case 0:
      digitalWrite(state_on,LOW);
      digitalWrite(state_off,HIGH);
      break;
    case 1:
      digitalWrite(state_on,HIGH);
      digitalWrite(state_off,LOW);
      break;}
   switch (templed){
    case 0:
      digitalWrite(templed,LOW);
      break;
    case 1:
      digitalWrite(templed,HIGH);
      break;}
  
if (Serial.available() > 0) {
    data = Serial.readStringUntil('\n').toInt();
    switch (data){
      case 99:
        rotate=1;
        templed=0;
        break;
      case 100:
        rotate=0;
        templed=0;
        break;
      default:
        templed=1;
      }
      
      
  }   
}
