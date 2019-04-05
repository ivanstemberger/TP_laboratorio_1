#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/*
Esta calculadora est� creada con las siguientes funcionalidades:

En primer lugar, un bucle "while" que seguir� corriendo muientras el valor de la variable "selecci�n" no sea 5 (salir).

Inicialmente se mostrar� un men� con 5 opciones:
1) Ingresar un operando (A).
2) Ingresar otro operando (B).
3) Elejir una operaci�n (Suma, Resta, Divisi�n, Multiplicaci�n, Factorial).
4) Arrojar el resultado.
5) Salir.


Cade selecci�n realizada al presionar alguno de los n�meros (1 al 5) se guardar� en la variable integer "seleccion". A partir de esta, se pasar� a un
switch que, en funci�n de lo ingresado, permitir� realizar la acci�n deseada.
Las primeras dos opciones van a guardar el n�mero ingresado en las variables de tipo integer a y b, respectivamente.
La opci�n tres desplegar� un segundo men� para elegir la operaci�n. Esta elecci�n se guardar� en una variable int llamada "operacion".
La cuarta opci�n arrojar� el resultado en funci�n de la operaci�n seleccionada. Esto se realiza llamando a la funci�n correspondiente,
Finalmente, la quinta opci�n, Salir. Al seleccionarla, se saldr� del bucle inicial y el programa finalizar�.

*/
int main()
{
    int seleccion;
    int operacion;
    int a=0;
    int b=0;

    while(seleccion !=5)
    {

        printf("Por favor ingrese el numero de acuerdo a la operacion que desea realizar:\n");
        printf("1.Ingresar operando. A = %d\n",a);
        printf("2.Ingresar operando. B = %d\n",b);
        printf("3.Elija una operacion\n");
        printf("4.Resultado\n");
        printf("5.Salir\n");

        scanf("%d",&seleccion);


        switch (seleccion)
        {
            case 1:
            {
                printf("Ingrese primer operando\n");
                scanf("%d",&a);
                break;
            }
            case 2:
            {
                printf("Ingrese segundo operando\n");
                scanf("%d",&b);
                break;
            }
            case 3:
            {
                printf("1.Suma\n");
                printf("2.Resta\n");
                printf("3.Multiplicacion\n");
                printf("4.Division\n");
                printf("5.Factorial\n");

                scanf("%d",&operacion);
                break;
            }
            case 4:
            {

                 switch (operacion)
                {
                    case 1:
                    {
                        suma(a,b);
                        break;
                    }

                    case 2:
                    {
                        resta(a,b);
                        break;
                    }

                    case 3:
                    {
                        multiplicacion(a,b);
                        break;
                    }

                    case 4:
                    {
                        division(a,b);
                        break;
                    }

                    case 5:
                    {
                        factorial(a,b);
                        break;
                    }

                }

            }
        }
    }
    return 0;
}
