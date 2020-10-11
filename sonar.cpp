/** Do measurement with sonar sensor HC-SR04
 * 
 * Based on python tutorial:
 * https://www.youtube.com/watch?v=xACy8l3LsXI&ab_channel=GavenMacDonald
 * 
 * */
#include <iostream>
#include <wiringPi.h>

constexpr unsigned int TRIG{0};
constexpr unsigned int ECHO{1};

void setup()
{
    wiringPiSetup();
    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);
}

double measure()
{
    //  wait in between measurements
    delay(50);

    // trigger sensor
    digitalWrite(TRIG, 1);
    delayMicroseconds(10);
    digitalWrite(TRIG, 0);

    // measure echo peak length
    while (digitalRead(ECHO) == 0)
    {
    }
    unsigned int start = micros();

    while (digitalRead(ECHO) == 1)
    {
    }
    unsigned int stop = micros();

    // convert to meter
    return (double)(stop - start) / 1e6 * 170;
}

int main(void)
{
    std::cout << "Reading sonar" << std::endl;

    setup();

    double t = 0;

    while (true)
    {
        t = measure();
        std::cout << "Time: " << t << std::endl;
        delay(500);
    }
    return 0;
}