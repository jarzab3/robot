/*
 * rosserial Publisher Example
 * Prints "hello world!"
 */

#include <ros.h>
#include <std_msgs/String.h>

#include <std_msgs/Int16.h>

#define trigPin 7
#define echoPin 8

ros::NodeHandle  nh;

//std_msgs::String str_msg;

std_msgs::Int16 str_msg;



ros::Publisher chatter("chatter", &str_msg);

void setup()
{
  nh.initNode();
  nh.advertise(chatter);
  
//  Serial.begin (9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop()
{

  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;

String str = String(distance);

//int str_len = distance.length() + 1; 

char char_array[10];

str.toCharArray(char_array, 15);

//stringOne = stringOne.toCharArray(distance, 50) ;

  str_msg.data = char_array;
  chatter.publish( &str_msg );
  nh.spinOnce();
  delay(1000);
  
}

