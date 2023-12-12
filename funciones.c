#include "funciones.h"

// Declaración de la tabla de estados definida en Main.c
extern struct sStateTableEntry stateTable[];

// Función para encender la luz (a completar según sea necesario)
void light_on(int light)
{
}

// Función para manejar el evento GO_COMMAND
void handle_event_go(struct sStateTableEntry *currentState)
{
    // Cambia el estado actual al próximo estado cuando ocurre GO_COMMAND
    *currentState = stateTable[currentState->nextStateOnGo];

    // Enciende la luz asociada con el nuevo estado
    light_on(currentState->light);
}

