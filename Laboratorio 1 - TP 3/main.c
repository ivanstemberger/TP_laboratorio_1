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
                controller_addEmployee(listaEmpleados);
                break;
            }
            case 4:
            {
                controller_editEmployee(listaEmpleados);
                break;
            }
            case 5:
            {
                controller_removeEmployee(listaEmpleados);
                break;
            }
            case 6:
            {
                controller_ListEmployee(listaEmpleados);
                break;
            }
            case 7:
            {
                controller_sortEmployee(listaEmpleados);
                break;
            }
            case 8:
            {
                controller_saveAsText("data.csv" , listaEmpleados);
                break;
            }
            case 9:
            {
                controller_saveAsBinary("data.csv" , listaEmpleados);
                break;
            }
        }
    }while(opcion != 10);
    return 0;
}
