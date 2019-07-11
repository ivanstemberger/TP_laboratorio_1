#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Llamada.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* llamadas)
{

    char llamada[4];
    char fecha[10]
    char cliente[9];
    char problema;
    char solucion[2];
    int cantidad = 0;


    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            cantidad = fscanf(pFile,"%[^,],%[^,]%[^,],%[^,],%[^,\n]\n", llamada, fecha, cliente,problema,solucion);
            if(cantidad != 4)
            {
                printf("Error en la carga\n\n");
                system("pause");
            }
            else
            {
                eLLamada* llamada = llamada_new();
                ll_add(llamadas,llamada);
                llamada.id_Llamada = atoi(llamada));
                strcpy(llamada.fecha,fecha);
                llamada.numero_Cliente = atoi(cliente);
                llamada.id_Problema = atoi(problema);
                strcpy(llamada.solucionado,solucion);
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
