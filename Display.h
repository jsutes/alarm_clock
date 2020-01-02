#ifndef DISPLAY_H
#define DISPLAY_H

#include <TM1637Display.h>


class Display
{
    public:
        Display(int clkPin, int dioPin);

        void setTime(int hour, int minute);

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
        TM1637Display tm1637_;
        int hour_;
        int minute_;

        void updateScreen();
};

#endif