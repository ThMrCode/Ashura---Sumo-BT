#include <BTControl.h>

void setup() {
    BTControl::start();
    DriverMotor::start();
}

void loop() {
    BTControl::loop();
}