#include "raylib.h"
#include <stdio.h>
#include <stdbool.h>
#include "animacion.h"
#include <math.h>
#include "player.h"
#include "colisiones.h"
//fila 2 en 1X 36Y
//fila 3 en el +68Y
// fila 4 en el +104Y y +1X 136
int main(void) {
    (void)anim_run_front;
    (void)anim_run_back;
    (void)anim_run_side;
    (void)player;
    
     // Inicialización
    const int screenWidth = 700; 
    const int screenHeight = 700; 
    InitWindow(screenWidth, screenHeight, "raylib [core] ejemplo - ventana básica");

     Texture2D player_textura = LoadTexture("assets/minish.png");
    inicializar_animaciones();
    SetTargetFPS(100);         
    while (!WindowShouldClose()) {  // Detecta si se presiona el botón de cerrar o la tecla ESC
        
        //actualizacion input
       
        velocidad_estado_personaje(&player); 
        
        
       //puts("primer punto");
        // Actualización juego
       
        elegir_estado_actual(&player);
        animacion_update(&player);
        actualizar_izquierda_derecha(&player);

        // Dibujado
        BeginDrawing();
       //puts("segundo punto");
        ClearBackground(BROWN); // Limpia el fondo con color
        Rectangle frame = animacion_frame(&player);
       // puts("tercer punto");
       
       
        DrawTexturePro(player_textura,frame,
            (Rectangle){player.posicion.x,player.posicion.y,128,128}, player.pivote, 0.0f, BLUE);
                                                                        //25
        //debug area XDDD    
        if(IsKeyUp(KEY_H)){    

           Rectangle dRec = { player.posicion.x, player.posicion.y, 128, 128 };    
           DrawRectangleLinesEx(dRec, 2, WHITE);
           actualizar_hitbox_jugador(&player);
        }    
      
        
        EndDrawing();

    }
    CloseWindow();   
    UnloadTexture(player_textura);
    return 0;
}


// odio esto.
//1001101