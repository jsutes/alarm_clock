#ifndef DISPLAY_H
#define DISPLAY_H

#include <TM1637Display.h>


class Display
{
    public:
        Display(int clkPin, int dioPin);

        void setTime(int hour, int minute);
        void setTime(const int* hourminute);

        int getHours() const;
        int getMinutes() const;

        void setHours(int hour);
        void setMinutes(int minute);

        void incrementHours();
        void decrementHours();
        void incrementMinutes();
        void decrementMinutes();

        void on();
        void off();

        void startBlinking();
        void updateBlink();
        void stopBlinking();

        static int correctHoursRange(int hour);
        static int correctMinutesRange(int minute);

    private:
        TM1637Display tm1637_;
        int hour_;
        int minute_;
        int brightness_;
        bool on_;

        unsigned long previousBlinkTime_;
        const int blinkInterval_ = 500;

        void updateScreen();
        void onOffSwitch();
};

#endif