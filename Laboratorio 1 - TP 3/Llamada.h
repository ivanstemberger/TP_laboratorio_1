typedef struct
{
    int id_Llamada;
    char fecha[10];
    int numero_Cliente;
    int id_Problema;
    char solucionado[2];
}eLlamada;

eLLamada* llamada_new(void);
LinkedList* ll_filter(LinkedList* this, int(*fn)(void* element);
int filtro (int seleccion,eLlamada llamada);
int saveAsText(char* path , LinkedList* pArrayListEmployee);
