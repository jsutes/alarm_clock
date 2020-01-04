
#include "Display.h"

#include <Arduino.h>

Display::Display(int clkPin, int dioPin) :
    tm1637_(clkPin, dioPin)
{
    hour_ = 0;
    minute_ = 0;
    brightness_ = 7;
    on_ = true;
    tm1637_.clear();
    tm1637_.setBrightness(brightness_, true);
}

void Display::setTime(int hour, int minute)
{
    setHours(hour);
    setMinutes(minute);
}
void Display::setTime(const int* hourminute)
{
    setHours(hourminute[0]);
    setMinutes(hourminute[1]);
}

int Display::getHours() const
{
    return hour_;
}
int Display::getMinutes() const
{
    return minute_;
}
void Display::setHours(int hour)
{
    hour_ = correctHoursRange(hour);
    updateScreen();
}
void Display::setMinutes(int minute)
{
    minute_ = correctMinutesRange(minute);
    updateScreen();
}

void Display::incrementHours()
{
    setHours(getHours() + 1);
}
void Display::decrementHours()
{
    setHours(getHours() - 1);
}
void Display::incrementMinutes()
{
    setMinutes(getMinutes() + 1);
}
void Display::decrementMinutes()
{
    setMinutes(getMinutes() - 1);
}

void Display::on()
{
    on_ = true;
    tm1637_.setBrightness(brightness_, true);
    updateScreen();
}
void Display::off()
{
    on_ = false;
    tm1637_.setBrightness(brightness_, false);
    updateScreen();
}

void Display::startBlinking()
{
    previousBlinkTime_ = millis();
    on();
}
void Display::updateBlink()
{
    if (millis() - previousBlinkTime_ >= blinkInterval_) {
        // Update the stored time
        previousBlinkTime_ = millis();
        // Alternate the screen on/off
        onOffSwitch();
    }
}
void Display::stopBlinking()
{
    on();
}

int Display::correctHoursRange(int hour)
{
    return (((hour-1) % 24 + 24) % 24) + 1;
}
int Display::correctMinutesRange(int minute)
{
    return (minute % 60 + 60) % 60;
}

void Display::updateScreen() {
    tm1637_.showNumberDecEx(hour_*100 + minute_, 0b01000000);
}

void Display::onOffSwitch()
{
    if (on_) {
        off();
    } else {
        on();
    }
}