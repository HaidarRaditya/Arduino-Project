#include "pitches.h"

int melody[] = {
  NOTE_C4, NOTE_C3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

void setup() {
  // put your setup code here, to run once:
  for (int thisNote = 0; thisNote < 8; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];

    tone(13, melody[thisNote, noteDuration], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);

    noTone(13);
  }

}

void loop() {
  // put your main code here, to run repeatedly:

}
