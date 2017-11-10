/*
 * rosserial Publisher Example
 * Prints "hello world!"
 */

#include <ros.h>
#include <std_msgs/String.h>


#define trigPin 13
#define echoPin 12
#define led 11
#define led2 1


ros::NodeHandle  nh;

std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);

char hello[13] = "hello world!";


void setup()
{
  nh.initNode();
  nh.advertise(chatter);
  
//  Serial.begin (9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
//  pinMode(led, OUTPUT);
//  pinMode(led2, OUTPUT);
}

void loop()
{

    long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  
//  if (distance < 4) {  // This is where the LED On/Off happens
//    digitalWrite(led,HIGH); // When the Red condition is met, the Green LED should turn off
//  digitalWrite(led2,LOW);
//}
//  else {
//    digitalWrite(led,LOW);
//    digitalWrite(led2,HIGH);
//  }
//  
//  if (distance >= 200 || distance <= 0){
//    Serial.println("Out of range");
//  }
//  else {
//    Serial.print(distance);
//    Serial.println(" cm");
//  }
//  delay(50);

//char hello[13] = "hello world!";

String str = String(231231);


//int str_len = distance.length() + 1; 

char char_array[10];

// Copy it over 
str.toCharArray(char_array, 15);

//stringOne = stringOne.toCharArray(distance, 50) ;


  //////
  
  str_msg.data = char_array;
  chatter.publish( &str_msg );
  nh.spinOnce();
  delay(1000);
}

