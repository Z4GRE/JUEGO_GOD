#pragma once
#include "raylib.h"
#include "animacion.h"

typedef enum { 
    STATE_IDLE, 
    STATE_RUN, 
    STATE_ATTACK,
    STETE_DEATH
} PlayerState;

typedef enum { 
    DIR_UP, 
    DIR_DOWN, 
    DIR_LEFT, 
    DIR_RIGHT 
} PlayerDir;

typedef struct Player {
    Vector2 posicion;  // x, y
    Vector2 velocidad; // hacia donde se mueve
    float speed_stat;  // qué tan rápido corre
    animacion *anim_active; // Puntero a la animación que debe mostrarse                           
}   Player;   

extern animacion anim_idle;
extern animacion anim_run_front;
extern animacion anim_run_side;
extern animacion anim_run_back;
extern Player player;

void velocidad_personaje(Player* s);
void estado_animacion(PlayerDir*p);