#include <stdio.h>
#include "raylib.h"
#include "colisiones.h"
#include "player.h"


Circulo hitbox_jugador = (Circulo) {
    .centro = {0.0f,0.0f},
    .radio = 12.0f * 4 ,
    .hitbox_color = RED,
    .offset.x = 64.0f,
    .offset.y = 64.0f
};

void actualizar_hitbox_jugador(Player *h ){

    DrawCircleLines(h->posicion.x + h->poscicion_hitbox->offset.x,
               h->posicion.y + h->poscicion_hitbox->offset.y,
               h->poscicion_hitbox->radio, RED);
 
}

