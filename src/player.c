#include "raylib.h"
#include "player.h"
#include "animacion.h"
#include <math.h>
#include <stdio.h>
Player player = (Player) {
    .posicion = (Vector2){280.0f,330.0f},
    .velocidad = (Vector2){0.0f,0.0f},
    .speed_stat = 300.0f,
    .state = IDLE,
    .direccion = DOWN,
    .animacion_actual = &anim_idle_front,
    .ultima_direccion = IDLE_DOWN,
    .mirando_derecha = 1.0f,
};       


animacion anim_idle_front = (animacion) {
    .primer_frame = PRIMER_FRAME,
    .ultimo_frame = 1,
    .actual_frame = 0,
    .duracion_frame = DURACION_RUN_FRAME,
    .siguiente_frame = 0,
    .tamaño_frame = TAMAÑO_FRAME,
    .setY= 0.0f,
    .setX= 9.5f,
};
animacion anim_idle_back = (animacion) {
    .primer_frame = PRIMER_FRAME,
    .ultimo_frame = 1,
    .actual_frame = 0,
    .duracion_frame = DURACION_RUN_FRAME,
    .siguiente_frame = 0,
    .tamaño_frame = TAMAÑO_FRAME,
    .setY= 0.0f,
    .setX= 76.0f,
};
animacion anim_idle_side = (animacion) {
    .primer_frame = PRIMER_FRAME,
    .ultimo_frame = 1,
    .actual_frame = 0,
    .duracion_frame = DURACION_RUN_FRAME,
    .siguiente_frame = 0,
    .tamaño_frame = TAMAÑO_FRAME,
    .setY= 0.0f,
    .setX= 36.0f,

};

animacion anim_run_front = (animacion) { //animacion de correr de frente
    .primer_frame = 0,
    .ultimo_frame = 9,
    .actual_frame = 0,
    .duracion_frame = DURACION_RUN_FRAME,
    .siguiente_frame = 0.,
    .tamaño_frame = TAMAÑO_FRAME,
    .setY= 68.0f,
    .setX= 9.5f,
};    


animacion anim_run_side = (animacion) {
    .primer_frame = 0,
    .ultimo_frame = 9,
    .actual_frame = 0,
    .duracion_frame = DURACION_RUN_FRAME,
    .siguiente_frame = 0,
    .tamaño_frame = TAMAÑO_FRAME,
    .setY= 68.0f,
    .setX= 341.2f,  
};    

animacion anim_run_back = (animacion) {
    .primer_frame = 0,
    .ultimo_frame =9,
    .actual_frame = 0,
    .duracion_frame = DURACION_RUN_FRAME,
    .siguiente_frame = 0,
    .tamaño_frame = TAMAÑO_FRAME,
    .setY= 71.0f,
    .setX= 678.0f,
};
animacion animaciones[MAX_ANIMACIONES];

void inicializar_animaciones(){
    animaciones[IDLE_UP] = anim_idle_back;
    animaciones[IDLE_RIGHT] = anim_idle_side;
    animaciones[IDLE_DOWN] = anim_idle_front;
    animaciones[IDLE_LEFT] = anim_idle_side;
    animaciones[UP] = anim_run_back; 
    animaciones[RIGHT] = anim_run_side;
    animaciones[DOWN] = anim_run_front;
    animaciones[LEFT] = anim_run_side;
}
void velocidad_estado_personaje(Player *p) {
    if(player.velocidad.x == 0 || player.velocidad.y == 0){
        p->state = IDLE;
        if (p->direccion == UP)      {  p->ultima_direccion = IDLE_UP;   }
        else if (p->direccion == DOWN) {  p->ultima_direccion = IDLE_DOWN; }    
        else if (p->direccion == RIGHT) {  p->ultima_direccion = IDLE_RIGHT; }
        else if (p->direccion == LEFT) {  p->ultima_direccion = IDLE_LEFT; } 
    }

    player.velocidad.x = 0.0f;
    player.velocidad.y = 0.0f;

    if (IsKeyDown(KEY_UP))      player.velocidad.y -=1.0f; 
    if (IsKeyDown(KEY_DOWN))    player.velocidad.y +=1.0f; 
    if (IsKeyDown(KEY_RIGHT))   player.velocidad.x +=1.0f; 
    if (IsKeyDown(KEY_LEFT))    player.velocidad.x -=1.0f; 

    if(player.velocidad.x != 0 || player.velocidad.y != 0){
        p->state = RUN;
        if (player.velocidad.y < 0)      {  p->direccion = UP;   }
        else if (player.velocidad.y > 0) {  p->direccion = DOWN; }    
        else if (player.velocidad.x > 0) { p->direccion = RIGHT; }
        else if (player.velocidad.x < 0) { p->direccion = LEFT;  } 
    

    float pitagoras = sqrt(player.velocidad.x * player.velocidad.x + player.velocidad.y * player.velocidad.y);

    if (pitagoras > 0 ){
        player.velocidad.x /= pitagoras;
        player.velocidad.y /= pitagoras; 
    }    
        player.posicion.y += player.velocidad.y * player.speed_stat * GetFrameTime();    
        player.posicion.x += player.velocidad.x * player.speed_stat * GetFrameTime(); 
    }
}    
