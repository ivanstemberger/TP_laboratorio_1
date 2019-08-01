#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"


Employee* employee_new(void)
{
    Employee* empleado = (Employee*)malloc(sizeof(Employee));

    if(empleado == NULL)
    {
        printf("No hay espacio para un nuevo empleado.\n");
        return 0;
    }
    else
    {
        empleado->id = 0;
        strcpy(empleado->nombre, "");
        empleado->horasTrabajadas = 0;
        empleado->sueldo = 0;
    }
    return empleado;

}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* this = employee_new();


    if(employee_setId(this,atoi(idStr)) && employee_setNombre(this,nombreStr)&& employee_setHorasTrabajadas(this,atoi(horasTrabajadasStr)) && employee_setSueldo(this,atof(sueldoStr)))
    {
        return this;
    }
    else
    {
        printf("/nHubo un error en la carga./n");
        free(this);
        return 0;
    }
}
void employee_delete()
{

}
int employee_setId(Employee* this,int id)
{
    if(this != NULL)
    {
        this->id = id;
        return 1;
    }
    else
    {
        return 0;
    }

}
int employee_getId(Employee* this,int* id)
{

}
int employee_setNombre(Employee* this,char* nombre)
{
    if(this != NULL && strlen(nombre) > 0 && nombre != NULL)
    {
        strcpy(this->nombre,nombre);
        return 1;
    }
    else
    {
        return 0;
    }
}
int employee_getNombre(Employee* this,char* nombre)
{
    return 1;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    if(this != NULL)
        {
            this->horasTrabajadas = horasTrabajadas;
            return 1;
        }
        else
        {
            return 0;
        }
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    return 1;
}

int employee_setSueldo(Employee* this,float sueldo)
{
    if(this != NULL)
    {
        this->sueldo = sueldo;
        return 1;
    }
    else
    {
        return 0;
    }
}
int employee_getSueldo(Employee* this,float* sueldo)
{
    return 1;
}
