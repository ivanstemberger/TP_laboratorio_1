#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Llamada.h"


eLLamada* llamada_new(void)
{
    eLLamada* llamada = (eLLamada*)malloc(sizeof(eLLamada));

    if(llamada == NULL)
    {
        printf("No hay espacio para un nuevo empleado.\n");
        return 0;
    }
    else
    {
        llamada.id_Llamada = 0;
        llamada.fecha.dia = 0;
        llamada.fecha.mes = 0;
        llamada.fecha.anio = 0;
        llamada.numero_Cliente = 0;
        llamada.id_Problema = 0;
        llamada.solucionado = " ";
    }
    return empleado;

}
int filtro (int seleccion,eLlamada llamada);
{
    if(llamada.id_Problema == solucion)
    {
        return 1;
    }

    return 0;
}

int saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* archivo = fopen(path, "w");

    if(pArrayListEmployee != NULL)
    {
        fprintf(archivo, "id,nombre,horasTrabajadas,sueldo\n");
        for(int i=0; i<ll_len(pArrayListEmployee); i++)
        {
            Employee* this = (Employee*) ll_get(pArrayListEmployee, i);
            fprintf(archivo, "%d,%s,%d,%f\n", this->id, this->nombre, this->horasTrabajadas, this->sueldo);
        }
        return 1;
        printf("\nLos datos han sido almacenados.\n");
    }
    else
    {
        return 0;
    }
    fclose(archivo);

}
