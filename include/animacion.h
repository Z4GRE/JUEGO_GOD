# pragma once
typedef struct animacion{
    int pri; //primero
    int ult; //ultimo   
    int act; //actual
    float speed; // cuanto dura el frame de la animacion
    float duracion;  //timer de cuando se actualiza el siguente frame de la animacion... creo
    float tamaño_frame; 
    float setY;
    float setX; 
    bool mirando_derecha; 
}   animacion;

void animacion_update(animacion* s);
Rectangle animacion_frame(animacion* s, int numero_frames_ciclo);
void actualizar_input_jugador(animacion* s);

