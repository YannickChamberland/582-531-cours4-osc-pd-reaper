#include <Arduino.h>
#define MA_BROCHE_BOUTON 39 
#define MA_BROCHE_ANGLE 32 
#include <MicroOscSlip.h>
#include <FastLED.h>
  CRGB monPixel;
// Le nombre 128 entre les < > ci-dessous est le nombre maximal d'octets réservés pour les messages entrants.
// Les messages sortants sont écrits directement sur la sortie et ne nécessitent pas de réservation d'octets supplémentaires.
MicroOscSlip<128> monOsc(&Serial);


void setup() {
pinMode( MA_BROCHE_BOUTON , INPUT );
Serial.begin(115200);
FastLED.addLeds<WS2812,27,GRB>( & monPixel, 1 );
}

void loop() {
  int maLectureBouton = digitalRead( MA_BROCHE_BOUTON );
  int maLectureAnalogique = analogRead(MA_BROCHE_ANGLE);
  int purple = millis() % 255;
  /*Serial.print(maLectureBouton);
  Serial.println();*/
  monOsc.sendInt("/bouton"  , maLectureBouton );
  delay(100);
  monOsc.sendInt("/angle", maLectureAnalogique);
  monPixel = CRGB(purple,0,purple);
  FastLED.show();
}