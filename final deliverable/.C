#define BLYNK_TEMPLATE_ID "TMPLzvCSIVya"
#define BLYNK_DEVICE_NAME "IOT"
#define BLYNK_AUTH_TOKEN "TObjLoXh2lZq3Ys6wwJdwj19i2GdjWZa"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#include <SoftwareSerial.h> 
#include <TinyGPS.h> 
float lat = 10.73616,lon = 79.12620; // create variable for latitude and longitude object  
SoftwareSerial gpsSerial(D8,D7);//rx,tx
TinyGPS gps; // create gps object 

BlynkTimer timer;

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "IOT";
char pass[] = "12345678";

const int key =D6;

String inputstring = "";                              
String temperature= "000";                             
boolean input_string_complete = false;                
boolean sensor_string_complete = false;               
char temp=0;
int vat=0;
char inchar,temp_flag[3],ph_flag[3];   
int flog=0;  
int button1=0;

void serialEvent()
  {                                 
        if(Serial.available() > 0)
        {                    
            inchar = (char)Serial.read();
            if(inchar=='*')
            {
                while(Serial.available() > 0)
                    {    
                      inchar = (char)Serial.read();              
                      Serial.print(inchar);
                      if(inchar=='#'){break;}
                      inputstring+=inchar;
                      temp++;
                   }
             }
           }   
  }   
void setup()
{
  Serial.begin(9600);
  gpsSerial.begin(9600); // connect gps sensor 
  Blynk.begin(auth, ssid, pass);
  inputstring.reserve(30);   
  pinMode(key,INPUT);                           
 }

void loop()
{
    Blynk.run();
    timer.run();
    vat++;
    if (Serial.available() > 0) { serialEvent(); }
    Blynk.virtualWrite(V1,inputstring);
    inputstring = ""; 
  
  while(gpsSerial.available())
  { // check for gps data 
     if(gps.encode(gpsSerial.read()))// encode gps data 
       {  
        gps.f_get_position(&lat,&lon); // get latitude and longitude // lcd.print(lat); // lcd.print(lon); 
       } 
  } 
String latitude = String(lat,6); 
  String longitude = String(lon,6); 
//Serial.println(latitude+";"+longitude);
 Blynk.virtualWrite(V2,latitude+";"+longitude); 
                                                                                                                                                           
}
