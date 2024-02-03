#include <cstddef>
#include <raylib.h>

#include "playfield.hpp"
#include "piece.hpp"

int main(int argc, char *argv[]) {

    const int screenWidth = 400;
    const int screenHeight = 800;

    playfield pf;
    piece CurrentPiece(&pf.GetField());
    pallete p;

    size_t frameCounter = 0;
    SetTargetFPS(60);

    InitWindow(screenWidth, screenHeight, "Tetris");
    while (!WindowShouldClose()) {
        // Updating things
        int key = GetKeyPressed();
        switch (key) {
            case KEY_LEFT:
                CurrentPiece.Left();
                break;
            case KEY_RIGHT:
                CurrentPiece.Right();
                break;
            case KEY_DOWN:
                CurrentPiece.step();
                break;
            case KEY_R:
                pf.ResetPlayfield(CurrentPiece);
                break;
            case KEY_X: 
                CurrentPiece.rotateRight();
                break;
            case KEY_Z: 
                CurrentPiece.rotateLeft();
                break;
            default:
               break;
        }
        if (++frameCounter >= 15) {
            CurrentPiece.step();
            frameCounter = 0;
            pf.LookForCompleteLines();
        }
        
        // Drawing ---------------------------
        BeginDrawing();
        ClearBackground(WHITE);
        // DrawPlayfield ---------------------------
        for (size_t x = 0; x < pf.width; x++) {
            for (size_t y = 0; y < pf.height; y++) {
                DrawRectangleRec(pf[x][y].GetRec(), pf[x][y].GetColor());
            }
        } 
        EndDrawing();
        // End Drawing ---------------------------
    }

    return 0;
}
