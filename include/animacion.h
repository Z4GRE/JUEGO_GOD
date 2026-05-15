# pragma once
#define DURACION_RUN_FRAME 0.07
#define TAMAÑO_FRAME 32.0
#define PRIMER_FRAME 0
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

extern animacion anim_idle_front;
extern animacion anim_idle_back;
extern animacion anim_idle_side;
extern animacion anim_run_front;
extern animacion anim_run_side;
extern animacion anim_run_back;
 // guardo todos los tipos de animaciones posibles en el bucle

struct Player;


void animacion_update(struct Player* s); //bucle de repeticion de frames
Rectangle animacion_frame(struct Player*s); //dibuja el bucle de las animaciones
void actualizar_izquierda_derecha(struct Player* s); // dice si el personaje esta mirando o a la derecha o la izquierda
void inicializar_animaciones(); //decide la animacion actual en el frame
void elegir_estado_actual(struct Player*s);