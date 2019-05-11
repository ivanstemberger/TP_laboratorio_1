

typedef struct {

int id;
char nombre[52];
char apellido[52];
float salario;
int idSector;
int isEmpty;

}eEmployee;




void inicializar(eEmployee empleado[], int cantidad);

void altaEmpleado (eEmployee empleado[], int cantidad);

void modEmpleado (eEmployee empleado[], int cantidad);

void bajaEmpleado (eEmployee empleado[], int cantidad);

void lista (eEmployee empleado[], int cantidad);

void salarios (eEmployee empleado[], int cantidad);

void mostrar (eEmployee empleado[], int cantidad);
