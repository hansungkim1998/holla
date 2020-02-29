#include <Adafruit_DotStar.h>
#include <SPI.h>

#define NUMPIXELS 58
#define DATAPIN 4
#define CLOCKPIN 5

#define SOUND1 A0
#define SOUND2 A1

Adafruit_DotStar strip(NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_BRG);
int p1;
int p2;
int rate;
uint32_t green;
uint32_t blue;
uint32_t blank;
float sound1;
float sound2;

void setup() {
  pinMode(SOUND1, INPUT);
  pinMode(SOUND2, INPUT);
  
  initialize();
  Serial.begin(9600);
}

void initialize() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  p1 = 0;
  p2 = NUMPIXELS;
  green = strip.Color(255, 0, 0);
  blue = strip.Color(0, 0, 255);
  blank = strip.Color(0, 0, 0);
  rate = 80;
  sound1 = 0;
  sound2 = NUMPIXELS;
}

void loop() {
  strip.fill(blank, 0, NUMPIXELS);
  strip.show();
  delay(1000);
  
  // Main game
  while (p1 < NUMPIXELS-1 && p2 > 0) {
    //Serial.println(p1);
    sound1 = analogRead(SOUND1);
    sound2 = analogRead(SOUND2);
    Serial.println(sound1);
    Serial.println(sound2);
    Serial.println("--------------------");

    if (p1 == p2) {
      p1 += (int) ((sound1-sound2)/rate);
      p2 = p1;
    } else {
      p1 += (int)(sound1/rate);
      p2 += (-1) * (int)(sound2/rate);

      if (p1 > p2) {
        int temp = (p1+p2)/2;
        p1 = temp;
        p2 = temp;
      }
    }

    strip.fill(blank, 0, NUMPIXELS);
    colorPlayer1();
    colorPlayer2();
    strip.show();

    delay(100);
  }

  // Game over
  if (p1 >= NUMPIXELS-1) { // Player 1 wins
    for (int i = 0; i < 5; i++) {
      colorPlayer1();
      strip.show();
      delay(500);
      strip.fill(blank, 0, NUMPIXELS);
      strip.show();
      delay(500);
    }
  } else { // Player 2 wins
    for (int i = 0; i < 5; i++) {
      colorPlayer2();
      strip.show();
      delay(500);
      strip.fill(blank, 0, NUMPIXELS);
      strip.show();
      delay(500);
    }
  }

  // Reset game
  delay(5000);
  initialize();
}

void colorPlayer1() {
  if (p1 != 0) {
    strip.fill(green, 0, p1);
  }
}

void colorPlayer2() {
  if (p2 != NUMPIXELS) {
    strip.fill(blue, p2, NUMPIXELS-p2);
  }
}
