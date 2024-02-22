#ifndef PLAYFIELD
#define PLAYFIELD
#include <cstddef>
#include <raylib.h>
#include <vector> 

#include "square.hpp" 
#include "pallete.hpp"
#include "piece.hpp"

using std::vector;

class playfield {
private:
    pallete colors;
    vector<vector<square>> field;
public:

    piece* currentPiece = nullptr;
    const size_t width = 10;
    const size_t height = 25;
    playfield();
    void ResetPlayfield();
    vector<vector<square>>& GetField();
    vector<square>& operator[] (size_t i);
    void LookForCompleteLines();
    void LowerField(int row);
};

#endif // !PLAYFIELD
