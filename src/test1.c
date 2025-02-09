#define RAYGUI_IMPLEMENTATION
#include "raylib.h"
#include "raygui.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    InitWindow(800, 600, "Test1 Window");
    SetTargetFPS(120);
    char choice[64] = "";  
    bool editMode = true;
    char resultMessage[64] = "";  
    srand(time(NULL)); 
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        GuiSetStyle(LABEL, TEXT_SIZE, 200);  
        GuiLabel((Rectangle){50, 50, 700, 200}, "Type 1. Heads, 2. Tails:");
        GuiTextBox((Rectangle){50, 300, 300, 40}, choice, 64, editMode);
        DrawText(resultMessage, 50, 400, 20, DARKBLUE);
        if (IsKeyPressed(KEY_ENTER)) {
            int random = rand() % 2;  
            char resultChar = (random == 0) ? '1' : '2';
            if (choice[0] == resultChar) {
                snprintf(resultMessage, sizeof(resultMessage), "You Win");
            } else {
                snprintf(resultMessage, sizeof(resultMessage), "You Lose L");
            }
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
