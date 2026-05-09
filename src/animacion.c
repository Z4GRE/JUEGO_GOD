#include "raylib.h"
#include "animacion.h"
#include "player.h"
#include <stdio.h>

void actualizar_input_jugador(Player* s){
  if (player.velocidad.x > 0.0f ){  s->mirando_derecha = true; }
  else if (player.velocidad.x < -0.0f ){  s->mirando_derecha = false; } 
}  
//.+
void animacion_update(Player* s) {
  float delta_time = GetFrameTime();
  s->animacion_actual->siguiente_frame -= delta_time;

  if (s->animacion_actual->siguiente_frame <= 0.0) {
    s->animacion_actual->siguiente_frame = s->animacion_actual->duracion_frame;
    s->animacion_actual->actual_frame++; 

    if (s->animacion_actual->actual_frame > s->animacion_actual->ultimo_frame) {
        s->animacion_actual->actual_frame = s->animacion_actual->primer_frame;
      }   
  }
 /* void animacion_update(Player* s) {
  float delta_time = GetFrameTime();
  s->duracion -= delta_time;

  if (s->duracion <= 0.0) {
    s->duracion = s->speed;
    s->++; 

    if (s->act > s->ult) {
        s->act = s->pri;
      }   
  }*/
  
  
}
void elegir_estado_actual(Player*s){
  if(s->state == RUN){
    switch (s->direccion) {
      case IDLE_UP:
        s->animacion_actual = &animaciones[IDLE_DOWN];
        break;
      case IDLE_RIGHT:
       s->animacion_actual = &animaciones[IDLE_DOWN];
      case IDLE_DOWN:
        s->animacion_actual = &animaciones[IDLE_DOWN];
        break;
      case IDLE_LEFT:
        s->animacion_actual = &animaciones[IDLE_DOWN];
        break;
      case UP:
        s->animacion_actual = &animaciones[UP];
       break;
      case RIGHT:
        s->animacion_actual = &animaciones[RIGHT];
        break;
      case DOWN:
        s->animacion_actual = &animaciones[DOWN];
        break;
       case LEFT:
        s->animacion_actual = &animaciones[LEFT];
        break;
        default:
        s->animacion_actual = &animaciones[IDLE_DOWN];
        break;
    }  
  } else {s->animacion_actual = &animaciones[IDLE_DOWN];}
}
Rectangle animacion_frame(Player* s) {
  
  float x = (s->animacion_actual->actual_frame % s->animacion_actual->ultimo_frame * s->animacion_actual->tamaño_frame);
  float y = s->animacion_actual->setY;

  float tamaño_derecha = s->animacion_actual->tamaño_frame;

  if (s->mirando_derecha ) {
    tamaño_derecha *= -1.0f;
  }

  return (Rectangle){
    .x = (float)x + s->animacion_actual->setX ,
    .y= (float)y,
    .width = tamaño_derecha,
    .height = s->animacion_actual->tamaño_frame};

} 