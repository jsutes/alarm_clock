
#include "Display.h"
#include "Button.h"


const int ledPin =  13;

const int displayClkPin = 2;
const int displayDioPin = 3;
const int buttonUpPin = 4;
const int buttonDownPin = 5;

Display display(displayClkPin, displayDioPin);

Button buttonUp(buttonUpPin);
Button buttonDown(buttonDownPin);

void setup()
{
    Serial.begin(115200);
    Serial.println("Setup");
    pinMode(ledPin, OUTPUT);

    display.setTime(8, 43);
}

void loop()
{
    Serial.println("loop begin");
    //delay(1000);

    //if (buttonUp.buttonPressed()) {
    //    digitalWrite(ledPin, HIGH);
    //} else {
    //    digitalWrite(ledPin, LOW);
    //}

    if (buttonUp.buttonPressed()) {
        Serial.print("Button UP pressed ... ");
        display.incrementHours();
        Serial.print("display finished ... ");
        delay(400);
        Serial.println("wait over");
    }
    if (buttonDown.buttonPressed()) {
        Serial.print("Button DOWN pressed ... ");
        display.decrementHours();
        Serial.print("display finished ... ");
        delay(400);
        Serial.println("wait over");
    }

}
