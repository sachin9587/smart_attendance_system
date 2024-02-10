#include <SPI.h>
#include <MFRC522.h>
#include <RTClib.h>
#include <Wire.h>
#include <Servo.h>
#define SS_PIN 10
#define RST_PIN 9
#define buzzer 5
const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor
int flag;
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
RTC_DS3231 rtc;


char t[32];
const int checkInHour = 00;
const int checkInMinute = 59;
int userCheckInHour;
int userCheckInMinute;
Servo myservo;
int pos=0;
long duration, cm;

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
void Ultrasonic()
{
    pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   
   cm = microsecondsToCentimeters(duration);
   
   
   
   if(cm>0&&cm<50)
   {
     flag=1;
     Serial.print(cm);
     Serial.print("cm \t");
    
   }
   delay(100);
}
void setup() {
  pinMode(buzzer, OUTPUT); 
  pinMode(2, OUTPUT);
  myservo.attach(4); 
  Serial.begin(9600); 
  while (!Serial);
  SPI.begin();
  pinMode(SS_PIN, OUTPUT);
  digitalWrite(SS_PIN, HIGH);
  mfrc522.PCD_Init();   // Initiate MFRC522
  Wire.begin();
  rtc.begin();
  rtc.adjust(DateTime(F(_DATE), F(TIME_)));
  
  
  delay(500);
 
}

void loop() {
   
  flag=0;
  // Look for new cards
  if (!mfrc522.PICC_IsNewCardPresent()) {
    return;
  }
  // Select one of the cards
  if (!mfrc522.PICC_ReadCardSerial()) {
    return;
  }
  
  //Show UID on serial monitor
  Serial.print("\nUID tag :");
  String content = "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.print("\t");
  Serial.print("Message : ");
  content.toUpperCase();
  
  if (content.substring(1) == "60 E9 8E A3" || content.substring(1) == "E3 84 D1 95") {  //change here the UID of the card/cards that you want to give access
    Serial.print("Authorized access");
    Serial.print("\t");
    
    digitalWrite(2, HIGH);
    tone(buzzer, 1000);
    delay(1000);
    digitalWrite(2,LOW);
    noTone(buzzer);
    delay(1000);
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
      }
  while(flag==0)
  {
   Ultrasonic();
  }

    while(1)
    {
    if(cm>0 && cm<50)
    {
      digitalWrite(2, HIGH);
      tone(buzzer, 1000);
      delay(1000);
      digitalWrite(2,LOW);
      noTone(buzzer);
      delay(1000);
      for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15ms for the servo to reach the position
      }
      break;
      }
      }
    DateTime now = rtc.now();
    sprintf(t, "%02d:%02d:%02d %02d/%02d/%02d", now.hour(), now.minute(), now.second(), now.day(), now.month(), now.year());  
    Serial.print(F("Date/Time: "));
    Serial.print(t);
    Serial.print("\t");
  
    userCheckInHour = now.hour();
    userCheckInMinute = now.minute();
    
    if ((userCheckInMinute <= checkInMinute)) {
      if(content.substring(1) == "60 E9 8E A3")
      Serial.print("SACHIN - You're welcome!");
      if(content.substring(1) == "E3 84 D1 95")
      Serial.print("SIDHARTH - You're welcome!");
    } else if (userCheckInMinute > checkInMinute) {
      Serial.println("You are late...");
     
      digitalWrite(2,HIGH);
      delay(1000);
      digitalWrite(2,LOW);
      delay(1000);
    }
  }
 
  else {
    Serial.println(" Access denied!! Try Again");
    digitalWrite(2,HIGH);
    tone(buzzer,500); 
    delay(100);
    tone(buzzer,392); 
    digitalWrite(2,LOW);
    delay(1000);
       
    noTone(buzzer); 
    delay(3000);
  }
 
}