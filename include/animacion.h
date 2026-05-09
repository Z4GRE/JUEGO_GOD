# pragma once
typedef struct animacion{
    int primer_frame; //primero
    int ultimo_frame; //ultimo   
    int actual_frame; //actual
    float duracion_frame; // cuanto dura el frame de la animacion
    float siguiente_frame;  //timer de cuando se actualiza el siguente frame de la animacion... creo
    float tamaño_frame; 
    float setY;
    float setX; 
    
}   animacion;

extern animacion anim_idle;
extern animacion anim_run_front;
extern animacion anim_run_side;
extern animacion anim_run_back;
 // guardo todos los tipos de animaciones posibles en el bucle

struct Player;

void animacion_update(struct Player* s);
Rectangle animacion_frame(struct Player*s);
void actualizar_input_jugador(struct Player* s);
void inicializar_animaciones(); //decide la animacion actual en el frame
void elegir_estado_actual(struct Player*s);


