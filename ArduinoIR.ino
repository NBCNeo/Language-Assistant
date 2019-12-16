#include <IRremote.h> // Imports the library to use IR remote

int led = 13; // LED to signal the button press in remote
int pin_rec = 4; // The pin receives the button press signals

IRrecv irrecv(pin_rec);
decode_results results; // Decodes the result from the IR remote

// Pins for motor A (Front right and rear right)
int enA = 8; // Enable pin for motor A
// Pin to control the state of the power pins of the motor A
int in1 = 12; 
int in2 = 11;

// Pins for motor B (Front left and rear left)
int enB = 7; // Enable pin for motor B
// Pin to control the state of the power pins of the motor B
int in3 = 10;
int in4 = 9;

int buzz = 2; // Setting pin for the buzzer pin

// Setting up the arduino before running the loop
void setup()
{
  
Serial.begin(9600);

pinMode(led,OUTPUT); // Sets the LED to output
digitalWrite(led,LOW); // Sets the LED to low, i.e. turned off

irrecv.enableIRIn(); // Enables the IR input

// Since all the motors are output, we set them as such
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(buzz, OUTPUT); // The buzzer is also the output
}

// The loop function runs over and over again as long as the power of the arduino is turned on.

void loop() 
{
if (irrecv.decode(&results)) // Checks if the button has been pressed, if true moves forward in the loop
{
  
digitalWrite(led,LOW);

irrecv.resume();
// First we need to find the hexadecimal value for the buttons
if (results.value == 0xFF6897) // Checks if the mapped button has been pressed
  {
  // If true, the buzzer turns on and moves forward on the loop
  digitalWrite(buzz, HIGH);
  delay(200);
  digitalWrite(buzz, LOW);
  delay(100);
  digitalWrite(buzz, HIGH);
  delay(200);
  digitalWrite(buzz, LOW);
  }
  
if (results.value == 0xFF18E7) // For the forward movement of the robot
{
 Serial.println("2"); // Prints "2" if the button 2 is pressed

  //For motor A
  // Turns on the motors on the forward direction and sets the speed to 200
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 200);
  
  // For motor B
  // Turns on the motors on the forward direction and sets the speed to 200
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 200);

}

else if(results.value == 0xFF10EF) // For the left movement of the robot 
{
  
  Serial.println("4"); // Prints "4" if the button 4 is pressed
  
  // For motor A
  // Turns on the motors on the forward direction and sets the speed to 200
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 200);
  
  // For motor B
  // Turns off the motor
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 200);
}

else if(results.value == 0xFF30CF) // For the rotational movement of the robot clockwise 
{
  
  Serial.println("Right"); // Prints "Right" if the button is pressed
  
  // For motor A
  // Turns on the motors on the forward direction and sets the speed to 200
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 200);
  
  // For motor B
  // Turns on the motors on the backward direction and sets the speed to 200
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 200);
  
}

else if(results.value == 0xFF5AA5) // For the rotational movement of the robot to the left
{ 

 Serial.println("Left"); // Prints "Left" if the button is pressed
 
  // For motor A
  // Turns off the two motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 200);
  
  // For motor B
  // Turns on the motors on the forward direction and sets the speed to 200  
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 200);

}

else if(results.value == 0xFF7A85)
{ 

  // For motor A
  // Turns on the motors on the backward direction and sets the speed to 200
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 200);
  
  // For motor B
  // Turns on the motors on the forward direction and sets the speed to 200  
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 200);

} 

else if(results.value == 0xFF4AB5)
{

  // For motor A
  // Turns on the motors on the backward direction and sets the speed to 200
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 200);
  
  // For motor B
  // Turns on the motors on the backward direction and sets the speed to 200  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 200);

}

else if(results.value == 0xFF38C7)
{

  // For motor A
  // Turns off the motor
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 200);
  
  // For motor B
  // Turns off the motor
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 200);
}
}
}
