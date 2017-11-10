/*
 * rosserial Publisher Example
 * Prints "hello world!"
 */

 #if defined(ARDUINO) && ARDUINO >= 100
#include <Arduino.h>
#else
 #include <WProgram.h>
#endif

#include <ros.h>
#include <std_msgs/String.h>

#include <std_msgs/Int16.h>
#include <std_msgs/UInt16.h>

#define trigPin 7
#define echoPin 8

#include <Servo.h> 

ros::NodeHandle  nh;

std_msgs::Int16 out_dist;

Servo servo;

void servo_cb( const std_msgs::UInt16& cmd_msg){
  servo.write(cmd_msg.data); //set servo angle, should be from 0-180
}

ros::Subscriber<std_msgs::Int16> sub("servo", servo_cb);

ros::Publisher chatter("arduino1", &out_dist);



void setup()
{
  nh.initNode();
  nh.advertise(chatter);
  
//  Serial.begin (9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  nh.subscribe(sub);
  
  servo.attach(9); //attach it to pin 9

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
  
  out_dist.data = distance *10;

  chatter.publish( &out_dist );

  ros::Subscriber<std_msgs::UInt16> sub("servo", servo_cb);

  nh.spinOnce();
  delay(1000);
  
}

