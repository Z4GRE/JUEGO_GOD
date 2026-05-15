# pragma once
# include "raylib.h"
typedef struct Circulo{
Vector2 centro;
float radio;
Color hitbox_color;
Vector2 offset;
} Circulo;

struct Player;
extern Circulo hitbox_jugador;

void actualizar_hitbox_jugador(struct Player* s);