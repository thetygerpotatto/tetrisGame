#ifndef PIECE
#define PIECE 
#include <cstdlib>
#include <raylib.h>
#include <vector>


#include "pallete.hpp"
#include "square.hpp"
#include "piece_types.hpp"
#include "rotations.hpp"
using std::vector;

class piece {
private:
    pallete colors;
    Color pieceColor;
    vector<Vector2> squares;
    vector<vector<square>> *field;
    PieceTypes pt;
    rotation rotator;

public:
    piece(vector<vector<square>>* f);

    void NewPiece(); 
    bool step();
    void rotateLeft();
    void rotateRight();
    void Left();
    void Right();
    void down(); 

private:
    Color GetRamdomColor();
    void PaintSquares(Color squareColor);
    void ChangePieceBackgroundState(bool state);
    bool CanGoDown();
    bool CanGoLeft();
    bool CanGoRight();
    bool IsItSelf(Vector2 cords);
};

#endif // PIECE
