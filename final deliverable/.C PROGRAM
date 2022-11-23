int sensorValue=0;
 
const int ledPin = 2; 
void setup() 
  {
    Serial.begin(9600); 
    pinMode(ledPin, OUTPUT);
  }
void loop()
  {
    loop: 
    sensorValue = analogRead(A0);
    sensorValue= sensorValue * (200 / 1024.0);    
  Serial.print("*");
  Serial.print(" T:");Serial.print(sensorValue);Serial.print("oC "); 
  Serial.print("#");   
          if(sensorValue>=40)
              {
                  digitalWrite(ledPin, HIGH);
              }
          else
              {
                 digitalWrite(ledPin, LOW);
              }
          delay(1000);
          goto loop;
  }
