#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{


    int cantidad = 0;
    char idStr[6];
    char nombreStr[20];
    char horasTrabajadasStr[6];
    char sueldoStr[6];

    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            cantidad = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,\n]\n", idStr, nombreStr, horasTrabajadasStr, sueldoStr);
            if(cantidad != 4)
            {
                printf("Error en la carga\n\n");
                system("pause");
            }
            else
            {
                Employee* empleado = employee_new();
                empleado->id = atoi(idStr);
                strcpy(empleado->nombre, nombreStr);
                empleado->horasTrabajadas = atoi(horasTrabajadasStr);
                empleado->sueldo = atoi(sueldoStr);
                ll_add(pArrayListEmployee, empleado);
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

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{


    if(pFile != NULL)
    {
        int cantidad;

        while(!feof(pFile))
        {

                Employee* empleado = employee_new();
                cantidad = fread(empleado, sizeof(Employee),1,pFile);
                if(cantidad != 1)
                {
                    printf("Error en la carga.\n");
                }
                else
                {
                    ll_add(pArrayListEmployee, empleado);
                }
        }
    fclose(pFile);
    return 1;
    }
    else
    {
        printf("No hay archivo\n");
        system("pause");
        return 0;
    }

}
