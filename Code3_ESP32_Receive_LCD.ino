/*
 * Adli Aulia Fattah H
 * Electrical Engineering, Universitas Indonesia
 */
#include "TRIGGER_WIFI_ESP32.h"               
#include "TRIGGER_GOOGLESHEETS_ESP32.h"   
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); // Set the LCD address to 0x27 for a 16 chars and 2 line display
//pin lcd SDA ke A4 dan SCL ke A5
/**********Google Sheets Definations***********/
char column_name_in_sheets[ ][20] = {"value1"};                        /*1. The Total no of column depends on how many value you have created in Script of Sheets;2. It has to be in order as per the rows decided in google sheets*/
String Sheets_GAS_ID = "AKfycbzO21jQ63wloswfDZ1W39CLu71VHUFag_eP1KM4YzY1hTgHoRkUmozygHiSWzXZDnnmhA";                                         /*This is the Sheets GAS ID, you need to look for your sheets id*/
int No_of_Parameters = 1;                                                                /*Here No_of_Parameters decides how many parameters you want to send it to Google Sheets at once, change it according to your needs*/
const char* WIFI_NAME= "AA"; 
const char* WIFI_PASSWORD = "SATUSATU";
/*********************************************/
float var1;
unsigned long times = 0;
void setup(){
  Serial.begin(9600);
  lcd.begin(); // initialize the LCD
  lcd.clear();
  lcd.noCursor();
  lcd.backlight(); // Turn on the blacklight and print a message.
  
  lcd.setCursor(0,0);
  lcd.print("Connecting WIFI");
  Serial.print("Connecting to ");
  Serial.println(WIFI_NAME);
  WIFI_Connect(WIFI_NAME, WIFI_PASSWORD);                                                     /*Provide you Wi-Fi SSID and password to connect to Wi-Fi*/
  Google_Sheets_Init(column_name_in_sheets, Sheets_GAS_ID, No_of_Parameters );
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Connected");
  delay(3000);
}

void loop(){

  String msg = ""; //Inisiasi variabel penerima
  //Selama data serial ada
  while(Serial.available() > 0){
    //Ambil data serial
    msg += char(Serial.read()); // karena yg dikirim kode ascii
  }  
  delay(50);
  Serial.print("Receive: ");
  Serial.println(msg);
  var1 = msg.toFloat();
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("TEGANGAN");
  lcd.setCursor(0,1);
  lcd.print("PV :");
  lcd.setCursor(4,1);
  lcd.print(var1);
  //delay(500);
  delay(1000); //paling ideal delay 1s, hindari < 1s

  unsigned long times_now = millis();
  if (times_now - times >= 10000){
    Data_to_Sheets(No_of_Parameters,  var1);
    Serial.println();
    times = millis();  
  }
}
