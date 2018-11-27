
// SMOOTHING
int in3Smoothing(int input){

  in3Total = in3Total - in3Raw[in3Index];
  in3Raw[in3Index] = analogRead(INPIN3);
  in3Total = in3Total + in3Raw[in3Index];
  in3Index = in3Index + 1;
  if (in3Index >= numAvg3) { in3Index = 0; }
  int in3Smooth = in3Total / numAvg3;
  return in3Smooth;
}


// SHOWING
void showValueStrip3(String type, int val){

  int valPX = (val-data3Min)*NUMPIXELS_STRIP3/(data3Max-data3Min);

  //ALL OFF
  for(int i=0;i<NUMPIXELS_STRIP3;i++){
    strip3.setPixelColor(i, strip3.Color(0,0,0));
  }
  // VU TYPES:
  //ALL GREEN
  if (type=="allG"){
    for(int i=0;i<valPX;i++){
      strip3.setPixelColor(i, strip3.Color(0,lightMax,0));
    }
  }
  //ALL GREEN TO RED
  if (type=="allG2R"){
    for(int i=0;i<valPX;i++){
      strip3.setPixelColor(i, strip3.Color(i*lightMax/NUMPIXELS_STRIP3,lightMax-i*lightMax/NUMPIXELS_STRIP3,0));
    }
  }
  //ONE GREEN
  if (type=="oneG"){
    strip3.setPixelColor(valPX, strip3.Color(0,lightMax,0));
  }
  //ONE GREEN TO RED
  if (type=="oneG2R"){
    strip3.setPixelColor(valPX, strip3.Color(valPX*lightMax/NUMPIXELS_STRIP3,lightMax-valPX*lightMax/NUMPIXELS_STRIP3,0));
  }

}
