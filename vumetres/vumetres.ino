// Using Adafruit NeoPixel Lib

// ! CH340 driver for mac : Avoid crash --> Install v1.4 found on github
// https://forum.arduino.cc/index.php?topic=428325.0
// https://github.com/adrianmihalko/ch340g-ch34g-ch34x-mac-os-x-driver

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

///////////////////////// OUTPUTS /////////////////////////

// !! STRIP COURTE NUMPIXELS 30
// !! STRIP LONGUE NUMPIXELS 87

// STRIP 1
#define OUTPIN1            5
#define NUMPIXELS_STRIP1   30
Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(NUMPIXELS_STRIP1, OUTPIN1, NEO_GRB + NEO_KHZ800);
// STRIP 2
#define OUTPIN2            6
#define NUMPIXELS_STRIP2   30
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(NUMPIXELS_STRIP2, OUTPIN2, NEO_GRB + NEO_KHZ800);
// STRIP 3
#define OUTPIN3            7
#define NUMPIXELS_STRIP3   30
Adafruit_NeoPixel strip3 = Adafruit_NeoPixel(NUMPIXELS_STRIP3, OUTPIN3, NEO_GRB + NEO_KHZ800);


// BRIGHTNESS
int lightMax = 150;

///////////////////////// INPUTS /////////////////////////
// INPUT 1
#define INPIN1 A0 // 0-0,2V --
long data1Min = 0;
long data1Max = 614;//5
// INPUT 2
#define INPIN2 A1 //
long data2Min = 10;
long data2Max = 614;
// INPUT 3
#define INPIN3 A2 // PONT DIVISEUR 0-3V
long data3Min = 10;
long data3Max = 614;

/////////////////////// SMOOTHING ///////////////////////
// 1
const int numAvg1 = 20;
int in1Raw[numAvg1];
int in1Index = 0;
int in1Total = 0;
// 2
const int numAvg2 = 20;
int in2Raw[numAvg2];
int in2Index = 0;
int in2Total = 0;
// 3
const int numAvg3 = 20;
int in3Raw[numAvg3];
int in3Index = 0;
int in3Total = 0;

//////////////////////////////////////////////////////////


// DIVERS
long randomValue = 0;
int sens = 1;


///////////////////////// SETUP /////////////////////////
void setup() {

  Serial.begin(9600);

  strip1.begin();
  strip2.begin();
  strip3.begin();

  // init all Smoothing arrays
  for (int i = 0; i < numAvg1; i++) { in1Raw[i] = 0; }
  for (int i = 0; i < numAvg2; i++) { in2Raw[i] = 0; }
  for (int i = 0; i < numAvg3; i++) { in3Raw[i] = 0; }

}


///////////////////////// LOOP /////////////////////////

void loop() {

  // randomValue=randomValue+sens*6;
  // if ((randomValue>600)||(randomValue<0)){ sens = -1*sens; }

  // int in1 = analogRead(INPIN1);
  // int in2 = analogRead(INPIN2);
  // int in3 = analogRead(INPIN3);

  int in1Smoothed = in1Smoothing( analogRead(INPIN1) );
  int in2Smoothed = in2Smoothing( analogRead(INPIN2) );
  int in3Smoothed = in3Smoothing( analogRead(INPIN3) );

  // Serial.print(analogRead(INPIN1));
  // Serial.print(" ");
  // Serial.print(analogRead(INPIN2));
  // Serial.print(" ");
  // Serial.print(analogRead(INPIN3));
  // Serial.print(" ----> ");
  // Serial.print(in1Smoothed);
  // Serial.print(" ");
  // Serial.print(in2Smoothed);
  // Serial.print(" ");
  // Serial.println(in3Smoothed);

  showValueStrip1("allG2R", in1Smoothed);
  showValueStrip2("allG2R", in2Smoothed);
  showValueStrip3("allG2R", in3Smoothed);

  // showValueStrip1("allG2R", randomValue);
  // showValueStrip2("allG2R", randomValue);
  // showValueStrip3("allG2R", randomValue);

  // Update
  strip1.show();
  strip2.show();
  strip3.show();

  delay(1);

}
