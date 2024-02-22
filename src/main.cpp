#include <cstddef>
#include <raylib.h>
#include <iostream>

#include "playfield.hpp"
#include "piece.hpp"

int main(int argc, char *argv[]) {

    const int screenWidth = 400;
    const int screenHeight = 800;

    playfield pf;
    piece currentPiece(&pf.GetField());
    pf.currentPiece = &currentPiece;
    pallete p;

    size_t frameCounter = 0;
    SetTargetFPS(60);

    InitWindow(screenWidth, screenHeight, "Tetris");
    while (!WindowShouldClose()) {
        // Updating things
        int key = GetKeyPressed();
        switch (key) {
            case KEY_LEFT:
                pf.currentPiece->Left();
                break;
            case KEY_RIGHT:
                pf.currentPiece->Right();
                break;
            case KEY_DOWN:
                pf.currentPiece->step();
                break;
            case KEY_R:
                pf.ResetPlayfield();
                break;
            case KEY_X: 
                pf.currentPiece->rotateRight();
                break;
            case KEY_Z: 
                pf.currentPiece->rotateLeft();
                break;
            default:
               break;
        }
        if (++frameCounter >= 15) {
            if (pf.currentPiece->step()) {
                pf.LookForCompleteLines();
                pf.currentPiece->NewPiece();
            } 


            frameCounter = 0;
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
