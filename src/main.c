#include "raylib.h"
#include <stdio.h>
#include <stdbool.h>
#include "animacion.h"
#include <math.h>
#include "player.h"
//fila 2 en 1X 36Y
//fila 3 en el +68Y
// fila 4 en el +104Y y +1X 136
int main(void) {
    (void)anim_run_front;
    (void)anim_run_back;
    (void)anim_run_side;
    (void)player;
    
     // Inicialización
    const int screenWidth = 600; 
    const int screenHeight = 600; 
    InitWindow(screenWidth, screenHeight, "raylib [core] ejemplo - ventana básica");

     Texture2D player_textura = LoadTexture("assets/minish.png");
    
    SetTargetFPS(80);         
    while (!WindowShouldClose()) {  // Detecta si se presiona el botón de cerrar o la tecla ESC
       
        //actualizacion input
        velocidad_personaje(&player);

        actualizar_input_jugador(player.anim_active);
       
        // Actualización juego

       animacion_update(player.anim_active);

        // Dibujado
        BeginDrawing();
       
        ClearBackground(BROWN); // Limpia el fondo con color
        Rectangle frame = animacion_frame(player.anim_active, 10);

        DrawTexturePro(player_textura,frame,
            (Rectangle){player.posicion.x,player.posicion.y,128,128}, (Vector2){64,128}, 0.0f, WHITE);

        EndDrawing();
    }
    UnloadTexture(player_textura);
    CloseWindow();   
    return 0;
}
