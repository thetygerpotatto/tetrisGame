#include "rotations.hpp"
#include "piece_types.hpp"
#include <iostream>
#include <raylib.h>
#include <raymath.h>

rotation::rotation() {}

rotation::rotation(vector<vector<square>> *pF) {
    playField = pF;
}

void rotation::SetPiece(PieceTypes p) {
    pieceType = p;
    rotationIndex = 0;
    rotationsQuantity = 0;
    SetUpRotationSteps();
}

void rotation::RotateRight(vector<Vector2>& squares) {
    Rotate(squares, direction::right);
}

void rotation::RotateLeft(vector<Vector2>& squares) {
    Rotate(squares, direction::left);
}

void rotation::Rotate(vector<Vector2>& squares, int di) {
    bool canBeRotated = true;

    if (pieceType == PieceTypes::O) canBeRotated = false;
    
    vector<Vector2> newSquareCoords;
    
    configRotationIndexDirection(di);

    for(size_t i = 0; i < squares.size() && canBeRotated; i++) {
        int x_ofset = squares[i].x + rotationSteps[rotationIndex][i].x * di;
        int y_ofset = squares[i].y + rotationSteps[rotationIndex][i].y * di;
        
        if (x_ofset > 9 || x_ofset < 0 ||
            y_ofset > 24 || y_ofset < 0) {
            canBeRotated = false;
        } else {
            Vector2 coord  = {static_cast<const float>(x_ofset), static_cast<const float>(y_ofset)};
            newSquareCoords.push_back(coord);
        }
    }
    
    if (canBeRotated) canBeRotated = canRotate(newSquareCoords);

    if (canBeRotated) {
        for (size_t i = 0; i < squares.size(); ++i) {
           squares[i].x = newSquareCoords[i].x; 
           squares[i].y = newSquareCoords[i].y; 
        }
        if (di > 0) {
            ++rotationIndex;    
            rotationIndex = rotationIndex % rotationsQuantity;
        }
    }
}

void rotation::SetUpRotationSteps() {
    rotationSteps.clear();
    switch (pieceType) {
        case PieceTypes::I: {
            array<Vector2, 4> ofsets;
            ofsets[0] = {2, -2}; ofsets[1] = {1, -1}; ofsets[2] = {0, 0}; ofsets[3] = {-1, 1};
            rotationSteps.push_back(ofsets);
            ofsets[0] = {-2, 2}; ofsets[1] = {-1, 1}; ofsets[2] = {0, 0}; ofsets[3] = {1, -1};
            rotationSteps.push_back(ofsets);
            rotationsQuantity  = 2;
        } break;
        case PieceTypes::J: {
            array<Vector2, 4> ofsets;
            ofsets[0] = {1, -1}; ofsets[1] = {0, 0}; ofsets[2] = {-1, 1}; ofsets[3] = {-2, 0};
            rotationSteps.push_back(ofsets);
            ofsets[0] = {1, 1}; ofsets[1] = {0, 0}; ofsets[2] = {-1, -1}; ofsets[3] = {0, -2};
            rotationSteps.push_back(ofsets);
            ofsets[0] = {-1, 1}; ofsets[1] = {0, 0}; ofsets[2] = {1, -1}; ofsets[3] = {2, 0};
            rotationSteps.push_back(ofsets);
            ofsets[0] = {-1, -1}; ofsets[1] = {0, 0}; ofsets[2] = {1, 1}; ofsets[3] = {0, 2};
            rotationSteps.push_back(ofsets);
            rotationsQuantity  = ofsets.size();
        } break;
        case PieceTypes::L: {
            array<Vector2, 4> ofsets;
            ofsets[0] = {1, -1}; ofsets[1] = {0, 0}; ofsets[2] = {-1, 1}; ofsets[3] = {0, -2};
            rotationSteps.push_back(ofsets);
            ofsets[0] = {1, 1}; ofsets[1] = {0, 0}; ofsets[2] = {-1, -1}; ofsets[3] = {2, 0};
            rotationSteps.push_back(ofsets);
            ofsets[0] = {-1, 1}; ofsets[1] = {0, 0}; ofsets[2] = {1, -1}; ofsets[3] = {0, 2};
            rotationSteps.push_back(ofsets);
            ofsets[0] = {-1, -1}; ofsets[1] = {0, 0}; ofsets[2] = {1, 1}; ofsets[3] = {-2, 0};
            rotationSteps.push_back(ofsets);
            rotationsQuantity  = ofsets.size();

        } break;
        case PieceTypes::S: {
            array<Vector2, 4> ofsets;
            ofsets[0] = {0, 0}; ofsets[1] = {-1, 1}; ofsets[2] = {0, -2}; ofsets[3] = {-1, -1};
            rotationSteps.push_back(ofsets);
            ofsets[0] = {0, 0}; ofsets[1] = {-1, -1}; ofsets[2] = {2, 0}; ofsets[3] = {1, -1};
            rotationSteps.push_back(ofsets);
            ofsets[0] = {0, 0}; ofsets[1] = {1, -1}; ofsets[2] = {0, 2}; ofsets[3] = {1, 1};
            rotationSteps.push_back(ofsets);
            ofsets[0] = {0, 0}; ofsets[1] = {1, 1}; ofsets[2] = {-2, 0}; ofsets[3] = {-1, 1};
            rotationSteps.push_back(ofsets);
            rotationsQuantity  = ofsets.size();
        } break;
        case PieceTypes::T: {
            array<Vector2, 4> ofsets;
            ofsets[0] = {1, -1}; ofsets[1] = {0, 0}; ofsets[2] = {-1, 1}; ofsets[3] = {-1, -1};
            rotationSteps.push_back(ofsets);
            ofsets[0] = {1, 1}; ofsets[1] = {0, 0}; ofsets[2] = {-1, -1}; ofsets[3] = {1, -1};
            rotationSteps.push_back(ofsets);
            ofsets[0] = {-1, 1}; ofsets[1] = {0, 0}; ofsets[2] = {1, -1}; ofsets[3] = {1, 1};
            rotationSteps.push_back(ofsets);
            ofsets[0] = {-1, -1}; ofsets[1] = {0, 0}; ofsets[2] = {1, 1}; ofsets[3] = {-1, 1};
            rotationSteps.push_back(ofsets);
            rotationsQuantity  = ofsets.size();
        } break;
        case PieceTypes::Z: {
            array<Vector2, 4> ofsets;
            ofsets[0] = {1, -1}; ofsets[1] = {0, 0}; ofsets[2] = {-1, -1}; ofsets[3] = {-2, 0};
            rotationSteps.push_back(ofsets);
            ofsets[0] = {1, 1}; ofsets[1] = {0, 0}; ofsets[2] = {1, -1}; ofsets[3] = {0, -2};
            rotationSteps.push_back(ofsets);
            ofsets[0] = {-1, 1}; ofsets[1] = {0, 0}; ofsets[2] = {1, 1}; ofsets[3] = {2, 0};
            rotationSteps.push_back(ofsets);
            ofsets[0] = {-1, -1}; ofsets[1] = {0, 0}; ofsets[2] = {-1, 1}; ofsets[3] = {0, 2};
            rotationSteps.push_back(ofsets);
            rotationsQuantity  = ofsets.size();
        } break;
        case PieceTypes::O: {
        } 
        default: break;
    }
}

void rotation::configRotationIndexDirection(int dir) {
    if (dir < 0) {
        --rotationIndex;
        if (rotationIndex < 0) rotationIndex = rotationsQuantity + rotationIndex;
    } 
}

bool rotation::canRotate(const vector<Vector2> &squares) {

    for (Vector2 squareCord : squares) {
        if (squareCord.x < 0 || squareCord.x > 9) {
            return false;        
        }
        if (squareCord.y < 0 || squareCord.y > 24) {
            return false;
        }
        if (!(*playField)[squareCord.x][squareCord.y].IsBackground()) return false;
    }
    return true;
}
