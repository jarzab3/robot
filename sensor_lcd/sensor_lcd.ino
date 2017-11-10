/*
* Ultrasonic Sensor HC-SR04 and Arduino Tutorial
*
* Crated by Dejan Nedelkovski,
* www.HowToMechatronics.com
*
*/
// defines pins numbers

const int trigPin = 7;
const int echoPin = 8;
// defines variables
long duration;
int distance;

/////SERVO

#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int pos = 0;    // variable to store the servo position




//////filter variables
float EMA_a = 0.6;      //initialization of EMA alpha

float EMA_a_low = 0.3; 
float EMA_a_high = 0.5;

int EMA_S_low = 0;        //initialization of EMA S
int EMA_S_high = 0;

int highpass = 0;
//int bandpass = 0;

int bandpass = 0;
int bandstop = 0;

int sensorValue = 0; 


void setup() {

myservo.attach(9);
  
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input

//Serial.begin(9600); // Starts the serial communication
pinMode(LED_BUILTIN, OUTPUT);

///////filtering
Serial.begin(115200);           //setup of Serial module, 115200 bits/second

EMA_S_low = pulseIn(echoPin, HIGH);
EMA_S_high = pulseIn(echoPin, HIGH);


}
void loop() {

digitalWrite(trigPin, LOW);
delayMicroseconds(2);

digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);
// Calculating the distance

distance = duration/58.2;

//Serial.println(distance);

//delay(1000);                          //print digital value to serial

//EMA_S = (EMA_a*distance) + ((1-EMA_a)*EMA_S);    //run the EMA
//Serial.println(EMA_S);                              //print digital value to serial
//delay(50);      

bandpass = EMA_S_high - EMA_S_low;


EMA_S_low = (EMA_a_low*distance) + ((1-EMA_a_low)*EMA_S_low);  //run the EMA
 
EMA_S_high = (EMA_a_high*distance) + ((1-EMA_a_high)*EMA_S_high);
   
highpass = sensorValue - EMA_S_low;     //find the high-pass as before (for comparison)
bandpass = EMA_S_high - EMA_S_low;      //find the band-pass
bandstop = sensorValue - bandpass;        //find the band-stop signal

 
Serial.print(highpass);
Serial.print(",");
Serial.print(bandpass);
Serial.print(",");
Serial.print(bandstop);
Serial.print(",");

Serial.print(distance);
   
delay(20);                              //20ms delay

int y = map(bandpass, 1, -180, 1, 180);
//
//Serial.println("mapped");
Serial.print(",");
Serial.println(y);
//Serial.println("");

myservo.write(y);

//for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
//  myservo.write(pos);            // tell servo to go to position in variable 'pos'
//  delay(15);                       // waits 15ms for the servo to reach the position
//}

//for (pos = 0; pos <= 180; pos += 1) { // goes from 180 degrees to 0 degrees
//  myservo.write(pos);            // tell servo to go to position in variable 'pos'
//  delay(15);                       // waits 15ms for the servo to reach the position
//}

  
}


