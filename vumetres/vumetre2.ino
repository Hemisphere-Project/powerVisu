
void showValueStrip2(String type, int val){

  int valPX = (val-data2Min)*NUMPIXELS/(data2Max-data2Min);

  //ALL OFF
  for(int i=0;i<NUMPIXELS;i++){
    strip2.setPixelColor(i, strip2.Color(0,0,0));
  }
  // VU TYPES:
  //ALL GREEN
  if (type=="allG"){
    for(int i=0;i<valPX;i++){
      strip2.setPixelColor(i, strip2.Color(0,lightMax,0));
    }
  }
  //ALL GREEN TO RED
  if (type=="allG2R"){
    for(int i=0;i<valPX;i++){
      strip2.setPixelColor(i, strip2.Color(i*lightMax/NUMPIXELS,lightMax-i*lightMax/NUMPIXELS,0));
    }
  }
  //ONE GREEN
  if (type=="oneG"){
    strip2.setPixelColor(valPX, strip2.Color(0,lightMax,0));
  }
  //ONE GREEN TO RED
  if (type=="oneG2R"){
    strip2.setPixelColor(valPX, strip2.Color(valPX*lightMax/NUMPIXELS,lightMax-valPX*lightMax/NUMPIXELS,0));
  }

}
