
void showValueStrip1(String type, int val){

  int valPX = (val-data1Min)*NUMPIXELS_STRIP1/(data1Max-data1Min);

  //ALL OFF
  for(int i=0;i<NUMPIXELS_STRIP1;i++){
    strip1.setPixelColor(i, strip1.Color(0,0,0));
  }
  // VU TYPES:
  //ALL GREEN
  if (type=="allG"){
    for(int i=0;i<valPX;i++){
      strip1.setPixelColor(i, strip1.Color(0,lightMax,0));
    }
  }
  //ALL GREEN TO RED
  if (type=="allG2R"){
    for(int i=0;i<valPX;i++){
      strip1.setPixelColor(i, strip1.Color(i*lightMax/NUMPIXELS_STRIP1,lightMax-i*lightMax/NUMPIXELS_STRIP1,0));
    }
  }
  //ONE GREEN
  if (type=="oneG"){
    strip1.setPixelColor(valPX, strip1.Color(0,lightMax,0));
  }
  //ONE GREEN TO RED
  if (type=="oneG2R"){
    strip1.setPixelColor(valPX, strip1.Color(valPX*lightMax/NUMPIXELS_STRIP1,lightMax-valPX*lightMax/NUMPIXELS_STRIP1,0));
  }

}
