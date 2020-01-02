
#include "Display.h"

#include <Arduino.h>

Display::Display(int clkPin, int dioPin) :
    tm1637_(clkPin, dioPin)
{
    tm1637_.clear();
    tm1637_.setBrightness(7, true);
    hour_ = 0;
    minute_ = 0;
}

void Display::setTime(int hour, int minute)
{
    setHours(hour);
    setMinutes(minute);
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

int Display::correctHoursRange(int hour)
{
    return (((hour-1) % 12 + 12) % 12) + 1;
}
int Display::correctMinutesRange(int minute)
{
    return (minute % 60 + 60) % 60;
}

void Display::updateScreen() {
    tm1637_.showNumberDecEx(hour_*100 + minute_, 0b01000000);
}