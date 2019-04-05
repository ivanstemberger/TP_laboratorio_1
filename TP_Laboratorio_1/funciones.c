#include <stdio.h>
#include <stdlib.h>

/*
- La función suma se encarga de tomar las variables a y b, ambas integers, y las suma.El resultado lo guarda en una variable
llamada del mismo modo para luego mostrarla por pantalla.

- La función resta toma las mismas dos variables, a y b, y las resta. Nuevamente, el resultado es mostrado por pantalla.

- La función multiplicación realiza una multiplicación de las variables a y b para luego mostrarla por pantalla.

- La función división recibe las variables a y b para luego guardarlas como float en dos variables c y d, respectivamente.
Esto es para poder realizar divisiones que tengan decimales, del estilo 1/3, etc.Luego, procede a verificar que la variable
divisora no sea 0 mediante un IF.De serlo, arrojará un mensaje indicando que no se puede dividir por ese numero.
Finalmente, si el divisor es distinto de 0 se procede a realizar la división de c y d para luego mostrarla por pantalla.

- La última función, factorial, toma las variables a y b y realiza el factorial de ambas mediante un for. Ambos resultados son
guardados en dos variables distintas que posteriormente serán mostradas por pantalla.

*/


void suma(int a, int b)
{
    int resultado;

    resultado = a + b;

    printf("El resultado de A + B es: %d\n", resultado);

}

void resta (int a, int b)
{
    int resultado;

    resultado = a - b;

   printf("El resultado de A - B es: %d\n", resultado);
}

void multiplicacion (int a, int b)
{
    int resultado;

    resultado = a * b;

    printf("El resultado de A * B es: %d\n", resultado);
}

void division(int a, int b)
{
    float c = a;
    float d = b;
    float resultado;


    if (d==0)
    {
        printf("No se puede dividir por cero.\n");
    }
    else
    {
        resultado = c/d;
        printf("El resultado de A/B es: %.2f\n", resultado);
    }

}

void factorial (int a,int b)
{
    int i;
    int resultadoA = 1;
    int resultadoB= 1;

    for(i= 1; i<=a; i++)
    {

        resultadoA=resultadoA*i;
    }

    for(i= 1; i<=b; i++)
    {
        resultadoB=resultadoB*i;
    }


    printf("El factorial de %d es %d y el factorial de %d es %d/n", a,resultadoA,b,resultadoB);

}
