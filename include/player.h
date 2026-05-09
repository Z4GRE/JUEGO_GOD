#pragma once
#include "raylib.h"
#include "animacion.h"


typedef enum { 
    IDLE, 
    RUN, 
    ATTACK,
    DEATH
} player_state;

typedef enum { 
    IDLE_UP, IDLE_RIGHT, IDLE_DOWN, IDLE_LEFT,
    UP,  RIGHT,  DOWN, LEFT,
    MAX_ANIMACIONES
   
} player_direccion;
struct animacion;
typedef struct Player { //se encarga de todo lo del jugador y la mierda random que no se donde poner XDDDDDDDDD
    Vector2 posicion;  // x, y
    Vector2 velocidad; // hacia donde se mueve
    float speed_stat;  // qué tan rápido corre
    player_state state; // en que estado esta el personaje
    player_direccion direccion;// hacia donde apunta el personaje   
    player_direccion ultima_direccion; //donde miro en lo ultimo
    struct animacion *animacion_actual;   //la... animacion actual XD que mas voy a poner      
    float mirando_derecha;               
}   Player;   

extern Player player;
extern animacion animaciones[MAX_ANIMACIONES];

void velocidad_estado_personaje(Player* s); //mueve al personaje en de posicion
void state_player(Player *p);
