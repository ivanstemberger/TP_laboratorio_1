#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "empleados.h"
#include "validaciones.h"


/**
 *
 *\brief coloca en 1 (vacio) todos los espacios del array de empleado.
 *\param empleado es el array que contiene la información del empleado
 *\param cantidad máxima de empleados que se pueden cargar
 *
 */


void inicializar(eEmployee empleado[], int cantidad)
{
    int i;

    for(i = 0; i < cantidad ; i++)
    {
        empleado[i].isEmpty = 1;
        empleado[i].id = 0;

    }
}

/**
 *
 *\brief Permite la carga del empleado.
 *\param empleado es la variable que contiene la información del empleado
 *\param cantidad máxima de empleados que se pueden cargar
 *
 */

void altaEmpleado(eEmployee empleado[], int cantidad)
{
    int i;

    char auxNombre[52];
    char auxApellido[52];
    char auxSalario[52];
    char auxSector[2];

    for (i = 0; i < cantidad; i++)
    {
        if(empleado[i].isEmpty == 1)
        {




            printf("Ingrese el nombre:\n");
            fflush(stdin);
            scanf("%s", auxNombre);

            if(soloLetras(auxNombre) && strlen(auxNombre)<=52)
            {
                strcpy(empleado[i].nombre,auxNombre);
            }
            else
            {
                printf("El nombre solo puede constar de letras hasta un maximo de 52.\n");
                break;
            }

            printf("Ingrese el apellido:\n");
            fflush(stdin);
            scanf("%s", auxApellido);

            if(soloLetras(auxApellido) && strlen(auxApellido)<=52)
            {
                strcpy(empleado[i].apellido,auxApellido);
            }
            else
            {
                printf("El apellido solo puede constar de letras hasta un maximo de 52.\n");
                break;
            }

            printf("Ingrese el salario:\n");
            scanf("%s", auxSalario);

            if(esNumerico(auxSalario))
            {
                empleado[i].salario = atoi(auxSalario);
            }
            else
            {
                printf("El salario solo puede constar de numeros.\n");
                break;
            }

            printf("Ingrese el codigo del sector:\n");
            scanf("%s", auxSector);

             if(esNumerico(auxSector) && strlen(auxNombre)<=2)
            {
                empleado[i].idSector = atoi(auxSalario);
            }
            else
            {
                printf("El sector solo puede constar de numeros hasta un máximo de 2 dígitos.\n");
                break;
            }

            empleado[i].id = i + 1;
            empleado[i].isEmpty = 0;
            break;
        }



    }

}

/**
 *
 *\brief Permite dar de baja a un empleado. Se realiza una baja lógica.
 *\param empleado es la variable que contiene la información del empleado
 *\param cantidad máxima de empleados que se pueden cargar
 *
 */


void bajaEmpleado (eEmployee empleado[],int cantidad)
{
    int i;
    int idAux;

    printf("Ingrese el legajo del empleado a dar de baja:\n");
    scanf("%d", &idAux);


    for(i = 0; i < cantidad; i++)
    {
        if (empleado[i].id == idAux)
        {
            empleado[i].isEmpty = 1;
            break;
        }
    }


}

/**
 *
 *\brief Permite modificar Nombre, Apellido, Salario y Sector de cada empleado.
 *\param empleado es la variable que contiene la información del empleado
 *\param cantidad máxima de empleados que se pueden cargar
 *
 */


void modEmpleado (eEmployee empleado[], int cantidad)
{

    int i;
    char idAux[4];
    int id;
    int choice;
    char auxSalario[52];
    char auxSector[2];

    printf("Ingrese el id del empleado a modificar:\n");
    scanf("%s", idAux);

    if(esNumerico(idAux))
                    {
                        id = atoi(idAux);
                    }
                    else
                    {
                        printf("El id solo puede contener numeros.");
                    }

    printf("Seleccione una de las siguientes opciones:\n 1) Apellido\n 2) Nombre\n 3) Salario \n 4) Sector \n");
    scanf("%d", &choice);


    switch (choice)
    {
        case 1:
        {

            for(i=0;i<cantidad;i++)
            {

                printf("%d \n",empleado[i].id);

                if(id == empleado[i].id)
                {
                    printf("El apellido actual es: %s \n Introduzca el nuevo apellido.\n", empleado[i].apellido);
                    fflush(stdin);
                    scanf("%s", empleado[i].apellido);
                    break;
                }
            }

            break;
        }
        case 2:
        {
            for(i=0;i<cantidad;i++)
            {
                if(empleado[i].id == id)
                {
                    printf("El nombre actual es: %s \n Introduzca el nuevo nombre.\n", empleado[i].nombre);
                    fflush(stdin);
                    scanf("%s", empleado[i].nombre);
                    break;
                }
            }
            break;
        }

        case 3:
        {
        for(i=0;i<cantidad;i++)
            {
                if(empleado[i].id == id)
                {
                    printf("El salario actual es: %f \n Introduzca el nuevo salario.\n", empleado[i].salario);
                    scanf("%s", auxSalario);

                    if(esNumerico(auxSalario))
                    {
                        empleado[i].salario = atoi(auxSalario);
                    }
                    else
                    {
                        printf("El salario solo puede contener numeros.");
                    }

                    break;
                }
            }

        break;

        }

        case 4:
        {
        for(i=0;i<cantidad;i++)
            {
                if(empleado[i].id == id)
                {
                    printf("El sector actual es: %d \n Introduzca el nuevo código de sector.\n", empleado[i].idSector);
                    fflush(stdin);
                    scanf("%s", auxSector);

                    if(esNumerico(auxSector))
                    {
                        empleado[i].idSector = atoi(auxSector);
                    }
                    else
                    {
                        printf("El sector solo puede contener numeros.");
                    }

                    break;
                }
            }
        break;
        }

    }
}

/**
 *
 *\brief Realiza un listado en orden alfabetico de los apellidos y los sectores.
 *\param empleado es la variable que contiene la información del empleado
 *\param cantidad máxima de empleados que se pueden cargar
 *
 */


void lista(eEmployee empleado[], int cantidad)
{
    int i;
    int j;
    char aux[52];
    int sectorAux;

    for(i=0; i < cantidad; i++)
    {
        for(j=i+1; j < cantidad; j++)
        {

            if(strcmp(empleado[i].apellido,empleado[j].apellido) > 0)
            {
                strcpy (aux,empleado[i].apellido);
                strcpy (empleado[i].apellido, empleado[j].apellido);
                strcpy(empleado[j].apellido, aux);

                strcpy (aux,empleado[i].nombre);
                strcpy (empleado[i].nombre, empleado[j].nombre);
                strcpy(empleado[j].nombre, aux);

                sectorAux = empleado[i].idSector;
                empleado[i].idSector = empleado[j].idSector;
                empleado[j].idSector = sectorAux;
            }
            else if (empleado[i].apellido == empleado[j].apellido)
            {
                if (empleado[i].idSector > empleado[j].idSector)
                {
                    sectorAux = empleado[i].idSector;
                    empleado[i].idSector = empleado[j].idSector;
                    empleado[j].idSector = sectorAux;

                    strcpy (aux,empleado[i].nombre);
                    strcpy (empleado[i].nombre, empleado[j].nombre);
                    strcpy(empleado[j].nombre, aux);
                }
            }
        }
    }
}

/**
 *
 *\brief Muestra la suma total de todos los salarios y el promedio de salario por empleado.
 *\param empleado es la variable que contiene la información del empleado
 *\param cantidad máxima de empleados que se pueden cargar
 *
 */


void salarios (eEmployee empleado[], int cantidad)
{
    int i;
    int contador = 0;
    int total = 0;
    int promedio = 0;

    for(i=0; i < cantidad; i++)
    {
        if(empleado[i].isEmpty == 0)
        {
            total = empleado[i].salario + total;
            contador++;
        }
    }
    promedio = total/contador;
    printf("El total de salarios es: %d \n", total);
    printf("El promedio de salarios es: %d \n", promedio);
}

/**
 *
 *\brief Muestra un listado ordenado alfabeticamente de todos los empleados por apellido y sector.
 *\param empleado es la variable que contiene la información del empleado
 *\param cantidad máxima de empleados que se pueden cargar
 *
 */


void mostrar (eEmployee empleado[], int cantidad)
{
    int i;

    for(i=0;i<cantidad;i++)
    {
        printf("\n Apellido: %s     Nombre: %s       Sector: %d \n", empleado[i].apellido, empleado[i].nombre, empleado[i].idSector);
    }
}
