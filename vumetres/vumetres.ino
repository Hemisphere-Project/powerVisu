// Using Adafruit NeoPixel Lib

// ! CH340 driver for mac : Avoid crash --> Install v1.4 found on github
// https://forum.arduino.cc/index.php?topic=428325.0
// https://github.com/adrianmihalko/ch340g-ch34g-ch34x-mac-os-x-driver

// TODO : showVuMetre(Adafruit_NeoPixel vuMetreI, String type, int val) POSSIBLE ??
// Or conditions if vumetre1, 2, 3, etc ?

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN1            5
#define PIN2            6
#define PIN3            7
#define NUMPIXELS      30
Adafruit_NeoPixel vuMetre1 = Adafruit_NeoPixel(NUMPIXELS, PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel vuMetre2 = Adafruit_NeoPixel(NUMPIXELS, PIN2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel vuMetre3 = Adafruit_NeoPixel(NUMPIXELS, PIN3, NEO_GRB + NEO_KHZ800);

int lightMax = 40;
int randomValue = 0;
int maxValue = 100;
// DIVERS
int sens = 1;


void setup() {
  // Serial.begin(9600);
  vuMetre1.begin();
}

void showVuMetre(String type, int val){

  int valPX = val*NUMPIXELS/maxValue;
  //ALL OFF
  for(int i=0;i<NUMPIXELS;i++){
    vuMetre1.setPixelColor(i, vuMetre1.Color(0,0,0));
  }
  // VU TYPES:
  //ALL GREEN
  if (type=="allG"){
    for(int i=0;i<valPX;i++){
      vuMetre1.setPixelColor(i, vuMetre1.Color(0,lightMax,0));
    }
  }
  //ALL GREEN TO RED
  if (type=="allG2R"){
    for(int i=0;i<valPX;i++){
      vuMetre1.setPixelColor(i, vuMetre1.Color(i*lightMax/NUMPIXELS,lightMax-i*lightMax/NUMPIXELS,0));
    }
  }
  //ONE GREEN
  if (type=="oneG"){
    vuMetre1.setPixelColor(valPX, vuMetre1.Color(0,lightMax,0));
  }
  //ONE GREEN TO RED
  if (type=="oneG2R"){
    vuMetre1.setPixelColor(valPX, vuMetre1.Color(valPX*lightMax/NUMPIXELS,lightMax-valPX*lightMax/NUMPIXELS,0));
  }

}

void loop() {
  randomValue=randomValue+sens;
  if ((randomValue>maxValue)||(randomValue<0)){ sens = -1*sens; }

  showVuMetre("allG2R", randomValue);

  vuMetre1.show();
  vuMetre2.show();
  vuMetre3.show();

  delay(5);
}
