

// Replace BLYNK_CODE with unique code from Blynk app after registering.
// Add wifi credentials
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define TRIGGER 5
#define ECHO    4

char auth[] = "BLYNK_CODE";

//WiFi credentials.

char ssid[] = "WiFi NAME";
char pass[] = "WiFi PASSWORD";

void setup()
{

  
  Blynk.begin(auth, ssid, pass);
  pinMode(0, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  
}

void loop()
{
  
  Blynk.run();
  
  
  long duration, distance;
  
  // Clears the trigPin
  digitalWrite(TRIGGER, LOW);  
  delayMicroseconds(2); 
  
  
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10); 
  digitalWrite(TRIGGER, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(ECHO, HIGH);
  
  // Calculating the distance
  // distance is now in centimeters
  distance = (duration/2) / 29.1;
  
  if (distance > 100){
  lcd.print(0,0, "Door Open  ");
  }else {
   lcd.print(0,0, "Door Closed");
  }
}
