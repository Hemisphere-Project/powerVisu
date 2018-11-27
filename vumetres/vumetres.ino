// Using Adafruit NeoPixel Lib

// ! CH340 driver for mac : Avoid crash --> Install v1.4 found on github
// https://forum.arduino.cc/index.php?topic=428325.0
// https://github.com/adrianmihalko/ch340g-ch34g-ch34x-mac-os-x-driver


#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN1            5
#define PIN2            6
#define PIN3            7
#define NUMPIXELS      30
Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(NUMPIXELS, PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(NUMPIXELS, PIN2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip3 = Adafruit_NeoPixel(NUMPIXELS, PIN3, NEO_GRB + NEO_KHZ800);

// BRIGHTNESS
int lightMax = 40;
// DATA ZONES
int data1Min = 10;
int data1Max = 50;
int data2Min = 10;
int data2Max = 50;
int data3Min = 10;
int data3Max = 50;

// DIVERS
int randomValue = 0;
int sens = 1;


void setup() {
  // Serial.begin(9600);
  strip1.begin();
  strip2.begin();
  strip3.begin();
}


void loop() {
  randomValue=randomValue+sens;
  if ((randomValue>100)||(randomValue<0)){ sens = -1*sens; }

  showValueStrip1("allG2R", randomValue);
  showValueStrip2("oneG2R", randomValue);
  showValueStrip3("allG", randomValue);

  strip1.show();
  strip2.show();
  strip3.show();

  delay(5);
}
