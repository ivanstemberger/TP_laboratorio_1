#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Llamada.h"


int main()
{
    int opcion = 0;
    int load;
    FILE* pFile = fopen("DATA_final1.csv", "r");


    LinkedList* ll_llamada = ll_newLinkedList();

    do{
        printf("Por favor, seleccione una de las siguientes opciones para continuar:\n\n"
        "1) Cargar los datos de las llamadas.\n"
        "2) Imprimir llamadas.\n"
        "3) Generar archivo.\n"
        "4) Salir\n"
        );

        scanf("%d",&opcion);



        switch(opcion)
        {
            case 1:
            {
                if(pFile != NULL)
                {
                    load = parser_llamadaFromText(pFile, ll_llamada);
                }
                break;
            }

            case 3:
            {
                filtro(seleccion,llamada);
                LinkedList* ll_filter(ll_llamada,filtro,llamada);
                break;
            }
            case 4:
            {
                if(binario || texto)
                {
                    controller_editEmployee(listaEmpleados);
                }
                else
                {
                    printf("Primero abra el archivo.");
                }

                break;

            }
        }
    }while(opcion != 10);
    return 0;
}
