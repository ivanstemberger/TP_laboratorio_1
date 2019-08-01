#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "partida.h"


ePartida* partida_new(void)
{
    ePartida* partida = (ePartida*)malloc(sizeof(ePartida));

    if(partida == NULL)
    {
        printf("No hay espacio para un nuevo empleado.\n");
        return 0;
    }
    else
    {
        partida->id_partida = 0;
        strcpy(partida->fecha," ");
        partida->tipo_juego = 0;
        partida->cantidad_jugadores = 0;
        partida->duracion_partida = 0;
    }
    return partida;

}
void promedio(void* pElement)
{
    ePartida* partidaAux = partida_new();
    partidaAux = pElement;

    int pingPong = 0;
    int pingProm = 0;
    int pool = 0;
    int poolProm = 0;
    int metegol = 0;
    int meteProm = 0;
    int dardos = 0;
    int dardosProm = 0;

    if(partidaAux->tipo_juego)

    switch (partidaAux->tipo_juego)
    {
    case 0:
        {
            pingPong = pingPong + partidaAux->cantidad_jugadores;
            pingProm++;
            break;
        }
    case 1:
        {
            pool = pingPong + partidaAux->cantidad_jugadores;
            poolProm++;
            break;
    }
    case 2:
        {
            metegol = pingPong + partidaAux->cantidad_jugadores;
            meteProm++;
            break;
        }
    case 3:
        {
            dardos = pingPong + partidaAux->cantidad_jugadores;
            dardosProm++;

            break;
        }
    }
    printf("La cantidad promedio de jugadores de Ping Ping fue: %d. \n", pingPong/pingProm);
}
