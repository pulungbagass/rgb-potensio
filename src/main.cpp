#include <Arduino.h>
const int potPin = 34;

// RGB pins
const int redPin = 25;
const int greenPin = 26;
const int bluePin = 27;

const int freq = 10000;
const int resolution = 8;

const int redChannel = 0;
const int greenChannel = 1;
const int blueChannel = 2;

void setColor(int r, int g, int b) {
  ledcWrite(redChannel, r);
  ledcWrite(greenChannel, g);
  ledcWrite(blueChannel, b);
}

void setup() {
  ledcSetup(redChannel, freq, resolution);
  ledcSetup(greenChannel, freq, resolution);
  ledcSetup(blueChannel, freq, resolution);

  ledcAttachPin(redPin, redChannel);
  ledcAttachPin(greenPin, greenChannel);
  ledcAttachPin(bluePin, blueChannel);
}

void loop() {
  int potValue = analogRead(potPin);

  // smoothing biar gak noise
  static int smooth = 0;
  smooth = (smooth * 0.8) + (potValue * 0.2);

  int val = map(smooth, 0, 4095, 0, 255);

  int r, g, b;

  if (val < 128) {
    // warm zone (merah → kuning)
    r = 255;
    g = val * 2;
    b = 0;
  } else {
    // cool zone (kuning → biru)
    val -= 128;
    r = 255 - val * 2;
    g = 255 - val * 2;
    b = val * 2;
  }

  setColor(r, g, b);

  delay(10);
}