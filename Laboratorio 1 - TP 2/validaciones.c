#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *
 *\brief verifica si el valor recibido es númerico
 *\param auxiliar Array con la cadena analizada
 *\return 1 si es númerico, 0 si no lo es
 *
 */


int esNumerico(char auxiliar[])
{
    int i = 0;


    while(auxiliar[i] != '\0')
    {


        if(auxiliar[i] > '0' || auxiliar[i] < '9')
        {
            return 1;
            break;
        }


    }
    return 0;
}

/**
 *
 *\brief verifica si el valor recibido contiene solo letras
 *\param auxiliar Array con la cadena analizada
 *\return 1 si la cadena contiene solo letras, 0 si no.
 *
 */
int soloLetras(char auxiliar[])
{
    int i = 0;

    while(auxiliar[i]!= '\0')
    {
        if((auxiliar[i] != ' ') &&(auxiliar[i] < 'a' || auxiliar[i] > 'z') && (auxiliar[i]<'A' || auxiliar[i]>'Z'))
        {
            return 0;
            break;
        }
        i++;

    }

    return 1;
}

