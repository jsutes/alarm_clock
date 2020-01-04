
#include "Light.h"

#include <Arduino.h>

Light::Light(int pin) :
    pixels_(numLedPixels_, pin, NEO_GRBW + NEO_KHZ800)
{
}

void Light::setup()
{
    pixels_.begin();
    pixels_.clear();
    pixels_.show();
    pixels_.setBrightness(255);
}

void Light::off()
{
    pixels_.clear();
    pixels_.show();
}

void Light::on(int r, int g, int b)
{
    pixels_.fill(pixels_.Color(r, g, b));
    pixels_.show();
}

void Light::fadeOn(int r, int g, int b)
{
    int increments = 255;
    for (int i = 0; i < increments; i++) {
        pixels_.setBrightness(255 * i/((float)increments-1));
        pixels_.fill(pixels_.Color(r, g, b));
        pixels_.show();
        delay(fadeTime_ / increments);
    }
}
void Light::fadeOff()
{
    int increments = 255;
    for (int i = increments-1; i >= 0; i--) {
        pixels_.setBrightness(255 * i/((float)increments-1));
        //pixels_.fill(pixels_.Color(r, g, b));
        pixels_.show();
        delay(fadeTime_ / increments);
    }
}