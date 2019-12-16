int buzzer = 8;
 
void setup() {
 
}
 
void loop() {

tone(buzzer, 1000); // tone() is the main function to use with a buzzer, it takes 2 or 3 parameteres (buzzer pin, sound frequency, duration)
 delay(1000);
 tone(buzzer, 2000); // You can also use noTone() to stop the sound it takes 1 parametere which is the buzzer pin
 delay(1000);
 
}
