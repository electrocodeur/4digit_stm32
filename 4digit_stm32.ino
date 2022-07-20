#include <DHT.h>;

#define DHT11_PIN PB1
#define DHTTYPE DHT11

DHT dht(DHT11_PIN, DHTTYPE);

int temp, hum;

byte segA = PA0; //Display pin 11
byte segB = PA1; //Display pin 7
byte segC = PA2; //Display pin 4
byte segD = PA3; //Display pin 2
byte segE = PA4; //Display pin 1
byte segF = PA5; //Display pin 10
byte segG = PA6; //Display pin 5
byte digit1 = PB12;
byte digit2 = PB13;
byte digit3 = PB14;
byte digit4 = PB15;

void setup() {
  dht.begin();
  pinMode(segA, OUTPUT);
  pinMode(segB, OUTPUT);
  pinMode(segC, OUTPUT);
  pinMode(segD, OUTPUT);
  pinMode(segE, OUTPUT);
  pinMode(segF, OUTPUT);
  pinMode(segG, OUTPUT);
  pinMode(digit1, OUTPUT);
  pinMode(digit2, OUTPUT);
  pinMode(digit3, OUTPUT);
  pinMode(digit4, OUTPUT);
}
void loop() {
  temp = dht.readTemperature();
  hum = dht.readHumidity();

  for (int i = 0; i < 4000; i++) {
    temp = dht.readTemperature();
    hum = dht.readHumidity();
    degres(temp);
  }
  for (int i = 0; i < 4000; i++) {
    temp = dht.readTemperature();
    hum = dht.readHumidity();
    humidite(hum);
  }

}
void degres(int toDisplay) {
#define DISPLAY_BRIGHTNESS  750

#define DIGIT_ON  1   //ANODE = 1; CATHODE = 0;
#define DIGIT_OFF 0   //ANODE = 0; CATHODE = 1;

  for (int digit = 4 ; digit > 0 ; digit--) {

    //Turn on a digit for a short amount of time
    switch (digit) {
      case 1:
        digitalWrite(digit1, DIGIT_ON);
        lightNumber(toDisplay % 10); // display degree symbol
        toDisplay /= 10;
        delayMicroseconds(DISPLAY_BRIGHTNESS);
        break;
      case 2:
        digitalWrite(digit2, DIGIT_ON);
        lightNumber(toDisplay % 10); // display degree symbol
        toDisplay /= 10;
        delayMicroseconds(DISPLAY_BRIGHTNESS);
        break;
      case 3:
        digitalWrite(digit3, DIGIT_ON);
        lightNumber(11); // display degree symbol
        //toDisplay /= 10;
        delayMicroseconds(DISPLAY_BRIGHTNESS);
        break;
      case 4:
        digitalWrite(digit4, DIGIT_ON);
        lightNumber(12); // display degree symbol
        //toDisplay /= 10;
        delayMicroseconds(DISPLAY_BRIGHTNESS);
        break;
    }
    //Turn off all segments
    lightNumber(10);

    //Turn off all digits
    digitalWrite(digit1, DIGIT_OFF);
    digitalWrite(digit2, DIGIT_OFF);
    digitalWrite(digit3, DIGIT_OFF);
    digitalWrite(digit4, DIGIT_OFF);

  }
}
void humidite(int toDisplay) {
#define DISPLAY_BRIGHTNESS  750

#define DIGIT_ON  1   //ANODE = 1; CATHODE = 0;
#define DIGIT_OFF 0   //ANODE = 0; CATHODE = 1;

  for (int digit = 4 ; digit > 0 ; digit--) {

    //Turn on a digit for a short amount of time
    switch (digit) {
      case 1:
        digitalWrite(digit1, DIGIT_ON);
        lightNumber(toDisplay % 10); // display degree symbol
        toDisplay /= 10;
        delayMicroseconds(DISPLAY_BRIGHTNESS);
        break;
      case 2:
        digitalWrite(digit2, DIGIT_ON);
        lightNumber(toDisplay % 10); // display degree symbol
        toDisplay /= 10;
        delayMicroseconds(DISPLAY_BRIGHTNESS);
        break;
      case 3:
        digitalWrite(digit3, DIGIT_ON);
        lightNumber(11);
        //toDisplay /= 10;
        delayMicroseconds(DISPLAY_BRIGHTNESS);
        break;
      case 4:
        digitalWrite(digit4, DIGIT_ON);
        lightNumber(13);
        //toDisplay /= 10;
        delayMicroseconds(DISPLAY_BRIGHTNESS);
        break;
    }
    //Turn off all segments
    lightNumber(10);

    //Turn off all digits
    digitalWrite(digit1, DIGIT_OFF);
    digitalWrite(digit2, DIGIT_OFF);
    digitalWrite(digit3, DIGIT_OFF);
    digitalWrite(digit4, DIGIT_OFF);

  }
}
//Given a number, turns on those segments
//If number == 10, then turn off number
void lightNumber(int numberToDisplay) {
  //ANODE = 1; CATHODE = 0;
#define SEGMENT_ON  0 //ANODE = 0; CATHODE = 1;
#define SEGMENT_OFF 1 //ANODE = 1; CATHODE = 0;

  switch (numberToDisplay) {

    case 0:
      digitalWrite(segA, SEGMENT_ON);
      digitalWrite(segB, SEGMENT_ON);
      digitalWrite(segC, SEGMENT_ON);
      digitalWrite(segD, SEGMENT_ON);
      digitalWrite(segE, SEGMENT_ON);
      digitalWrite(segF, SEGMENT_ON);
      digitalWrite(segG, SEGMENT_OFF);
      digitalWrite(13, SEGMENT_OFF);
      break;

    case 1:
      digitalWrite(segA, SEGMENT_OFF);
      digitalWrite(segB, SEGMENT_ON);
      digitalWrite(segC, SEGMENT_ON);
      digitalWrite(segD, SEGMENT_OFF);
      digitalWrite(segE, SEGMENT_OFF);
      digitalWrite(segF, SEGMENT_OFF);
      digitalWrite(segG, SEGMENT_OFF);
      digitalWrite(13, SEGMENT_OFF);
      break;

    case 2:
      digitalWrite(segA, SEGMENT_ON);
      digitalWrite(segB, SEGMENT_ON);
      digitalWrite(segC, SEGMENT_OFF);
      digitalWrite(segD, SEGMENT_ON);
      digitalWrite(segE, SEGMENT_ON);
      digitalWrite(segF, SEGMENT_OFF);
      digitalWrite(segG, SEGMENT_ON);
      digitalWrite(13, SEGMENT_OFF);
      break;

    case 3:
      digitalWrite(segA, SEGMENT_ON);
      digitalWrite(segB, SEGMENT_ON);
      digitalWrite(segC, SEGMENT_ON);
      digitalWrite(segD, SEGMENT_ON);
      digitalWrite(segE, SEGMENT_OFF);
      digitalWrite(segF, SEGMENT_OFF);
      digitalWrite(segG, SEGMENT_ON);
      digitalWrite(13, SEGMENT_OFF);
      break;

    case 4:
      digitalWrite(segA, SEGMENT_OFF);
      digitalWrite(segB, SEGMENT_ON);
      digitalWrite(segC, SEGMENT_ON);
      digitalWrite(segD, SEGMENT_OFF);
      digitalWrite(segE, SEGMENT_OFF);
      digitalWrite(segF, SEGMENT_ON);
      digitalWrite(segG, SEGMENT_ON);
      digitalWrite(13, SEGMENT_OFF);
      break;

    case 5:
      digitalWrite(segA, SEGMENT_ON);
      digitalWrite(segB, SEGMENT_OFF);
      digitalWrite(segC, SEGMENT_ON);
      digitalWrite(segD, SEGMENT_ON);
      digitalWrite(segE, SEGMENT_OFF);
      digitalWrite(segF, SEGMENT_ON);
      digitalWrite(segG, SEGMENT_ON);
      digitalWrite(13, SEGMENT_OFF);
      break;

    case 6:
      digitalWrite(segA, SEGMENT_ON);
      digitalWrite(segB, SEGMENT_OFF);
      digitalWrite(segC, SEGMENT_ON);
      digitalWrite(segD, SEGMENT_ON);
      digitalWrite(segE, SEGMENT_ON);
      digitalWrite(segF, SEGMENT_ON);
      digitalWrite(segG, SEGMENT_ON);
      digitalWrite(13, SEGMENT_OFF);
      break;

    case 7:
      digitalWrite(segA, SEGMENT_ON);
      digitalWrite(segB, SEGMENT_ON);
      digitalWrite(segC, SEGMENT_ON);
      digitalWrite(segD, SEGMENT_OFF);
      digitalWrite(segE, SEGMENT_OFF);
      digitalWrite(segF, SEGMENT_OFF);
      digitalWrite(segG, SEGMENT_OFF);
      digitalWrite(13, SEGMENT_OFF);
      break;

    case 8:
      digitalWrite(segA, SEGMENT_ON);
      digitalWrite(segB, SEGMENT_ON);
      digitalWrite(segC, SEGMENT_ON);
      digitalWrite(segD, SEGMENT_ON);
      digitalWrite(segE, SEGMENT_ON);
      digitalWrite(segF, SEGMENT_ON);
      digitalWrite(segG, SEGMENT_ON);
      digitalWrite(13, SEGMENT_OFF);
      break;

    case 9:
      digitalWrite(segA, SEGMENT_ON);
      digitalWrite(segB, SEGMENT_ON);
      digitalWrite(segC, SEGMENT_ON);
      digitalWrite(segD, SEGMENT_ON);
      digitalWrite(segE, SEGMENT_OFF);
      digitalWrite(segF, SEGMENT_ON);
      digitalWrite(segG, SEGMENT_ON);
      digitalWrite(13, SEGMENT_OFF);
      break;

    // all segment are ON
    case 10:
      digitalWrite(segA, SEGMENT_OFF);
      digitalWrite(segB, SEGMENT_OFF);
      digitalWrite(segC, SEGMENT_OFF);
      digitalWrite(segD, SEGMENT_OFF);
      digitalWrite(segE, SEGMENT_OFF);
      digitalWrite(segF, SEGMENT_OFF);
      digitalWrite(segG, SEGMENT_OFF);
      digitalWrite(13, SEGMENT_OFF);
      break;

    case 11: //°
      digitalWrite(segA, SEGMENT_ON);
      digitalWrite(segB, SEGMENT_ON);
      digitalWrite(segC, SEGMENT_OFF);
      digitalWrite(segD, SEGMENT_OFF);
      digitalWrite(segE, SEGMENT_OFF);
      digitalWrite(segF, SEGMENT_ON);
      digitalWrite(segG, SEGMENT_ON);
      digitalWrite(13, SEGMENT_OFF);
      break;

    case 12: //C
      digitalWrite(segA, SEGMENT_ON);
      digitalWrite(segB, SEGMENT_OFF);
      digitalWrite(segC, SEGMENT_OFF);
      digitalWrite(segD, SEGMENT_ON);
      digitalWrite(segE, SEGMENT_ON);
      digitalWrite(segF, SEGMENT_ON);
      digitalWrite(segG, SEGMENT_OFF);
      digitalWrite(13, SEGMENT_OFF);
      break;

    case 13://o
      digitalWrite(segA, SEGMENT_OFF);
      digitalWrite(segB, SEGMENT_OFF);
      digitalWrite(segC, SEGMENT_ON);
      digitalWrite(segD, SEGMENT_ON);
      digitalWrite(segE, SEGMENT_ON);
      digitalWrite(segF, SEGMENT_OFF);
      digitalWrite(segG, SEGMENT_ON);
      digitalWrite(13, SEGMENT_OFF);
      break;

  }
}
