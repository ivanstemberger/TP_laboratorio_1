#include <stdio.h>
#include <stdlib.h>
#include "socios.h"
#include <string.h>
#include <ctype.h>




int informeTotal(eSocio socio[],int cantidad)
{
    int i;
    int contador = 0;
    int contadorFecha = 1;
    int promedio;

    for(i=0;i<cantidad;i++)
    {
        if(socio[i].isEmpty == 0)
        {
            contador++;
        }
    }

    printf("La cantidad total de Prestamos es %d \n",contador);

    for(i=0;i<cantidad;i++)
    {
        if(socio[0].fechaSocio.dia != socio[i].fechaSocio.dia || socio[0].fechaSocio.mes != socio[i].fechaSocio.mes || socio[0].fechaSocio.anno != socio[i].fechaSocio.anno)
        {
            contadorFecha++;
        }
    }

    promedio = contador/contadorFecha;

    printf("El promedio diario de Prestamos es %d \n",promedio);

    return promedio;
}

void informeDias(eSocio socio[], int cantidad)
{
    int i;
    int j;
    int promedio = informeTotal(socio,cantidad);
    int contadorFecha = 0;
    int contador = 0;

    for(i=0;i>cantidad;i++)
    {
        for(j=0;j<cantidad;j++)
        {

            if(socio[i].fechaSocio.dia == socio[j].fechaSocio.dia && socio[i].fechaSocio.mes == socio[j].fechaSocio.mes && socio[i].fechaSocio.anno == socio[j].fechaSocio.anno)
            {
                contadorFecha++;

            }
            if(contadorFecha <= promedio)
            {
                contador++;
            }
        }
    }
    printf("La cantidad de dias que no superan el promedio diario es: %d \n", contador);
}

void libroDeterminado(eSocio socio[], int codigo, ePrestamo prestamo[], int cantidadPrestamo, int cantidad)
{
    int i;
    int j;

    printf("Los socios que solicitaron el libro son: \n");
    for(i=0;i<cantidadPrestamo;i++)
    {
        if(prestamo[i].codPrestamoLibro == codigo)
        {
            for(j=0;j<cantidad;j++)
            {
                if(prestamo[i].codPrestamoSocio == socio[j].codSocio)
                {
                    printf("%d,%s,%s \n", socio[j].codSocio, socio[j].apellido, socio[j].nombre);
                }
            }

        }

    }

}

void socioDeterminado(eLibro libro[], int codigo, ePrestamo prestamo[], int cantidadPrestamo, int cantidadLibro)
{
    int i;
    int j;

    printf("El socio codigo %d ha retirado los siguientes libros: \n", codigo);

    for(i=0;i<cantidadPrestamo;i++)
    {
        if(prestamo[i].codPrestamoSocio == codigo)
        {
            for(j=0;j<cantidadLibro;j++)
            {
                if(prestamo[i].codPrestamoLibro == libro[j].codLibro)
                {
                    printf("%s \n", libro[j].titulo);
                }
            }

        }

    }

}

void listarLibroMenos(eLibro libro[], int cantidadPrestamo, int cantidadLibro, ePrestamo prestamo[])
{
    int i;
    int j;
    int lista[10];
    int contador = 0;
    int minimoAux;
    eLibro libroAux;

    for(i=0;i<cantidadLibro;i++)
    {
        for(j=0;i<cantidadPrestamo;i++)
        {
            if(libro[i].codLibro == prestamo[j].codPrestamoLibro)
            {
                contador++;
            }
        }
        lista[i] = contador;
    }

    for(i=0;i<cantidadLibro;i++)
    {
        for(j=i+1;j<cantidadLibro;j++)
        {
            if(lista[i] > lista[j])
            {
                minimoAux = lista[i];
                lista[i] = lista[j];
                lista[j] = minimoAux;

                libroAux = libro[i];
                libro[i] = libro[j];
                libro[j] = libroAux;
            }

        }
    }

    printf("El/los libro/s menos solicitado es/son:\n %s \n" , libro[0].titulo);

    for(i=0;i<cantidadLibro;i++)
    {
        if(lista[i] == lista[i+1])
        {
            printf("%s \n",libro[i+1].titulo);
        }
    }


}

void listarSocioMas(eSocio socio[], int cantidad, int cantidadPrestamo, ePrestamo prestamo[])
{
    int i;
    int j;
    int lista[10];
    int contador = 0;
    int maximoAux;
    eSocio socioAux;

    for(i=0;i<cantidad;i++)
    {
        for(j=0;i<cantidadPrestamo;i++)
        {
            if(socio[i].codSocio == prestamo[j].codPrestamoSocio)
            {
                contador++;
            }
        }
        lista[i] = contador;
    }

    for(i=0;i<cantidad;i++)
    {
        for(j=i+1;j<cantidad;j++)
        {
            if(lista[i] < lista[j])
            {
                maximoAux = lista[i];
                lista[i] = lista[j];
                lista[j] = maximoAux;

                socioAux = socio[i];
                socio[i] = socio[j];
                socio[j] = socioAux;
            }

        }
    }

    printf("El/los socio/s con mas solicitudes de libros es/son:\n %d, %s, %s \n" , socio[0].codSocio, socio[0].apellido, socio[0].nombre);

    for(i=0;i<cantidad;i++)
    {
        if(lista[i] == lista[i+1])
        {
            printf("%d, %s, %s \n", socio[i+1].codSocio, socio[i+1].apellido, socio[i+1].nombre);
        }
    }

}
void prestamoFechaLibro(ePrestamo prestamo[], eFecha fecha, int cantidadPrestamo, int cantidadLibro, eLibro libro[])
{
    int i;
    int j;
    printf("Los libros solicitados en esta fecha fueron: \n");

    for(i=0;i<cantidadPrestamo;i++)
    {
        if(fecha.dia == prestamo[i].fechaPrestamo.dia && fecha.mes == prestamo[i].fechaPrestamo.mes && fecha.anno == prestamo[i].fechaPrestamo.anno)
        {
            for(j=0;j<cantidadLibro;j++)
            {
                if(prestamo[i].codPrestamoLibro == libro[j].codLibro)
                {
                    printf("%s \n",libro[j].titulo);
                }
            }


        }
    }


}

void prestamoFechaSocio(ePrestamo prestamo[], eFecha fecha, int cantidad, int cantidadPrestamo, eSocio socio[])
{
    int i;
    int j;

    printf("Los socios que solicitaron al menos un libro en esta fecha fueron: \n");

    for(i=0;i<cantidadPrestamo;i++)
    {
        if(fecha.dia == prestamo[i].fechaPrestamo.dia && fecha.mes == prestamo[i].fechaPrestamo.mes && fecha.anno == prestamo[i].fechaPrestamo.anno)
        {
            for(j=0;j<cantidad;j++)
            {
                if(prestamo[i].codPrestamoSocio == socio[j].codSocio && socio[j].isEmpty == 0)
                {
                    printf("%d, %s, %s \n",socio[j].codSocio, socio[j].apellido, socio[j].nombre);
                }
            }

        }
    }


}

void titulosDescenciente (eLibro libro[], int cantidadLibro)
{
    int i;
    int flag = 1;
    eLibro libroAux;

    while(flag == 1)
    {
        flag = 0;
        for(i=1;i<cantidadLibro;i++)
        {
            if(strcmp(libro[i].titulo,libro[i-1].titulo)>0)
            {
                libroAux = libro[i];
                libro[i] = libro[i+1];
                libro[i+1] = libroAux;
                flag = 1;
            }
        }
    }
    for(i=0;i<cantidadLibro;i++)
    {
        printf("%s \n", libro[i].titulo);
    }
}

void apellidoAscendiente(eSocio socio[],int cantidad)
{
    int i;
    int j;
    eSocio socioAux;

    for(i=1;i<cantidad;i++)
    {
        socioAux = socio[i];
        j = i-1;

        while(j<=0 && strcmp(socioAux.apellido,socio[j].apellido)>0)
        {
            socio[j+1] = socio[j];
            j--;
        }
        socio[j+1] = socioAux;
    }

    for(i=0;i<cantidad;i++)
    {
        printf("%d, %s, %s \n",socio[i].codSocio,socio[i].apellido,socio[i].nombre);
    }
}

void seleccionInformes(ePrestamo prestamo[], eSocio socio[], eLibro libro[], eAutor autor[], int cantidad, int cantidadPrestamo, int cantidadLibro, int cantidadAutor)
{
    int seleccion;
    int codigo;
    eFecha fechaAux;

    printf("Seleccione una opcion:\n"
    "1) Total general y Promedio diario de solicitudes a prestamo de los libros.\n"
    "2) Cantidad de dias cuya solicitud a prestamo NO superan el promedio diario.\n"
    "3) Lista de socios que solicitaron un libro determinado.\n"
    "4) Lista de libros solicitados por un socio determinado.\n"
    "5) Lista de libros menos solicitados.\n"
    "6) Lista de socios que mayor cantidad de solicitudes han realizado.\n"
    "7) Lista de libros solicitados a prestamo en una fecha determinada.\n"
    "8) Lista de socios que solicitaron un prestamo en una fecha determinada.\n"
    "9) Lista de libros ordenados por titulo descendiente.\n"
    "10)Lista de socios ordenados por apellido ascendiente.\n");
    scanf("%d",&seleccion);

    switch (seleccion)
    {
        case 1:
        {
            informeTotal(socio,cantidadPrestamo);
            break;
        }
        case 2:
        {
            informeDias(socio,cantidadPrestamo);
            break;
        }
        case 3:
        {
            printf("Por favor ingrese el codigo del libro: \n");
            scanf("%d",&codigo);
            libroDeterminado(socio,codigo,prestamo,cantidadPrestamo, cantidad);
            break;
        }
        case 4:
        {
            printf("Por favor ingrese el codigo del socio: \n");
            scanf("%d",&codigo);
            socioDeterminado(libro,codigo,prestamo,cantidadPrestamo, cantidadLibro);
            break;
        }
        case 5:
        {
            listarLibroMenos(libro,cantidadPrestamo,cantidadLibro,prestamo);
            break;
        }
        case 6:
        {
            listarSocioMas(socio,cantidad, cantidadPrestamo, prestamo);
            break;
        }
        case 7:
        {
            printf("Por favor introduzca el dia\n");
            scanf("%d",&fechaAux.dia);
            printf("Por favor introduzca el mes\n");
            scanf("%d",&fechaAux.mes);
            printf("Por favor introduzca el anno\n");
            scanf("%d",&fechaAux.anno);

            prestamoFechaLibro(prestamo,fechaAux,cantidadPrestamo, cantidadLibro, libro);
            break;
        }
        case 8:
        {
            printf("Por favor introduzca el dia\n");
            scanf("%d",&fechaAux.dia);
            printf("Por favor introduzca el mes\n");
            scanf("%d",&fechaAux.mes);
            printf("Por favor introduzca el anno\n");
            scanf("%d",&fechaAux.anno);

            prestamoFechaSocio(prestamo,fechaAux,cantidad,cantidadPrestamo,socio);
            break;
        }
        case 9:
        {
            titulosDescenciente (libro,cantidadLibro);
            break;
        }
        case 10:
        {
            apellidoAscendiente(socio,cantidad);
            break;
        }
    }

}
