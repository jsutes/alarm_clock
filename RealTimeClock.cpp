
#include "RealTimeClock.h"

#include <Arduino.h>

RealTimeClock::RealTimeClock()
{
}

void RealTimeClock::setup()
{
    rtc_.begin();
    if (!rtc_.isrunning()) {
        Serial.println("RTC is NOT running!");
        // Following line sets the RTC to the date & time this sketch was compiled
        // rtc_.adjust(DateTime(F(__DATE__), F(__TIME__)));
    } else {
        Serial.println("RTC is okay");
    }
}

void RealTimeClock::setTime(int hour, int minute)
{
    setHours(hour);
    setMinutes(minute);
}

void RealTimeClock::getHoursMinutes(int& hour, int& minute) const
{
    DateTime t = now();
    hour = t.hour();
    minute = t.minute();
}
const int* RealTimeClock::getHoursMinutes()
{
    DateTime t = now();
    hourminute_[0] = t.hour();
    hourminute_[1] = t.minute();
    return hourminute_;
}
int RealTimeClock::getHours() const
{
    return now().hour();
}
int RealTimeClock::getMinutes() const
{
    return now().minute();
}
void RealTimeClock::setHours(int hour)
{
    hour = correctHoursRange(hour);
    DateTime t = now();
    rtc_.adjust(DateTime(t.year(), t.month(), t.day(), hour, t.minute(), t.second()));
}
void RealTimeClock::setMinutes(int minute)
{
    minute = correctMinutesRange(minute);
    DateTime t = now();
    rtc_.adjust(DateTime(t.year(), t.month(), t.day(), t.hour(), minute, t.second()));
}

void RealTimeClock::incrementHours()
{
    setHours(getHours() + 1);
}
void RealTimeClock::decrementHours()
{
    setHours(getHours() - 1);
}
void RealTimeClock::incrementMinutes()
{
    setMinutes(getMinutes() + 1);
}
void RealTimeClock::decrementMinutes()
{
    setMinutes(getMinutes() - 1);
}

int RealTimeClock::correctHoursRange(int hour)
{
    return (((hour-1) % 24 + 24) % 24) + 1;
}
int RealTimeClock::correctMinutesRange(int minute)
{
    return (minute % 60 + 60) % 60;
}

DateTime RealTimeClock::now() const
{
  return rtc_.now();
}
