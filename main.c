#include "funciones.h"

STATE estado;
EVENT evento;

int main(int argc, char const *argv[])
{
  
  estado=RED;
  evento=NO_EVENT;

  while(estado){
    
    switch(estado){
      case RED:
        luz_roja();
        if(evento == GO_COMMAND)
        	estado = GREEN;
        break;
      case GREEN:
        luz_verde();
        if(evento == STOP_COMMAND)
        	estado = YELLOW;
        break;
      case YELLOW:
        luz_amarilla();
        if(evento == TIMER_TIMEOUT)
        	estado = RED;
        break;
      default:
        estado = EXIT;
    }

    /* letra q = SALIR, letra s = STOP_COMMAND, 
       letra t = TIMER_TIMEOUT, letra g = GO_COMMAND*/
    evento = get_event();
  }
}