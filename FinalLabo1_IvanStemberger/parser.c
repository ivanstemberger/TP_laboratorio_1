#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "partida.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_partidaFromText(FILE* pFile , LinkedList* ll_partida)
{


    char id[4];
    char fecha[10];
    char juego[9];
    char jugadores[2];
    char duracion[3];
    int cantidad = 0;


    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            cantidad = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,\n]\n", id, fecha, juego, jugadores, duracion);
            if(cantidad != 5)
            {
                printf("Error en la carga\n\n");
                system("pause");
            }
            else
            {
                ePartida* partida = partida_new();
                ll_add(ll_partida,partida);
                partida->id_partida = atoi(id);
                strcpy(partida->fecha,fecha);
                partida->tipo_juego = atoi(juego);
                partida->cantidad_jugadores = atoi(jugadores);
                partida->duracion_partida= atoi(duracion);
             }
        }
    fclose(pFile);
    return 1;
    }
    else
    {
        printf("No hay archivo.\n");
        system("pause");
        return 0;
    }

}

