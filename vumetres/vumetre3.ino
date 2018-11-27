
void showValueStrip3(String type, int val){

  int valPX = (val-data3Min)*NUMPIXELS/(data3Max-data3Min);

  //ALL OFF
  for(int i=0;i<NUMPIXELS;i++){
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
      strip3.setPixelColor(i, strip3.Color(i*lightMax/NUMPIXELS,lightMax-i*lightMax/NUMPIXELS,0));
    }
  }
  //ONE GREEN
  if (type=="oneG"){
    strip3.setPixelColor(valPX, strip3.Color(0,lightMax,0));
  }
  //ONE GREEN TO RED
  if (type=="oneG2R"){
    strip3.setPixelColor(valPX, strip3.Color(valPX*lightMax/NUMPIXELS,lightMax-valPX*lightMax/NUMPIXELS,0));
  }

}
