#pragma once
#include <Arduino.h>

namespace DriverMotor {

    // STATE
    enum STATE {
        STATE_LEFT,
        STATE_RIGHT,
        STATE_FORWARD,
        STATE_BACKWARD,
        STATE_FORWARD_LEFT,
        STATE_FORWARD_RIGHT,
        STATE_BACKWARD_LEFT,
        STATE_BACKWARD_RIGHT,
        STATE_STOP,
    };
    // Pines del driver (a left, b right)
    // NO TE OLVIDES DE LAS COMAS CTMR
    enum PIN {
        LEFT_PWM =                  12,
        LEFT_FORWARD =              33,
        LEFT_BACKWARD =             32,
        RIGHT_FORWARD =             26,
        RIGHT_BACKWARD =            25,
        RIGHT_PWM =                 27,
    };

    // GLOBAL VARIABLES
    extern STATE state;
    extern int velocity_advance;
    extern int velocity_turn;
    extern int velocity_dif;
    extern int correct_factor;

    // Start Driver
    void start();

    // Control directo de motores
    void controlMotor(bool left_F, bool left_B, bool right_F, bool right_B);

    // Motores Libres
    void freeMotor();
  
    // Motores Frenado Activo
    void stopMotor();

    // Select State 
    void stateLeft();

    void stateRight();

    void stateForward();
    
    void stateBackward();
    
    // Corrige el factor de velocidad
    void correctVelocity(int pwmLeft, int pwmRight);

    // Actualizar Velocidades segun State
    void controlVelocity(long long times);
}