/*
  Firmware for the Neerer volume control. 

  Turning the knob increases or decreases the volume.
  Pushing the knob starts or stops the music. 
*/

#include "Keyboard.h"
#include <Encoder.h>
#include <Bounce.h>

#define BUTTON 2
#define ENCODER_A 5
#define ENCODER_B 6


Encoder myEnc(ENCODER_A, ENCODER_B);
Bounce bouncer = Bounce( BUTTON,5 );


void setup() {
  Keyboard.begin();
  pinMode(BUTTON,INPUT);
}

void loop() {
  bouncer.update();
  static bool bounce_old = true;
  bool bounce_new = bounce.read();
  
  long newPosition = myEnc.read();
  if(newPosition < oldPosition){
    Keyboard.press(KEY_MEDIA_VOLUME_DEC);
    Keyboard.release(KEY_MEDIA_VOLUME_DEC);
  } else if(newPosition > oldPosition){
    Keyboard.press(KEY_MEDIA_VOLUME_INC);
    Keyboard.release(KEY_MEDIA_VOLUME_INC);
  }

  if (bounce_new !=bounce_old && bounce_new){
    Keyboard.press(KEY_MEDIA_PLAY_PAUSE);
    Keyboard.release(KEY_MEDIA_PLAY_PAUSE);
  }
  
}
