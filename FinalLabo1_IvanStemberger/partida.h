typedef struct
{
    int id_partida;
    char fecha[10];
    int tipo_juego;
    int cantidad_jugadores;
    int duracion_partida;
    int costo;
}ePartida;

ePartida* partida_new(void);
void promedio(void* pElement);
