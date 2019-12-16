# ArduinoIR
<h2>Building prototype for the mobile robot</h2>
<p>4WD robot controlled with IR remote and option for autonomous movement with ultrasonic sensor
</p>

<h2> Tools used: </h2>

1. Arduino UNO
2. Motor Board (L298N)
3. Tower Pro Micro Servo
4. DC Motors
5. Car base and Wheel set
6. IR sensor and remote
7. Ultrasonic sensor (HC-SR04)
8. Jumper Cables (Male to female, female to female, male to male)
9. Battery Set
10. Arduino Sensor Shield (v4)
11. Buzzer
<p>
The robot can be controlled using IR remote with the function of moving in all directions and controlling the buzzer. It is also capable of running on its own since it has been connected with ultrasonic sensor, depending on the code that is installed in the Arduino. A camera can easily be attached in the future along with a Raspberry Pi. They can either be attached externally alongside Arduino or Raspberry Pi can also be used for movement of the robot and be made to follow objects.
</p>
<p>
PiTextReader is an already existing framework to convert images to speech. The complete tutorial is given: https://github.com/rgrokett/PiTextReader
  </p>
  <p>
With this, we can attach a camera in the robot and face it towards any object with text and directly convert it to speech locally. The downsides are that the speech is very robotic which is tackled by the other part of our project.
So, there is another option. We can use OpenCV to recognize the text and use Tesseract to convert it to text. Then, we can feed the text into any Text-to-Speech (TTS) speech to convert it into speech.
  </p>
  <p>
The biggest challenge is going to be the integration of the autonomous movement of the robot and its ability to locate the text. For this, we can use OpenCV to detect the object and once it is able to detect, we can make a simple object following robot where the ultrasonic sensor will prevent the collision to any objects in the field.
  <p>

<h2>Challenges</h2>

https://www.instructables.com/id/Automatic-Vision-Object-Tracking/
- To create a stable model that can detect text with the help of a camera. Since, the surface in which the text might be written in can come in different forms and colors, using a contrasting color to locate the text will not work. So, we need a model that can detect text, move in the right field of view and take pictures which can then be processed using OCR.
- Integrating the Raspberry Pi’s camera for both movement of the robot and object detection. To avoid the collision of objects, we can also use ultrasonic sensor, but if we want to use camera for it, the processing power might not be enough using Raspberry Pi.

<h2> Steps </h2>
<p>
1. Upload the code to the Arduino.
2. Make the connections as shown in the circuit diagram.
  </p>
