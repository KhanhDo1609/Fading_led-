const int ledPin = 9; 

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  unsigned long cycleTime = millis() % 4500; /*The circle is 4500 ms totally
											                       2000ms Fade from off to full brightness
                                             2000ms Fade from full brightness to off
                                             500ms Staying off before the next loop*/
                                          
  int brightness;

  if (cycleTime < 2000) {
    // Fade from off to full brightness over 2 seconds.
    brightness = map(cycleTime, 0, 2000, 0, 255);
  } else if (cycleTime < 4000) {
    // Fade back to off over 2 seconds.
    brightness = map(cycleTime, 2000, 4000, 255, 0);
  } else {
    // Stay off for half a second.
    brightness = 0;
  }

  analogWrite(ledPin, brightness);
  delay(5);
}