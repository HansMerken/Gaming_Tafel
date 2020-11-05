
// - : minder helder 0xFFE01F
//+ : helderder 0xFFA857
//5: alles aan, wit 0xFF38C7
//0: RGB feestje 0xFF6897

// 1 minder R 0xFF30CF
// 3 meer R 0xFF7A85
// 4: minder G 0xFF10EF
// 6: meer G 0xFF5AA5
// 7: minder B 0xFF42BD
// 9: meer B 0xFF52AD


//Pot om de helderheid te controleren
//Knop voor de modus
//Pot voor het aantal spelers + biep

//modi:
//  RGB rainbow scroll - pot voor snelheid
//  Wit
//  aantal spelers, ieder een kleur - pot voor aantal
//  subtiel veranderen van kleur

//rapport via Serial

//test Git

//=======================================
// --------- HEADER -----------------

#include "defcolors.h"

// --------- LIBRARIES -----------------

#include <Adafruit_NeoPixel.h>

// --------- CONSTANTS -----------------
// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        3 // On Trinket or Gemma, suggest changing this to 1
// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 150 // Popular NeoPixel ring size
#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels
int sensorPin = A0;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor
int adaptPin = A1;    // select the input pin for the potentiometer
int adaptValue = 0;  // variable to store the value coming from the sensor
const int buttonPin = 2;    // the number of the pushbutton pin

const int ledPin = 13;      // the number of the LED pin

int sixplace[] = { 0, 1, 18, 36, 54, 74, 92, 110, 128,129,149,150 }; //led numbers for six places
int eightplace[] = { 0, 12, 26, 40, 54, 74, 88, 102 , 116,129,149,150 }; //led numbers for eight places


// --------- OBJECTS -----------------

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


// --------- VARIABLES -----------------

int red = 255;
int green = 255;
int blue = 255;
uint8_t brightness = 255;
unsigned long currentMillis = 0;
int numplayers = 2;
int mode = 0;
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin
int ledState = HIGH;         // the current state of the output pin

int pixperplayer;
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

//=======================================

void setup() {
  Serial.begin(115200);
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);

  // set initial LED state
  digitalWrite(ledPin, ledState);
  Serial.println("Setup Done");
  int noteDuration = 1000 / 4;

  tone(8, 262, noteDuration);
  int pauseBetweenNotes = noteDuration * 1.30;

  // delay(pauseBetweenNotes);
  // stop the tone playing:
  //  noTone(8);
    pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)

}


//=======================================

void loop() {
  // put your main code here, to run repeatedly:
  //  currentMillis = millis();
  //  neoPixel();
  brightness = analogRead(sensorPin)/4;
  adaptValue = analogRead(adaptPin);
  pixels.setBrightness(brightness);
  report();
  //
  checkButton();
  switch (mode) {
    case 0: //RGB
        modeRGB();
        break;
    case 1: //Wit
      break;
    case 2: //Spel
      modeSpelers();
      break;
    case 3: //Subtiel
      break;
    case 4: //reset
      mode = 0;
      break;
  }

}

//=======================================

void report()
{
  Serial.print("Brightness: ");
  Serial.println(brightness);

  Serial.print("Number of Players: ");
  Serial.println(numplayers);

  Serial.print("Mode: ");
  Serial.println(mode);

}
//=======================================

void checkButton()
{
  // read the state of the switch into a local variable:
  int reading = digitalRead(buttonPin);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;

      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) {
        Serial.println("poeng");
        mode++;
        switch (mode) {
          case 0: //RGB
            tone(8, 65, 250);
            break;
          case 1: //Wit
            tone(8, 262, 250);
            break;
          case 2: //Spel
            tone(8, 1047, 250);
            break;
          case 3: //Subtiel
            tone(8, 4186, 250);
            break;
        }
      }
    }
  }



  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState = reading;

}
//=======================================

void neoPixel()
{
  pixels.clear(); // Set all pixel colors to 'off'

  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  for (int i = 0; i < NUMPIXELS; i++) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.setPixelColor(i, pixels.Color(0, 150, 0));

    pixels.show();   // Send the updated pixel colors to the hardware.

    delay(DELAYVAL); // Pause before next pass through loop
  }
}

//=======================================

void modeRGB()
{

}


//=======================================

void modeWit()
{
    pixels.clear(); // Set all pixel colors to 'off'

  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
    for (int i = 0; i < NUMPIXELS; i++) { // For each pixel...

      // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
      // Here we're using a moderately bright green color:
        pixels.setPixelColor(i, pixels.Color(255, 255, 255));

        
    }
    pixels.show();   // Send the updated pixel colors to the hardware.


}


//=======================================

void modeSpelers()
{
  // aantal spelers instellen
  numplayers = (adaptValue / 120) + 2 ; // between 2 and 10
  // aantal pixels delen door aantal spelers = pixels per speler
  pixperplayer = NUMPIXELS / numplayers;
  //for loop for color

  for (int j = 1; j < 10; j++) { //for each player
      if (numplayers<9){
          for (int i = sixplace[j]; i < sixplace[j+1]; i++) { // For each pixel...

            // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255

             
                  pixels.setPixelColor(i, pixels.Color(playerColors[numplayers][j][0], playerColors[numplayers][j][1], playerColors[numplayers][j][2]));
           
              }
		  } else{

          for (int i = eightplace[j]; i < eightplace[j + 1]; i++) { // For each pixel...

            // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255


              pixels.setPixelColor(i, pixels.Color(playerColors[numplayers][j][0], playerColors[numplayers][j][1], playerColors[numplayers][j][2]));


          }
      

      }
  }
  pixels.show();   // Send the updated pixel colors to the hardware.

}


//=======================================

void modeSubtiel()
{

}
