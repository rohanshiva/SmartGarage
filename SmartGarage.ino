

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "BLYNK_CODE";//Replace code

//WiFi credentials.

char ssid[] = "Name";// wifi name
char pass[] = "Password";// wifi password

const int trigPin = 2;  //D4
const int echoPin = 0;  //D3

long duration;
int distance;

WidgetLCD lcd(V3);

void setup()
{

  
  Blynk.begin(auth, ssid, pass);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
}

void loop()
{
  Blynk.run();
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculating the distance
  distance= duration*0.034/2;
  // Prints the distance on the Serial Monitor
  if (distance > 90) {
   lcd.print(0,0, "Door Closed  ");
  }  else {
   lcd.print(0,0, "Door Open");
  }
  delay(1000);
  
}
