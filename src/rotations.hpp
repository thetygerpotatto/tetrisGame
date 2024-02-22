#ifndef ROTATIONS
#define ROTATIONS

#include <array>
#include <raylib.h>
#include <vector>
#include <map>
#include "piece_types.hpp"
#include "square.hpp"

using std::vector;
using std::map;
using std::array;

class rotation {
private:
    vector<vector<square>> *playField = nullptr; 
    enum direction {left = -1, right = 1};
    PieceTypes pieceType;
    vector<array<Vector2, 4>> rotationSteps;
    int rotationIndex  = 0;
    int rotationsQuantity = 0;

public:
    rotation();
    rotation(vector<vector<square>> *pF);
    void SetPiece(PieceTypes p);
    void RotateRight(vector<Vector2>& squares);
    void RotateLeft(vector<Vector2>& squares);
    void Rotate(vector<Vector2>& squares, int di);

private:
    void SetUpRotationSteps();
    void configRotationIndexDirection(int dir);
    bool canRotate(const vector<Vector2> &squares);
};


#endif // ROTATION
