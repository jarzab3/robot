/*
 * rosserial Publisher Example
 * Prints "hello world!"
 */

#if defined(ARDUINO) && ARDUINO >= 100
#include <Arduino.h>
#else
 #include <WProgram.h>
#endif

#include <Servo.h> 
#include <ros.h>
#include <std_msgs/UInt16.h>

#include <std_msgs/String.h>

Servo servo;

void servo_cb( const std_msgs::UInt16& cmd_msg){
  servo.write(cmd_msg.data); //set servo angle, should be from 0-180  
  digitalWrite(13, HIGH-digitalRead(13));  //toggle led  
}

ros::NodeHandle  nh;

std_msgs::String str_msg;

ros::Publisher chatter("chatter", &str_msg);

ros::Subscriber<std_msgs::UInt16> sub("servo", servo_cb);

void setup()
{
  
  nh.initNode();
  nh.advertise(chatter);
  
  nh.subscribe(sub);
  
  servo.attach(9); //attach it to pin 9

}

void loop()
{

  String str = String(servo.read());

  char char_array[10];

  str.toCharArray(char_array, 15);
  
  str_msg.data = char_array;

  chatter.publish( &str_msg );

  nh.spinOnce();
  delay(1000);

}

