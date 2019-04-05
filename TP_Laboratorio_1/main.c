#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/*
Esta calculadora está creada con las siguientes funcionalidades:

En primer lugar, un bucle "while" que seguirá corriendo muientras el valor de la variable "selección" no sea 5 (salir).

Inicialmente se mostrará un menú con 5 opciones:
1) Ingresar un operando (A).
2) Ingresar otro operando (B).
3) Elejir una operación (Suma, Resta, División, Multiplicación, Factorial).
4) Arrojar el resultado.
5) Salir.


Cade selección realizada al presionar alguno de los números (1 al 5) se guardará en la variable integer "seleccion". A partir de esta, se pasará a un
switch que, en función de lo ingresado, permitirá realizar la acción deseada.
Las primeras dos opciones van a guardar el número ingresado en las variables de tipo integer a y b, respectivamente.
La opción tres desplegará un segundo menú para elegir la operación. Esta elección se guardará en una variable int llamada "operacion".
La cuarta opción arrojará el resultado en función de la operación seleccionada. Esto se realiza llamando a la función correspondiente,
Finalmente, la quinta opción, Salir. Al seleccionarla, se saldrá del bucle inicial y el programa finalizará.

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
