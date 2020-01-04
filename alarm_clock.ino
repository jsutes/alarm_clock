
#include "Display.h"
#include "Button.h"
#include "RealTimeClock.h"


const int ledPin =  13;

const int displayClkPin = 2;
const int displayDioPin = 3;
const int buttonUpPin = 4;
const int buttonDownPin = 5;

Display display(displayClkPin, displayDioPin);
RealTimeClock rtc;

Button buttonUp(buttonUpPin);
Button buttonDown(buttonDownPin);

void setup()
{
    while (!Serial); // for Leonardo/Micro/Zero
    Serial.begin(115200);
    Serial.println("Setup");
    pinMode(ledPin, OUTPUT);

    rtc.setup();

}

void loop()
{
    Serial.println("loop begin");
    //delay(1000);


    int hour, minute;
    //Serial.print("time "); Serial.print(hour); Serial.print(" "); Serial.println(minute);
    rtc.getHoursMinutes(hour, minute);
    //Serial.print("time "); Serial.print(hour); Serial.print(" "); Serial.println(minute);
    display.setTime(hour, minute);



    //if (buttonUp.buttonPressed()) {
    //    digitalWrite(ledPin, HIGH);
    //} else {
    //    digitalWrite(ledPin, LOW);
    //}

    // Set real time clock
    if (buttonUp.buttonPressed()) {
        Serial.print("Button UP pressed ... ");
        rtc.incrementHours();
        Serial.print("display finished ... ");
        delay(400);
        Serial.println("wait over");
    }
    if (buttonDown.buttonPressed()) {
        Serial.print("Button DOWN pressed ... ");
        rtc.decrementHours();
        Serial.print("display finished ... ");
        delay(400);
        Serial.println("wait over");
    }

    //if (buttonUp.buttonPressed()) {
    //    Serial.print("Button UP pressed ... ");
    //    display.incrementHours();
    //    Serial.print("display finished ... ");
    //    delay(400);
    //    Serial.println("wait over");
    //}
    //if (buttonDown.buttonPressed()) {
    //    Serial.print("Button DOWN pressed ... ");
    //    display.decrementHours();
    //    Serial.print("display finished ... ");
    //    delay(400);
    //    Serial.println("wait over");
    //}

}
