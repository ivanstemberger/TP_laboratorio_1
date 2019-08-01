#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "LinkedList.h"
#include "Employee.h"
#include "validaciones.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int load;

    FILE* pFile = fopen("data.csv", "r");
    if(pFile != NULL)
    {
        load = parser_EmployeeFromText(pFile, pArrayListEmployee);
    }
    else
    {
        printf("El archivo no existe\n\n");
        system("pause");
        load = 0;
    }


    return load;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int load;

    FILE* pFile = fopen("data.bin", "rb");
    if(pFile != NULL)
    {
        load = parser_EmployeeFromBinary(pFile, pArrayListEmployee);
    }
    else
    {
        printf("El archivo no existe\n\n");
        system("pause");
        load = 0;
    }

    return load;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{

    Employee* empleado = employee_new();
    char idAux[4];
    char nombreAux[128];
    char horasAux[4];
    char sueldoAux[8];

    if(pArrayListEmployee != NULL && empleado != 0)
    {
        printf("Ingrese id: ");
        scanf("%s", idAux);
        while(!esNumerico(idAux))
        {
            printf("Ingrese id: ");
            scanf("%s", idAux);

        }

        printf("Ingrese nombre: ");
        scanf("%s", nombreAux);
        while(!soloLetras(nombreAux))
        {
            printf("Ingrese nombre: ");
            scanf("%s", nombreAux);
        }


        printf("Ingrese horas trabajadas: ");
        scanf("%s", horasAux);
        while(!esNumerico(horasAux))
        {
            printf("Ingrese horas trabajadas: ");
            scanf("%s", horasAux);
        }

        printf("Ingrese sueldo: ");
        scanf("%s", sueldoAux);
        while(!esNumerico(sueldoAux))
        {
            printf("Ingrese sueldo: ");
            scanf("%s", sueldoAux);
        }


        empleado = employee_newParametros(idAux, nombreAux, horasAux, sueldoAux);

        if(empleado != NULL)
        {
            ll_add(pArrayListEmployee, empleado);
            printf("El empleado ha sido debidamente agregado.");
        }

        return 1;
    }

    else
    {
        printf("No hay suficiente espacio en memoria\n");
        return 0;
    }


}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    char idAux[4];
    char nombreAux[128];
    char horasAux[4];
    char sueldoAux[8];
    int opcion;

    int indice = ll_len(pArrayListEmployee);
    int i;
    Employee* empleado;


    if(pArrayListEmployee != NULL)

    {
        while(opcion != 4)
        {
            printf("Seleccione que desea modificar:/n"
            "1) Nombre./n"
            "2) Horas Trabajadas./n"
            "3) Sueldo./n"
            "4) Atras./5");

            scanf("%d",&opcion);

            switch(opcion)
            {
                case 1:
                {
                    printf("Escriba el id del usuario que desea modificar./n");
                    scanf("%s",idAux);

                    while(!esNumerico(idAux))
                    {
                        printf("Ingrese id: ");
                        scanf("%s", idAux);
                    }

                    for(i=0;i<=indice;i++)
                    {
                        empleado = (Employee*)ll_get(pArrayListEmployee,i);

                        if(empleado->id == atoi(idAux))
                        {
                            printf("Introduzca el nombre./n");
                            scanf("%s",nombreAux);
                            while(!soloLetras(nombreAux))
                            {
                                printf("Ingrese nombre: ");
                                scanf("%s", nombreAux);
                            }

                            if(employee_setNombre(empleado,nombreAux))
                            {
                                printf("/nEl nombre ha sido modificado./n");
                                break;
                            }

                        }

                    }

                    break;
                }
                case 2:
                {
                    printf("Escriba el id del usuario que desea modificar./n");
                    scanf("%s",idAux);
                    while(!esNumerico(idAux))
                    {
                        printf("Ingrese id: ");
                        scanf("%s", idAux);
                    }

                    for(i=0;i<=indice;i++)
                    {
                        empleado = (Employee*)ll_get(pArrayListEmployee,i);

                        if(empleado->id == atoi(idAux))
                        {
                            printf("Introduzca las horas trabajadas./n");
                            scanf("%s",horasAux);
                            while(!esNumerico(horasAux))
                            {
                                printf("Ingrese horas trabajadas: ");
                                scanf("%s", horasAux);
                            }

                            if(!esNumerico(horasAux) && employee_setHorasTrabajadas(empleado,atoi(horasAux)))
                            {
                                printf("/nLas horas han sido modificadas./n");
                                break;
                            }

                        }

                    }

                    break;
                }
                case 3:
                {
                    printf("Escriba el id del usuario que desea modificar./n");
                    scanf("%s",idAux);
                    while(!esNumerico(idAux))
                    {
                        printf("Ingrese id: ");
                        scanf("%s", idAux);
                    }

                    for(i=0;i<=indice;i++)
                    {
                        empleado = (Employee*)ll_get(pArrayListEmployee,i);

                        if(empleado->id == atoi(idAux))
                        {
                            printf("Introduzca el nombre./n");
                            scanf("%s",sueldoAux);
                            while(!esNumerico(sueldoAux))
                            {
                                printf("Ingrese id: ");
                                scanf("%s", sueldoAux);
                            }

                            if(!esNumerico(sueldoAux) && employee_setSueldo(empleado,atof(nombreAux)))
                            {
                                printf("/nEl sueldo ha sido modificado./n");
                                break;
                            }

                        }

                    }

                    break;
                }
                case 4:
                {
                    printf("Escriba el id del usuario que desea modificar./n");
                    scanf("%s",idAux);
                    while(!esNumerico(idAux))
                    {
                        printf("Ingrese id: ");
                        scanf("%s", idAux);

                    }

                    for(i=0;i<=indice;i++)
                    {
                        empleado = (Employee*)ll_get(pArrayListEmployee,i);

                        if(empleado->id == atoi(idAux))
                        {
                            printf("Introduzca el nombre./n");
                            scanf("%s",nombreAux);
                            if(!soloLetras(nombreAux) && employee_setNombre(empleado,nombreAux))
                            {
                                printf("/nEl nombre ha sido modificado./n");
                                break;
                            }

                        }

                    }

                    break;
                }

            }

        }
    }
    return 1;


}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    char idAux[4];
    int indice = ll_len(pArrayListEmployee);
    int i;
    Employee* empleado;
    return 1;

    printf("Escriba el id del usuario que desea modificar./n");
    scanf("%s",idAux);
    while(!esNumerico(idAux))
    {
        printf("Ingrese id: ");
        scanf("%s", idAux);
    }

    for(i=0;i<=indice;i++)
    {
        empleado = (Employee*)ll_get(pArrayListEmployee,i);

        if(empleado->id == atoi(idAux))
        {
            if(ll_remove(pArrayListEmployee, indice))
            {
                printf("El registro ha sido eliminado con exito");
                return 1;
                break;
            }
            else
            {
                return 0;
            }
        }
    }
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* empleado;
    int indice= ll_len(pArrayListEmployee);
    int i;

    printf("\nId   |   Nombre    |   Horas Trabajadas    |   Sueldo\n");


    for (i=0;i<indice;i++)
    {
        empleado = (Employee*)ll_get(pArrayListEmployee,i);

        printf("%d   |   %s    |   %d    |   %f \n",empleado->id,empleado->nombre,empleado->horasTrabajadas,empleado->sueldo);

    }


    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    Employee* empleadoA;
    char nombreAux[128];
    int idAux;
    int horasAux;
    float sueldoAux;
    Employee* empleadoB;
    int opcion = 0;
    int indice= ll_len(pArrayListEmployee);
    int i;
    int j;

    printf("Seleccione por que parametro desea ordenar:/n"
            "1) Id/n"
            "2) Nombre./n"
            "3) Horas Trabajadas./n"
            "4) Sueldo./n");


    scanf("%d",&opcion);
    while (opcion != 1 || opcion != 2 || opcion != 3 || opcion != 4)
    {
        switch(opcion)
        {
            case 1:
            {
                for (i=0;i<indice;i++)
                {
                    empleadoA = (Employee*)ll_get(pArrayListEmployee,i);


                    for(j=i+1;j<indice;j++)
                    {
                        empleadoB = (Employee*)ll_get(pArrayListEmployee,j);


                        if(empleadoA->id > empleadoB->id)
                        {
                            idAux = empleadoA->id;
                            empleadoA->id = empleadoB->id;
                            empleadoB->id = idAux;

                            strcpy(nombreAux, empleadoA->nombre);
                            strcpy(empleadoA->nombre , empleadoB->nombre);
                            strcpy(empleadoB->nombre , nombreAux);

                            horasAux = empleadoA->horasTrabajadas;
                            empleadoA->horasTrabajadas = empleadoB->horasTrabajadas;
                            empleadoB->horasTrabajadas = horasAux;

                            sueldoAux = empleadoA->sueldo;
                            empleadoA->sueldo = empleadoB->sueldo;
                            empleadoB->sueldo = sueldoAux;
                        }

                    }
                }
                break;
            }
            case 2:
            {
                for (i=0;i<indice;i++)
                {
                    empleadoA = (Employee*)ll_get(pArrayListEmployee,i);
                    for(j=i+1;j<indice;j++)
                    {
                        empleadoB = (Employee*)ll_get(pArrayListEmployee,j);

                        if(strcmp(empleadoA->nombre,empleadoB->nombre) >0)
                        {
                            idAux = empleadoA->id;
                            empleadoA->id = empleadoB->id;
                            empleadoB->id = idAux;

                            strcpy(nombreAux, empleadoA->nombre);
                            strcpy(empleadoA->nombre , empleadoB->nombre);
                            strcpy(empleadoB->nombre , nombreAux);

                            horasAux = empleadoA->horasTrabajadas;
                            empleadoA->horasTrabajadas = empleadoB->horasTrabajadas;
                            empleadoB->horasTrabajadas = horasAux;

                            sueldoAux = empleadoA->sueldo;
                            empleadoA->sueldo = empleadoB->sueldo;
                            empleadoB->sueldo = sueldoAux;
                        }


                    }

                }

                break;
            }
            case 3:
            {
                for (i=0;i<indice;i++)
                {
                    empleadoA = (Employee*)ll_get(pArrayListEmployee,i);
                    for(j=i+1;j<indice;j++)
                    {
                        empleadoB = (Employee*)ll_get(pArrayListEmployee,j);
                        if(empleadoA->horasTrabajadas > empleadoB->horasTrabajadas)
                        {
                            idAux = empleadoA->id;
                            empleadoA->id = empleadoB->id;
                            empleadoB->id = idAux;

                            strcpy(nombreAux, empleadoA->nombre);
                            strcpy(empleadoA->nombre , empleadoB->nombre);
                            strcpy(empleadoB->nombre , nombreAux);

                            horasAux = empleadoA->horasTrabajadas;
                            empleadoA->horasTrabajadas = empleadoB->horasTrabajadas;
                            empleadoB->horasTrabajadas = horasAux;

                            sueldoAux = empleadoA->sueldo;
                            empleadoA->sueldo = empleadoB->sueldo;
                            empleadoB->sueldo = sueldoAux;
                        }
                    }

                }

                break;
            }
            case 4:
            {
                for (i=0;i<indice;i++)
                {
                    empleadoA = (Employee*)ll_get(pArrayListEmployee,i);
                    for(j=i+1;j<indice;j++)
                    {
                        empleadoB = (Employee*)ll_get(pArrayListEmployee,j);
                        if(empleadoA->sueldo > empleadoB->sueldo)
                        {
                            idAux = empleadoA->id;
                            empleadoA->id = empleadoB->id;
                            empleadoB->id = idAux;

                            strcpy(nombreAux, empleadoA->nombre);
                            strcpy(empleadoA->nombre , empleadoB->nombre);
                            strcpy(empleadoB->nombre , nombreAux);

                            horasAux = empleadoA->horasTrabajadas;
                            empleadoA->horasTrabajadas = empleadoB->horasTrabajadas;
                            empleadoB->horasTrabajadas = horasAux;

                            sueldoAux = empleadoA->sueldo;
                            empleadoA->sueldo = empleadoB->sueldo;
                            empleadoB->sueldo = sueldoAux;
                        }
                    }

                }
                break;
            }

        }
        break;

    }
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
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

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* archivo = fopen(path, "wb");
    Employee* empleado;
    int linea;

    if(pArrayListEmployee != NULL)
    {
        rewind(archivo);
        for(int i=0; i<ll_len(pArrayListEmployee); i++)
        {
            empleado = (Employee*)ll_get(pArrayListEmployee,i);
            linea = fwrite(empleado, sizeof(Employee), 1, archivo);

            if(linea != 1)
            {
                printf("\nError en la escritura.\n\n");
                break;
            }

        }
        printf("\nLos datos han sido almacenados\n");
        return 1;
    }

    else
    {

        return 0;
    }

    fclose(archivo);

}

