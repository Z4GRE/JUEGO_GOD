#pragma once
#include "raylib.h"
#include "animacion.h"
#include <stdio.h>
#define PIVOTE_X -6.0f
#define PIVOTE_Y 19.0f


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
struct Circulo;


typedef struct Player { //se encarga de todo lo del jugador y la mierda random que no se donde poner XDDDDDDDDD
    Vector2 posicion;  // x, y
    Vector2 velocidad; // hacia donde se mueve
    float speed_stat;  // qué tan rápido corre
    player_state state; // en que estado esta el personaje
    player_direccion direccion;// hacia donde apunta el personaje   
    player_direccion ultima_direccion; //donde miro en lo ultimo
    struct animacion *animacion_actual;   //la... animacion actual XD que mas voy a poner      
    bool mirando_derecha;
    struct Circulo *poscicion_hitbox;
    Vector2 pivote;
    //-6 19
}   Player;   

extern Player player;
extern  struct Circulo hitbox_jugador;
extern animacion animaciones[MAX_ANIMACIONES];

void velocidad_estado_personaje(Player* s); //mueve al personaje en de posicion
void state_player(Player *p);