#ifndef LIGHT_H
#define LIGHT_H

#include <Adafruit_NeoPixel.h>

class Light
{
    public:
        Light(int pin);

        void setup();

        void off();
        // Turn on (red, gree, blue) 0 - 255
        void on(int r, int g, int b);

        void fadeOn(int r, int g, int b);
        void fadeOff();

    private:
        const int numLedPixels_ = 12;
        const int fadeTime_ = 1000;
        Adafruit_NeoPixel pixels_;

};

#endif