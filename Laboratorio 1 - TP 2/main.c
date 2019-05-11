#include <stdio.h>
#include <stdlib.h>
#include "empleados.h"
#define CANT 1000

int main()
{

   int seleccion;
   int opcion;
   eEmployee empleado[CANT];
   inicializar(empleado, CANT);

    do{
        if(empleado[0].id == 0)
        {
        printf("Por favor de un alta para continuar:\n1) Dar de alta un empleado. \n");
        scanf("%d", &seleccion);

        }
        else
        {
        printf("Seleccione una opcion:\n1) Dar de alta un empleado. \n2)Modificar un empleado. \n3)Borrar un empeado. \n4) Informar. \n5) Salir. \n");
        scanf("%d", &seleccion);

        }

        switch(seleccion)
        {
            case 1:
            {
                altaEmpleado(empleado,CANT);
                break;
            }
            case 2:
            {
                modEmpleado(empleado, CANT);
                break;
            }
            case 3:
            {
                bajaEmpleado(empleado, CANT);
                break;
            }
            case 4:
            {
                printf("Seleccione que desea ver: \n1) Total y promedio de salarios. \n2) Ver el listado de empleados ordenado alfabeticamente por apellido y sector.\n");
                scanf("%d", &opcion);

                switch (opcion)
                {
                    case 1:
                    {
                        salarios(empleado, CANT);
                        break;
                    }
                    case 2:
                    {
                        mostrar(empleado, CANT);
                        break;
                    }
                }
                break;
            }
        }




    }while (seleccion != 5);
    return 0;
}
