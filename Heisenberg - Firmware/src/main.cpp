#include <BTControl.h>

void setup() {
    DriverMotor::start();
    BTControl::start();
}

void loop() {
    BTControl::loop();
}
 
// La logica del actualizador de aceleracion y registro de anteriores comandos la tendra un modulo aparte, 
// ese registrara times, ultimos comandos, etc

/*void updateDynamic(float* newLeft, float* newRight)
    {
        // En base al times del ultimo comando y a los valores maximos de motores, aceleracion gradual
        // Graduando times de 0 a TIME_UMBRAL con un desplazamiento de TIME_LAPSE, y actualizando cada TIME_LAPSE
        // La Velocidad Objetivo que tenga de maxima
        float factor = min(times + 5LL,50LL) / 50.0;
        *newLeft = maxLeft * factor;
        *newRight = maxRight * factor;
    }*/