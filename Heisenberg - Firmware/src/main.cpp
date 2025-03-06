#include <DriverMotor.h>

void setup() {
    DriverMotor::start();
    DriverMotor::stateForward();
}

void loop() {
    DriverMotor::correctVelocity(255,0);
    delay(2000);
    DriverMotor::correctVelocity(0,255);
    delay(2000);
}