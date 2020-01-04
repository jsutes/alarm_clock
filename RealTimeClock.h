#ifndef REALTIMECLOCK_H
#define REALTIMECLOCK_H

#include "RTClib.h"

class RealTimeClock
{
    public:
        RealTimeClock();

        void setup();

        void setTime(int hour, int minute);

        void getHoursMinutes(int& hour, int& minute) const;
        int getHours() const;
        int getMinutes() const;

        void setHours(int hour);
        void setMinutes(int minute);

        void incrementHours();
        void decrementHours();
        void incrementMinutes();
        void decrementMinutes();

        static int correctHoursRange(int hour);
        static int correctMinutesRange(int minute);

    private:
        RTC_DS1307 rtc;
        const char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        DateTime now() const;

};

#endif