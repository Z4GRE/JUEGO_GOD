#include "raylib.h"
#include "player.h"
#include "animacion.h"
#include <math.h>
   
Player player = (Player) {
    .posicion = (Vector2){280.0f,330.0f},
    .velocidad = (Vector2){0.0f,0.0f},
    .speed_stat = 360.0f,
    .anim_active = &anim_idle,
};
animacion anim_idle = (animacion) {
    .pri = 0,
    .ult = 0,
    .act = 0,
    .speed = 0.1,
    .duracion = 0.105,
    .tamaño_frame = 32.0,
    .setY= 0.0f,
    .setX= 1.5f,
};
animacion anim_run_front = (animacion) { //animacion de correr de frente
    .pri = 0,
    .ult = 9,
    .act = 0,
    .speed = 0.12,
    .duracion = 0.105,
    .tamaño_frame = 32.0,
    .setY= 68.0f,
    .setX= 7.5f,
};    

animacion anim_run_side = (animacion) {
    .pri = 0,
    .ult = 9,
    .act = 0,
    .speed = 0.12,
    .duracion = 0.105,
    .tamaño_frame = 32.0,
    .setY= 68.0f,
    .setX= 345.5f,
    .mirando_derecha = true,     
};    
animacion anim_run_back = (animacion) {
    .pri = 0,
    .ult =9,
    .act = 0,
    .speed = 0.12,
    .duracion = 0.105,
    .tamaño_frame = 32.0,
    .setY= 71.0f,
    .setX= 675.f,
};

void velocidad_personaje(Player *p) {
    player.velocidad.x = 0.0f;
    player.velocidad.y = 0.0f;

    if (IsKeyDown(KEY_UP))     { player.velocidad.y -=1.0f; }
    if (IsKeyDown(KEY_RIGHT))  { player.velocidad.x +=1.0f; }
    if (IsKeyDown(KEY_DOWN))   { player.velocidad.y +=1.0f; }
    if (IsKeyDown(KEY_LEFT))   { player.velocidad.x -=1.0f; }

    if (player.velocidad.x != 0.0f || player.velocidad.y != 0.0f) {
        if (player.velocidad.y > 0.0f){player.anim_active = &anim_run_front;}    
        else if(player.velocidad.y < -0.0f){ player.anim_active = &anim_run_back;} 
        else { player.anim_active = &anim_run_side;}   
    }else { player.anim_active = &anim_idle;}            
     
    float pitagoras = sqrt(player.velocidad.x * player.velocidad.x + player.velocidad.y * player.velocidad.y);

    if (pitagoras > 0 ){
        player.velocidad.x /= pitagoras;
        player.velocidad.y /= pitagoras; }
    player.posicion.y += player.velocidad.y * player.speed_stat * GetFrameTime();    
    player.posicion.x += player.velocidad.x * player.speed_stat * GetFrameTime(); 
    }
void estado_animacion(PlayerDir*p) {


}
