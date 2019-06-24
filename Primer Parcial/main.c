#include <stdio.h>
#include <stdlib.h>
#include "socios.h"
#include "listar.h"
#define CANT 100
#define CANTP 100

int main()
{
    eSocio socio[CANT];
    eAutor autor[5] = {{1,"Tolkien","John"},{2,"Borges","Jorge"},{3,"Cortazar","Julio"},{4,"Patrick","Rothfuss"},{5,"Adolfo","Casares"}};
    eLibro libro[10]={{1,"El Hobbit",1},{2,"La comunidad del anillo.",1},{3,"Las dos Torres.",1},{4,"El retorno del Rey",1},{5,"El Aleph",2},{6,"Ruinas Circulares",2},{7,"Rayuela",3},{8,"El nombre del viento",4},{9,"El temor de un hombre sabio",4},{10,"Obra completa I",5}};
    ePrestamo prestamo[CANTP];
    int seleccion;

    inicializar(socio,CANT);
    inicializarPrestamo(prestamo,CANTP);
    printf("Para poder continuar debe dar de alta al menos a un socio. \n");
    alta(socio,CANT);

    do
    {
        printf("Por favor seleccione una opcion. \n1) Dar de alta un socio. \n2) Modificar un socio. \n3) Dar de baja un socio. \n4) Listar socios. \n5) Listar libros. \n6) Listar autores. \n7) Prestamos. \n8) Informes \n9)Salir \n");
        scanf("%d",&seleccion);

        switch(seleccion)
        {
        case 1:
            {
                alta(socio,CANT);
                break;
            }
        case 2:
            {
                modSocio(socio,CANT);
                break;
            }
        case 3:
            {
                bajaSocio(socio,CANT);
                break;
            }
        case 4:
            {
                listarSocio(socio,CANT);
                break;
            }
        case 5:
            {
                listaLibro(libro,10);
                break;
            }
        case 6:
            {
                listaAutor(autor,5);
                break;
            }
        case 7:
            {
                altaPrestamo(libro,socio,prestamo,CANTP);
                break;
            }
        case 8:
            {
                seleccionInformes(prestamo,socio,libro,autor,CANT,CANTP,10,5);
            }
        }

    }while(seleccion != 9);


    return 0;
}
