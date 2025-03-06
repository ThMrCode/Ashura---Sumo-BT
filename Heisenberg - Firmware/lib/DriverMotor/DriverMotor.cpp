#include <DriverMotor.h>

namespace DriverMotor {
    STATE state = STATE_STOP;  // Definición
    int velocity_advance = 220;
    int velocity_turn = 140;
    int velocity_dif = 80;
    int correct_factor = 75;
    
}

void DriverMotor::start()   {
    pinMode(PIN::LEFT_PWM, OUTPUT);   
    pinMode(PIN::LEFT_FORWARD, OUTPUT);
    pinMode(PIN::LEFT_BACKWARD, OUTPUT);
    pinMode(PIN::RIGHT_FORWARD, OUTPUT);
    pinMode(PIN::RIGHT_BACKWARD, OUTPUT);
    pinMode(PIN::RIGHT_PWM, OUTPUT);
}

void DriverMotor::controlMotor(bool left_F, bool left_B, bool right_F, bool right_B)  {
    // Definir las Direcciones (Front, Back, Stop, Free)
    digitalWrite(PIN::LEFT_FORWARD, left_F);
    digitalWrite(PIN::LEFT_BACKWARD, left_B);
    digitalWrite(PIN::RIGHT_FORWARD, right_F);
    digitalWrite(PIN::RIGHT_BACKWARD, right_B);
}

void DriverMotor::freeMotor()   {
    digitalWrite(PIN::LEFT_FORWARD, LOW);
    digitalWrite(PIN::LEFT_BACKWARD, LOW);
    digitalWrite(PIN::RIGHT_FORWARD, LOW);
    digitalWrite(PIN::RIGHT_BACKWARD, LOW);
    analogWrite(PIN::LEFT_PWM, 0);
    analogWrite(PIN::RIGHT_PWM, 0);
}

void DriverMotor::stopMotor()   {
    digitalWrite(PIN::LEFT_FORWARD, HIGH);
    digitalWrite(PIN::LEFT_BACKWARD, HIGH);
    digitalWrite(PIN::RIGHT_FORWARD, HIGH);
    digitalWrite(PIN::RIGHT_BACKWARD, HIGH);
    analogWrite(PIN::LEFT_PWM, 0);
    analogWrite(PIN::RIGHT_PWM, 0);
    delay(100);                 // Aplicar por lo menos 100 ms
}

void DriverMotor::stateLeft()
{
    controlMotor(LOW, HIGH, HIGH, LOW);
}

void DriverMotor::stateRight()
{
    controlMotor(HIGH,LOW, LOW, HIGH);
}

void DriverMotor::stateForward()
{
    controlMotor(HIGH, LOW, HIGH, LOW);
}

void DriverMotor::stateBackward()
{
    controlMotor(LOW, HIGH, LOW, HIGH);
}

void DriverMotor::correctVelocity(int pwmLeft, int pwmRight)
{
    //int pwmNewLeft = (pwmLeft * correct_factor) / 100;
    analogWrite(LEFT_PWM, pwmLeft);
    analogWrite(RIGHT_PWM, pwmRight);
}

void DriverMotor::controlVelocity(long long times)
{
    if(times == 0) {
        switch (DriverMotor::state)
        {
        case STATE_FORWARD:
        case STATE_BACKWARD:
            correctVelocity(velocity_advance,velocity_advance);
            break;
        case STATE_LEFT:
        case STATE_RIGHT:
            correctVelocity(velocity_turn,velocity_turn);
            break;
        case STATE_FORWARD_LEFT:
        case STATE_BACKWARD_LEFT:
            correctVelocity(velocity_advance - velocity_dif,velocity_advance);
            break;
        case STATE_FORWARD_RIGHT:
        case STATE_BACKWARD_RIGHT:
            correctVelocity(velocity_advance, velocity_advance - velocity_dif);
            break;
        default:
            break;
        }
    }
}
