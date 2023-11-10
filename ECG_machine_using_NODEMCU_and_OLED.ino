#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1305.h>

#define OLED_RESET LED_BUILTIN
#define OLED_Address 0x78 // 0x3C device address of I2C OLED. Few other OLED has 0x3D
Adafruit_SSD1305 oled(128, 32, &Wire, OLED_RESET); // create our screen object setting resolution to 128x64
 
const int LO1Pin = 10; //LO - at D5
const int LO2Pin = 11; //LO + at D6
const int heartSensorPin = A0;
int LastTime=0;
int ThisTime;
bool BPMTiming=false;
bool BeatComplete=false;
int BPM=0;
int lastx=0;
int lasty=0;

#define UpperThreshold 560
#define LowerThreshold 530

int heartSensorValue;
int x, y; 

 
void setup() {
Serial.begin(9600);
pinMode(LO1Pin, INPUT); // Setup for leads off detection LO -
pinMode(LO2Pin, INPUT); // Setup for leads off detection LO +
pinMode(heartSensorPin, INPUT);
  
oled.begin(SSD1305_SWITCHCAPVCC, OLED_Address);
oled.clearDisplay();
oled.setTextSize(2);
delay(100);
}
 
void loop() {
if((digitalRead(LO1Pin) == 1) || (digitalRead(LO2Pin) == 1)) 
 { Serial.println('!');}
else {
  if(x>319){
oled.clearDisplay();
x=0;
lastx=x;
}
 
ThisTime=millis();
heartSensorValue = analogRead(heartSensorPin);
Serial.println(heartSensorValue);
oled.setTextColor(WHITE);
y = 180 - (int)(heartSensorValue/6.5); 
oled.writeLine(lastx,lasty,x,y,WHITE);
lasty=y;
lastx=x;
x++;
delay(10);
 
/*if(value>UpperThreshold)
{
if(BeatComplete)
{
BPM=ThisTime-LastTime;
BPM=int(60/(float(BPM)/1000));
BPMTiming=false;
BeatComplete=false;
tone(8,1000,250);
}
if(BPMTiming==false)
{
LastTime=millis();
BPMTiming=true;
}
}
if((value<LowerThreshold)&(BPMTiming))
BeatComplete=true;
 
oled.writeFillRect(0,50,128,16,BLACK);
oled.setCursor(0,50);
oled.print("BPM:");
oled.print(BPM);
 
oled.display();
a++;*/
}
}
