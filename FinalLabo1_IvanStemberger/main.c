#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "partida.h"
#include "parser.h"


int main()
{
    int opcion = 0;
    int load = 0;
    int i;
    int tipo;
    int cantidad = 0;
    ePartida* partidaAux = partida_new();
    FILE* pFile = fopen("data.csv", "r");


    LinkedList* ll_partida = ll_newLinkedList();

    do{
        printf("Por favor, seleccione una de las siguientes opciones para continuar:\n\n"
        "1) Cargar los datos de las partidas.\n"
        "2) Imprimir partida.\n"
        "3) Imprimir promedio de jugadores por tipo de juego.\n"
        "4) Generar archivo de costos por tipo de juego.\n"
        "5) Salir."
        );

        scanf("%d",&opcion);



        switch(opcion)
        {
            case 1:
            {
                if(pFile != NULL)
                {
                    load = parser_partidaFromText(pFile, ll_partida);
                }
                if (load == 1)
                {
                    printf("funciono la carga.\n");
                }
                break;
            }

           case 2:
            {

                for(i=0;i<ll_partida->size;i++)
                {

                    partidaAux = ll_get(ll_partida,i);

                    printf("ID: %d \n", partidaAux->id_partida);
                    printf("Fecha: %s \n", partidaAux->fecha);
                    printf("juego: %d \n", partidaAux->tipo_juego);
                    printf("jugadores: %d \n", partidaAux->cantidad_jugadores);
                    printf("duracion: %d \n", partidaAux->duracion_partida);

                }
                break;
            }
             case 3:
            {
                for(i=0;i<ll_partida->size;i++)
                {
                    partidaAux = ll_get(ll_partida,i);

                    if(ll_map(ll_partida,promedio,partidaAux))
                    {
                        printf("bien");
                    }
                    else
                    {
                        printf("mal");
                    }

                }


                break;

            }
        }
    }while(opcion != 10);
    return 0;
}
