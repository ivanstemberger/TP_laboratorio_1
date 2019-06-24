typedef struct {
    int codAutor;
    char apellido[31];
    char nombre[31];
}eAutor;

typedef struct{
    int codLibro;
    char titulo[31];
    int codAutor;
}eLibro;


typedef struct{
    int dia;
    int mes;
    int anno;
}eFecha;

typedef struct{
    int codSocio;
    char apellido[31];
    char nombre[31];
    char sexo;
    char telefono[16];
    char mail[31];
    eFecha fechaSocio;
    int isEmpty;
}eSocio;


typedef struct {
    int codPrestamo;
    int codPrestamoLibro;
    int codPrestamoSocio;
    eFecha fechaPrestamo;
}ePrestamo;


void inicializar(eSocio socio[],int cantidad);
void inicializarPrestamo(ePrestamo prestamo[],int cantidadPrestamo);
void alta (eSocio socio[],int cantidad);
void modSocio(eSocio socio[],int cantidad);
void bajaSocio(eSocio socio[],int cantidad);
void listarSocio(eSocio socio[], int cantidad);
void mostrarLista(eSocio socio[],int cantidad);
void listaLibro(eLibro libro[], int cantidad);
void listaAutor(eAutor autor[], int cantidad);
void altaPrestamo(eLibro libro[], eSocio socio[],ePrestamo prestamo[], int cantidad);
