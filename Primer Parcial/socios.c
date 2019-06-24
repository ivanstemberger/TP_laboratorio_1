#include <stdio.h>
#include <stdlib.h>
#include "socios.h"
#include "validaciones.h"
#include <string.h>
#include <ctype.h>


void listaAutor(eAutor autor[], int cantidad)
{
    int i;
    int j;
    char aux[31];

    printf("Codigo de Autor ||  Apellido  ||  Nombre \n");

    for(i=0;i<cantidad;i++)
    {
        for(j=i+1;j<cantidad;j++)

        if(strcmp(autor[i].apellido,autor[j].apellido)>1)
        {
            strcpy(aux,autor[i].apellido);
            strcpy(autor[i].apellido,autor[j].apellido);
            strcpy(autor[j].apellido,aux);
        }
        else if(strcmp(autor[i].apellido,autor[j].apellido) == 0)
        {
            if(strcmp(autor[i].nombre,autor[j].nombre)>1)
            {
                strcpy(aux,autor[i].nombre);
                strcpy(autor[i].nombre,autor[j].nombre);
                strcpy(autor[j].nombre,aux);
            }

        }
    }
    for(i=0;i<cantidad;i++)
    {
        printf("%d  ||  %s  || %s \n",autor[i].codAutor,autor[i].apellido,autor[i].nombre);
    }
}

void listaLibro(eLibro libro[], int cantidad)
{
    int i;
    int j;
    char aux[31];

    printf("Codigo de Libro ||  Titulo  ||  Codigo de Autor \n");

    for(i=0;i<cantidad;i++)
    {
        for(j=i+1;j<cantidad;j++)

        if(strcmp(libro[i].titulo,libro[j].titulo)>1)
        {
            strcpy(aux,libro[i].titulo);
            strcpy(libro[i].titulo,libro[j].titulo);
            strcpy(libro[j].titulo,aux);
        }

    }
    for(i=0;i<cantidad;i++)
    {
        printf("%d  ||  %s  || %d \n",libro[i].codLibro,libro[i].titulo,libro[i].codAutor);
    }
}

void inicializarPrestamo(ePrestamo prestamo[], int cantidad)
{
    int i;

    for(i=0;i<cantidad;i++)
    {
        prestamo[i].codPrestamo = 0;
        prestamo[i].codPrestamoSocio = 0;
        prestamo[i].codPrestamoLibro = 0;
        prestamo[i].fechaPrestamo.dia = 0;
        prestamo[i].fechaPrestamo.mes = 0;
        prestamo[i].fechaPrestamo.anno = 0;
    }

}

void altaPrestamo(eLibro libro[], eSocio socio[], ePrestamo prestamo[], int cantidad)
{

    char auxDia[2];
    char auxMes[2];
    char auxYear[4];
    int i;


    for(i=0;i<cantidad;i++)
    {
        if(prestamo[i].codPrestamo == 0)
        {
            prestamo[i].codPrestamo++;

            printf("Ingrese el código del libro: \n");
            scanf("%d",&prestamo[i].codPrestamoLibro);

            printf("Ingrese el código del socio: \n");
            scanf("%d",&prestamo[i].codPrestamoSocio);

            printf("intruduzca el dia: \n");
            gets(auxDia);

            while(!validacionDia(auxDia))
            {
                printf("intruduzca el dia: \n");
                gets(auxDia);

            }
            prestamo[i].fechaPrestamo.dia = atoi(auxDia);


            printf("intruduzca el mes: \n");
            gets(auxMes);

            while(!validacionDia(auxMes))
            {
                printf("intruduzca el mes: \n");
                gets(auxMes);
            }

            prestamo[i].fechaPrestamo.mes = atoi(auxMes);


            printf("intruduzca el anno: \n");
            gets(auxYear);

            while(!validacionYear(auxYear))
            {
                printf("intruduzca el anno: \n");
                gets(auxYear);

            }
            prestamo[i].fechaPrestamo.anno = atoi(auxYear);

            break;
        }
    }


}


void inicializar(eSocio socio[],int cantidad)
{
    int i;

    for(i=0;i<cantidad;i++)
    {
        socio[i].isEmpty = 1;
        socio[i].codSocio = 0;
    }
}

void alta(eSocio socio[],int cantidad)
{
    int i;
    char auxNombre[31];
    char auxApellido[31];
    char auxSexo;
    char auxTelefono[16];
    char auxMail[31];
    char auxDia[2];
    char auxMes[2];
    char auxYear[4];
    char salir;


    for(i=0;i<cantidad;i++)
    {
        if(socio[i].isEmpty == 1)
        {
            socio[i].codSocio = i + 1;

            printf("Por favor, introduzca el apellido del socio: \n");
            fflush(stdin);
            gets(auxApellido);

            while(!validacionSocio(auxApellido) || !validacionLargo(auxApellido))
            {
                printf("Por favor, introduzca el apellido del socio: \n");
                fflush(stdin);
                gets(auxApellido);
            }
            strcpy(socio[i].apellido,auxApellido);

            printf("Por favor, introduzca el nombre del socio: \n");
            fflush(stdin);
            gets(auxNombre);

            while(!validacionSocio(auxNombre) || !validacionLargo(auxNombre))
            {
                printf("Por favor, introduzca el nombre del socio: \n");
                fflush(stdin);
                gets(auxNombre);
            }
            strcpy(socio[i].nombre,auxNombre);

            printf("Por favor, introduzca el sexo (m/f): \n");
            fflush(stdin);
            scanf("%c", &auxSexo);

            while(!validacionSexo(auxSexo))
            {
                printf("Por favor, introduzca el sexo del socio: \n");
                fflush(stdin);
                scanf("%c", &auxSexo);
            }

            socio[i].sexo = auxSexo;

            printf("Por favor, introduzca el telefono: \n");
            fflush(stdin);
            gets(auxTelefono);


            while(!validacionTelefono(auxTelefono))
            {
                printf("Por favor, introduzca el telefono: \n");
                fflush(stdin);
                gets(auxTelefono);
            }

            strcpy(socio[i].telefono,auxTelefono);

            printf("Por favor, introduzca el email: \n");
            fflush(stdin);
            gets(auxMail);


            while(!esAlfaNumerico(auxMail))
            {
                printf("Por favor, introduzca el email: \n");
                fflush(stdin);
                gets(auxMail);
            }
            strcpy(socio[i].mail,auxMail);


            printf("intruduzca el dia: \n");
            gets(auxDia);

            while(!validacionDia(auxDia))
            {
                printf("intruduzca el dia: \n");
                gets(auxDia);

            }
            socio[i].fechaSocio.dia = atoi(auxDia);


            printf("intruduzca el mes: \n");
            gets(auxMes);

            while(!validacionDia(auxMes))
            {
                printf("intruduzca el mes: \n");
                gets(auxMes);
            }

            socio[i].fechaSocio.mes = atoi(auxMes);


            printf("intruduzca el anno: \n");
            gets(auxYear);

            while(!validacionYear(auxYear))
            {
                printf("intruduzca el anno: \n");
                gets(auxYear);

            }
            socio[i].fechaSocio.anno = atoi(auxYear);

            socio[i].isEmpty = 0;

            printf("¿Desea continuar? s/n");
            scanf("%c",&salir);

            while(salir != 's' && salir != 'n' && salir != 'N' && salir != 'S')
            {
                printf("¿Desea continuar? s/n \n");
                scanf("%c",&salir);
            }

            if(salir == 'n' || salir == 'N')
            {
                break;
            }
        }

    }

}

void modSocio(eSocio socio[],int cantidad)
{
    int i;
    int codAux;
    int seleccion;

    printf("Por favor introduzca el codigo del socio: \n");
    scanf("%d",&codAux);

    for(i=0;i<cantidad;i++)
    {
        if(codAux == socio[i].codSocio)
        {
           printf("Por favor seleccione una opcion: \n1)Apellido. \n2)Nombre. \n3)Sexo. \n4)Telefono. \n5)Email.\n");
           scanf("%d",&seleccion);

           switch(seleccion)
           {
                case 1:
                {
                    printf("Introduzca el nombre: \n");
                    gets(socio[i].nombre);
                    while(!validacionSocio(socio[i].nombre) || !validacionLargo(socio[i].nombre))
                    {
                        printf("Por favor, introduzca el nombre del socio: \n");
                        fflush(stdin);
                        gets(socio[i].nombre);
                    }

                  break;
                }
                case 2:
                {
                    printf("Introduzca el apellido: \n");
                    gets(socio[i].apellido);

                    while(!validacionSocio(socio[i].apellido) || !validacionLargo(socio[i].apellido))
                    {
                        printf("Por favor, introduzca el apellido del socio: \n");
                        fflush(stdin);
                        gets(socio[i].apellido);
                    }

                    break;
                }
                case 3:
                {
                    printf("Introduzca el sexo: \n");
                    scanf("%c",&socio[i].sexo);
                    while(!validacionSexo(socio[i].sexo))
                    {
                        printf("Por favor, introduzca el sexo del socio: \n");
                        fflush(stdin);
                        scanf("%c", &socio[i].sexo);
                    }

                    break;
                }
                case 4:
                {
                    printf("Introduzca el telefono: \n");
                    gets(socio[i].telefono);
                    while(!validacionTelefono(socio[i].telefono))
                    {
                        printf("Por favor, introduzca el telefono: \n");
                        fflush(stdin);
                        gets(socio[i].telefono);
                    }

                    break;
                }
                case 5:
                {
                    printf("Introduzca el email: \n");
                    gets(socio[i].mail);
                    while(!esAlfaNumerico(socio[i].mail))
                    {
                        printf("Por favor, introduzca el email: \n");
                        fflush(stdin);
                        gets(socio[i].mail);
                    }

                    break;
                }
           }
        }
        else
        {
            printf("No se encontró el socio solicitado.\n");
            break;
        }

    }

}

void bajaSocio(eSocio socio[],int cantidad)
{
    int i;
    int codAux;

    printf("Por favor ingrese el codigo del socio que desea dar de baja: \n");
    scanf("%d",&codAux);

    for(i=0;i<cantidad;i++)
    {
        if(codAux == socio[i].codSocio)
        {
            socio[i].isEmpty = 1;
            break;
        }
        else
        {
            printf("El codigo de socio no fue encontrado.\n");
            break;
        }
    }
}

void listarSocio(eSocio socio[], int cantidad)
{
    int i;
    int j;
    eSocio socioAux;


    for(i=0;i<cantidad;i++)
    {
        if(socio[i].isEmpty == 0)
        {
            for(j=i+1;j<cantidad;j++)
            if(strcmp(socio[i].apellido,socio[j].apellido)>0)
            {

                socioAux = socio[i];
                socio[i] = socio[j];
                socio[j] = socioAux;


            }
            else if(strcmp(socio[i].apellido,socio[j].apellido) == 0)
            {
                if(strcmp(socio[i].nombre,socio[j].nombre)>1)
                {
                    socioAux = socio[i];
                    socio[i] = socio[j];
                    socio[j] = socioAux;
                }

            }
        }
    }

    mostrarLista(socio,cantidad);

}
void mostrarLista(eSocio socio[],int cantidad)
{
        int i;

        for(i=0;i<=cantidad;i++)
        {

            printf("Codigo de Socio|Apellido|Nombre|Sexo|Telefono|Email|Fecha de Ingreso \n");
            printf("%d|%s|%s|%c|%s|%s|%d/%d/%d \n",  socio[i].codSocio,socio[i].apellido,socio[i].nombre,socio[i].sexo,socio[i].telefono,socio[i].mail,socio[i].fechaSocio.dia,socio[i].fechaSocio.mes,socio[i].fechaSocio.anno);

        }

}


