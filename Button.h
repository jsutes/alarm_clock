#ifndef BUTTON_H
#define BUTTON_H


class Button
{
    public:
        Button(int pin);

        bool buttonPressed() const;

    private:
        int pin;

};

#endif