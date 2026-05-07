#include "raylib.h"
#include "animacion.h"
#include "player.h"

void actualizar_input_jugador(animacion* s){
  if (player.velocidad.x > 0.0f ){  s->mirando_derecha = true; }
  if (player.velocidad.x < -0.0f ){  s->mirando_derecha = false; } 
}  

void animacion_update(animacion* s) {
  float delta_time = GetFrameTime();
  s->duracion -= delta_time;

  if (s->duracion <= 0.0) {
    s->duracion = s->speed;
    s->act++; 

    if (s->act > s->ult) {
        s->act = s->pri;
      }   
  }
  
}

Rectangle animacion_frame(animacion* s, int numero_frames_ciclo) {
  float x = (s->act % numero_frames_ciclo * s->tamaño_frame);
  float y = s->setY;

  float tamaño_derecha = s->tamaño_frame;

  if (s->mirando_derecha ) {
    tamaño_derecha *= -1.0f;
  }

  return (Rectangle){
    .x = (float)x + s->setX ,
    .y= (float)y,
    .width = tamaño_derecha,
    .height = s->tamaño_frame};


}


