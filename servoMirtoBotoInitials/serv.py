import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)
GPIO.setup(18, GPIO.OUT)
pwm = GPIO.PWM(18, 100)
pwm.start(5)

def SetAngle(angle, duration):
	duty = angle / 18 + 2
	GPIO.output(18, True)
	pwm.ChangeDutyCycle(duty)
	time.sleep(1)
	GPIO.output(18, False)
	pwm.ChangeDutyCycle(0)
	time.sleep(duration)

d = 180
u = 0

SetAngle(d, 6)

SetAngle(d, 8)

SetAngle(u, 4.5) 
#Drive through A
SetAngle(d, 3.5)
 
SetAngle(u, 7)

SetAngle(d, 8)

SetAngle(u, 0.1)

pwm.stop()

GPIO.cleanup()

