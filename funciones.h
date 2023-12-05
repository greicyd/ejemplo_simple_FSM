#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <pthread.h>

typedef enum {EXIT = 0, RED, GREEN, YELLOW} STATE;
typedef enum {NO_EVENT = 0, STOP_COMMAND, GO_COMMAND, TIMER_TIMEOUT} EVENT;

int get_event();
void luz_verde();
void luz_roja();
void luz_amarilla();