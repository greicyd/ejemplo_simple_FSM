// Definición de funciones.h
#ifndef FUNCIONES_H
#define FUNCIONES_H

// Inclusión de bibliotecas necesarias
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <pthread.h>

// Definición de constantes simbólicas para identificar los tipos de luz
#define kRedLight 1       // Tipo de luz asociado al estado rojo
#define kGreenLight 2     // Tipo de luz asociado al estado verde
#define kYellowLight 3    // Tipo de luz asociado al estado amarillo

// Definición de tipos de datos para los estados y eventos
typedef enum { EXIT = 0, kRedState, kGreenState, kYellowState } STATE;
typedef enum { NO_EVENT = 0, STOP_COMMAND, GO_COMMAND, TIMER_TIMEOUT } EVENT;

// Definición de una estructura para la tabla de estados
struct sStateTableEntry
{
    int light;               // Tipo de luz asociado al estado
    STATE nextStateOnGo;     // Próximo estado cuando se recibe el evento GO_COMMAND
    STATE nextStateOnStop;   // Próximo estado cuando se recibe el evento STOP_COMMAND
    STATE nextStateOnTimeout;// Próximo estado cuando se recibe el evento TIMER_TIMEOUT
};

// Declaración de funciones que serán implementadas en funciones.c
int get_event();                                // Función para obtener eventos desde la entrada
void light_on(int light);                       // Función para encender la luz según el tipo
void handle_event_go(struct sStateTableEntry *currentState); // Función para manejar el evento GO_COMMAND

#endif // FUNCIONES_H