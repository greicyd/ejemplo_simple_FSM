#include "funciones.h"

// Definición de una tabla que representa el comportamiento de la máquina de estados
struct sStateTableEntry stateTable[] = {
    {kRedLight, kGreenState, kRedState, kRedState},       // Red
    {kYellowLight, kYellowState, kYellowState, kRedState},// Yellow
    {kGreenLight, kGreenState, kYellowState, kGreenState}  // Green
};

// Variables globales para representar el estado actual y el evento actual
STATE estado;
EVENT evento;

// Función principal del programa
int main(int argc, char const *argv[])
{
    // Inicialización del estado y el evento
    estado = kRedState;
    evento = NO_EVENT;

    // Bucle principal que se ejecuta mientras el estado no sea EXIT
    while (estado != EXIT) 
    {
        // ...

        // Switch statement para manejar cada estado
        switch (estado)
        {
        case kRedState:
            // Enciende la luz asociada al estado rojo
            light_on(stateTable[kRedState].light);

            // Verifica si el evento es GO_COMMAND y maneja el evento
            if (evento == GO_COMMAND)
                handle_event_go(&stateTable[kRedState]);

            // Resto del código específico para el estado RED
            break;

        case kGreenState:
            // Enciende la luz asociada al estado verde
            light_on(stateTable[kGreenState].light);

            // Resto del código específico para el estado GREEN
            break;

        case kYellowState:
            // Enciende la luz asociada al estado amarillo
            light_on(stateTable[kYellowState].light);

            // Resto del código específico para el estado YELLOW
            break;

        default:
            // Si el estado es diferente de los definidos, establece el estado a EXIT
            estado = EXIT;
        }
       
    }

    // Fin del programa
    return 0;
}