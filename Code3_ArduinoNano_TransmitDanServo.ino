/*
 * Adli Aulia Fattah H
 * Electrical Engineering, Universitas Indonesia
 */
#include <Servo.h>

Servo myservo_y, myservo_x;
int LDR1 = A0, LDR2 = A1, LDR3 = A2, LDR4 = A3;
float rRDL1 = 0, rRDL2 = 0, rRDL3 = 0, rRDL4 = 0;
int max1=0, max2=0, max3=0;
int ser1 = 80, ser2=0;
float Volt1, Volt;;

void setup() {
  Serial.begin(9600);
  myservo_x.attach(8); //myservo2 rotator
  myservo_y.attach(9); //myservo1 panel
  myservo_x.write(0);
  myservo_y.write(ser1);
}

void loop() {
  rRDL1 = analogRead(LDR1) / 100;
  rRDL2 = analogRead(LDR2) / 100;
  rRDL3 = analogRead(LDR3) / 100;
  rRDL4 = analogRead(LDR4) / 100;

  max1 = max(rRDL1, rRDL2);
  max2 = max(rRDL3, rRDL4);
  max3 = max(max1, max2);
  
  if(rRDL2<max3 && rRDL4<max3)
  {
    if(ser1>0)
      ser1-=3;
    myservo_y.write(ser1);
  }
  if(rRDL3<max3 && rRDL1<max3)
  {
    if(ser1<160)
      ser1+=3;
    myservo_y.write(ser1);
  }

  if(rRDL2<max3 && rRDL3<max3)
  {
    if(ser2<100)
      ser2+=3;
    myservo_x.write(ser2);
  }
  if(rRDL1<max3 && rRDL4<max3)
  {
    if(ser2>0)
      ser2-=3;
    myservo_x.write(ser2);
    
  }
  Volt1=analogRead(A6);//s ke pin analog A0
  Volt=((Volt1*0.00489)*5); //0.004887585

  String sendToESP = "";
  sendToESP += Volt;
  Serial.println(sendToESP);
  delay(100);
}
