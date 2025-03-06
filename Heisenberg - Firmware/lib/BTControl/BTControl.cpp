#include <BTControl.h>

namespace BTControl {
    String Name = "Heisenberg";\
    BluetoothSerial BT = BluetoothSerial();
    char LastCommand = 'S';
    long long times = 0;
}

void BTControl::start()
{
    BT.begin(Name); // Inicializa el Bluetooth , con este nombre aparecera en su celular
}

void BTControl::menu(char command)
{
  if(command != BTControl::LastCommand) {
    BTControl::LastCommand = command;
    switch (command) {
      case 'F': 
        DriverMotor::stateForward();
        DriverMotor::state = DriverMotor::STATE_FORWARD;
        break;
      case 'B': 
        DriverMotor::stateBackward();
        DriverMotor::state = DriverMotor::STATE_BACKWARD;
        break;
      case 'L':
        DriverMotor::stateLeft();
        DriverMotor::state = DriverMotor::STATE_LEFT;
        break;
      case 'R':
        DriverMotor::stateRight();
        DriverMotor::state = DriverMotor::STATE_RIGHT;
        break;
      case 'G': 
        DriverMotor::stateForward();
        DriverMotor::state = DriverMotor::STATE_FORWARD_LEFT;
        break;
      case 'I': 
        DriverMotor::stateForward();
        DriverMotor::state = DriverMotor::STATE_FORWARD_RIGHT;
        break;
      case 'H':
        DriverMotor::stateBackward();
        DriverMotor::state = DriverMotor::STATE_BACKWARD_LEFT;
        break;
      case 'J':
        DriverMotor::stateBackward();
        DriverMotor::state = DriverMotor::STATE_BACKWARD_RIGHT;
        break;
      case 'S':
        DriverMotor::stopMotor();
        DriverMotor::state = DriverMotor::STATE_STOP;
        break;
      default:
        break;
    }
    times = 0;
  }
  else if(BTControl::times < 100) BTControl::times++;
  DriverMotor::controlVelocity(BTControl::times);
}

void BTControl::loop()
{
    if (BT.available()) {   // Verifica si hay datos desde Bluetooth
      char rc = BT.read();  // Lee el comando
      menu(rc);             // Ejecuta la función correspondiente al comando
    }
}

/*case '1':
          DriverMotor::correct_factor = 0.4f;
          DriverMotor::state = DriverMotor::STATE_STOP;
          break;
      case '2':
          DriverMotor::correct_factor = 0.45f;
          DriverMotor::state = DriverMotor::STATE_STOP;
          break;
        case '3':
          DriverMotor::correct_factor = 0.5f;
          DriverMotor::state = DriverMotor::STATE_STOP;
          break;
      case '4':
          DriverMotor::correct_factor = 0.55f;
          DriverMotor::state = DriverMotor::STATE_STOP;
          break;
      case '5':
          DriverMotor::correct_factor = 0.60f;
          DriverMotor::state = DriverMotor::STATE_STOP;
          break;
      case '6':
          DriverMotor::correct_factor = 0.65f;
          DriverMotor::state = DriverMotor::STATE_STOP;
          break;
      case '7':
          DriverMotor::correct_factor = 0.7f;
          DriverMotor::state = DriverMotor::STATE_STOP;
          break;
      case '8':
          DriverMotor::correct_factor = 0.75f;
          DriverMotor::state = DriverMotor::STATE_STOP;
          break;*/