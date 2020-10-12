#include <iostream>
#include <wiringPi.h>

// #include <vector>

#define bitRead(value, bit) (((value) >> (bit)) & 0x01)

// const int pins[4]{26, 19, 13, 6};
const int pins[4]{25, 24, 23, 22};
// const int lookup[8]{0b01000, 0b01100, 0b00100, 0b00110, 0b00010, 0b00011, 0b00001, 0b01001};

const bool seq[8][4]{
    {1, 0, 0, 0},
    {1, 1, 0, 0},
    {0, 1, 0, 0},
    {0, 1, 1, 0},
    {0, 0, 1, 0},
    {0, 0, 1, 1},
    {0, 0, 0, 1},
    {1, 0, 0, 1}};

// const std::vector<std::vector<bool>> seq{
//     {1, 0, 0, 0},
//     {1, 1, 0, 0},
//     {0, 1, 0, 0},
//     {0, 1, 1, 0},
//     {0, 0, 1, 0},
//     {0, 0, 1, 1},
//     {0, 0, 0, 1},
//     {1, 0, 0, 1}};

void setup()
{
    wiringPiSetup();
    for (int pin : pins)
    {
        pinMode(pin, OUTPUT);
        digitalWrite(pin, 0);
    }
}

int main(void)
{
    std::cout << "Stepper demo" << std::endl;

    setup();

    for (int i = 0; i < 512; ++i)
    {
        for (int step = 0; step < 8; ++step)
        {
            for (int pi = 0; pi < 4; ++pi)
            {
                digitalWrite(pins[pi], seq[step][pi]);
            }
            delay(1);
        }
    }

    for (auto pin : pins)
    {
        digitalWrite(pin, 0);
    }

    return 0;
}