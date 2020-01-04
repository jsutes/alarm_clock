
#include "Display.h"
#include "Button.h"
#include "RealTimeClock.h"
#include "Light.h"

const int displayClkPin = 2;
const int displayDioPin = 3;
const int buttonUpPin = 4;
const int buttonDownPin = 5;
const int buttonSetTimePin = 6;
const int ledPin =  8;


Display display(displayClkPin, displayDioPin);
RealTimeClock rtc;
Light light(ledPin);

Button buttonUp(buttonUpPin);
Button buttonDown(buttonDownPin);
Button buttonSetTime(buttonSetTimePin);

void setup()
{
    while (!Serial); // for Leonardo/Micro/Zero
    Serial.begin(115200);
    Serial.println("Setup");

    rtc.setup();
    light.setup();

}

void loop()
{
    Serial.println("loop begin");
    //delay(1000);

    light.fadeOn(255, 0, 0);
    delay(200);
    light.fadeOff();
    light.fadeOn(0, 255, 0);
    light.fadeOff();
    delay(200);
    light.fadeOn(0, 0, 255);
    light.fadeOff();
    delay(200);

    display.setTime(rtc.getHoursMinutes());

    if (buttonSetTime.buttonPressed()) {
        display.startBlinking();
        // Enter a state where the time can be changed by the up/down buttons
        delay(400);
        // Set hours until SetTime button is pressed
        while (!buttonSetTime.buttonPressed()) {
            display.updateBlink();
            if (buttonUp.buttonPressed()) {
                Serial.print("Button UP pressed ... ");
                rtc.incrementHours();
                display.setTime(rtc.getHoursMinutes());
                Serial.print("display finished ... ");
                delay(400);
                Serial.println("wait over");
            }
            if (buttonDown.buttonPressed()) {
                rtc.decrementHours();
                display.setTime(rtc.getHoursMinutes());
                delay(400);
            }
        }
        delay(400);
        // Set minutes until SetTime button is pressed
        while (!buttonSetTime.buttonPressed()) {
            display.updateBlink();
            if (buttonUp.buttonPressed()) {
                rtc.incrementMinutes();
                display.setTime(rtc.getHoursMinutes());
                delay(400);
            }
            if (buttonDown.buttonPressed()) {
                rtc.decrementMinutes();
                display.setTime(rtc.getHoursMinutes());
                delay(400);
            }
        }
        display.stopBlinking();
        delay(400);
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


    //if (buttonUp.buttonPressed()) {
    //    digitalWrite(ledPin, HIGH);
    //} else {
    //    digitalWrite(ledPin, LOW);
    //}

}
