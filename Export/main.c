#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int opcion = 0;
    int binario=0;
    int texto=0;

    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        printf("Por favor, seleccione una de las siguientes opciones para continuar:\n\n"
        "1) Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n"
        "2) Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n"
        "3) Alta de empleado\n"
        "4) Modificar datos de empleado\n"
        "5) Baja de empleado\n"
        "6) Listar empleados\n"
        "7) Ordenar empleados\n"
        "8) Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
        "9) Guardar los datos de los empleados en el archivo data.csv (modo binario).\n"
        "10) Salir\n"
        );

        scanf("%d",&opcion);



        switch(opcion)
        {
            case 1:
            {
                if(!binario && controller_loadFromText("data.csv",listaEmpleados))
                {
                    texto = 1;
                }
                else
                {
                    printf("/nArchivo abierto en binario./n");
                }
                break;
            }
            case 2:
            {
                ;
                if(!texto && controller_loadFromBinary("data.csv",listaEmpleados))
                {
                    binario = 1;
                }
                else
                {
                    printf("/nArchivo abierto en texto./n");
                }
                break;

            }
            case 3:
            {
                if(binario || texto)
                {
                    controller_addEmployee(listaEmpleados);
                }
                else
                {
                    printf("Primero abra el archivo.");
                }
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
            case 5:
            {
                if(binario || texto)
                {
                    controller_removeEmployee(listaEmpleados);
                }
                else
                {
                    printf("Primero abra el archivo.");
                }

                break;
            }
            case 6:
            {
                if(binario || texto)
                {
                    controller_ListEmployee(listaEmpleados);
                }
                else
                {
                    printf("Primero abra el archivo.");
                }

                break;
            }
            case 7:
            {
                if(binario || texto)
                {
                    controller_sortEmployee(listaEmpleados);
                }
                else
                {
                    printf("Primero abra el archivo.");
                }

                break;
            }
            case 8:
            {
                if(binario || texto)
                {
               controller_saveAsText("data.csv" , listaEmpleados);
                }
                else
                {
                    printf("Primero abra el archivo.");
                }

                break;
            }
            case 9:
            {
                if(binario || texto)
                {
                controller_saveAsBinary("data.csv" , listaEmpleados);
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
