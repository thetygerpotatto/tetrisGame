#ifndef ROTATIONS
#define ROTATIONS

#include <array>
#include <cstddef>
#include <raylib.h>
#include <vector>
#include <map>
#include "piece_types.hpp"
#include <iostream>

using std::vector;
using std::map;
using std::array;

class rotation {
private:
    enum direction {left = -1, right = 1};
    PieceTypes pieceType;
    vector<array<Vector2, 4>> rotationSteps;
    int rotationIndex  = 0;
    int rotationsQuantity = 0;

public:
    rotation();
    void SetPiece(PieceTypes p);
    void RotateRight(vector<Vector2>& squares);
    void RotateLeft(vector<Vector2>& squares);
    void Rotate(vector<Vector2>& squares, int di);

private:
    void SetUpRotationSteps();
    void configRotationIndexDirection(int dir);
};


#endif // ROTATION
