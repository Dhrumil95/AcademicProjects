/* 

Dhrumil 

Project Video : https://www.youtube.com/watch?v=GUST0R2dywI

*/

/***** Library Declaration *******/
#include <math.h>
#include <SoftwareSerial.h>

/****** SoftwareSerial declarations for sending and receiving characters ******/
SoftwareSerial sendSerial(0,1);
SoftwareSerial receiveSerial(0,1);

/**** Initializing the pins and SoftwareSerial vars ******/
void setup() {
  sendSerial.begin(19200);
  receiveSerial.begin(57600);
  pinMode(2,INPUT);            // Push Button Input
  pinMode(8,OUTPUT);       // Dc Motor Output
}

/***** loop function - runs the code over and over again ********/
void loop() {
/* First of all checks if the pre (Ultrasonic) arduino is sending signal */
  if(receiveSerial.available() > 0)  // if character is received
  switch( receiveSerial.read() )  { 
  case 'u':
  sendSerial.write('u');             // Writes/Sends the ‘u’ to another Arduino to read
   break;
 }
/* stores the value returned from tempRet function in temp var */
  float temp = tempRet(analogRead(A0));    // Stores the values in temp var
/* Follows the algorithm described above */ 
 if (temp >= 47 ) {
    sendSerial.write('h');              // Writes/Sends the ‘h’ to another Arduino to read
    digitalWrite(8,LOW);          // Turn the DC motor On
  }
  else digitalWrite(8,HIGH);  // Turn the DC motor Off

/* Implementation of Push Button */
 int buttonState = digitalRead(2);  // Reads state of button and stores it in Button State
 if (buttonState == HIGH)   // if Button was pressed
      sendSerial.write('c');  // Send Signal to call emergency Contact
  delay(2000);    // Delay two seconds for consistent and accurate values.
}
/***** Function to convert Thermistor Resistance to Celsius Temperature ***/
float tempRet(int thermVal) {
  long logR;  
  float convC;
  logR = 9850 * ((1024.0 / thermVal) - 1); 
  convC = log(logR); 
  convC = 1 / (0.001129148 + (0.000234125 * convC) + (0.0000000876741 * convC * convC * convC));
  convC = convC - 273.15;                  
  return convC;                                     
}

