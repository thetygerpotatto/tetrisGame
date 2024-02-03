#include "playfield.hpp"


playfield::playfield() {
    for (size_t x = 0; x < width; ++x) {
        vector<square> column;
        for (size_t y = 0; y < height; ++y) {
            square sqr = square(x, y, colors.Default); 
            column.push_back(sqr);
        }
        field.push_back(column);
    }
}

void playfield::ResetPlayfield(piece& p) {
    for (size_t x = 0; x < width; ++x) {
        for (size_t y = 0;y < height; ++y) {
            field[x][y].SetColor(colors.Default);
            field[x][y].SetBackgroundState(true);
        }
    }

    p.NewPiece();
}

vector<vector<square>>& playfield::GetField() {
    return field;
}

vector<square>& playfield::operator[] (size_t i) {
    return field[i];
}

void playfield::LookForCompleteLines() {
    int pieceCount = 0;
    int lineCount = 0;
    for (size_t y = 0; y < height; ++y) {
        for (size_t x = 0; x < width; ++x) {
            if(!field[x][y].IsBackground()) ++pieceCount; 
        }
        if (pieceCount == 10) {
            ++lineCount;
            LowerField(y);
        }
        pieceCount = 0;
    }
}

void playfield::LowerField(int row){
    for (size_t x = 0; x < width; x++) {
        field[x][row].SetColor(colors.Default);
        field[x][row].SetBackgroundState(true);
    }

    for (size_t y = row; y >= 0 && y > 4; y--) {
        for (size_t x = 0; x < 10; x++) {
            field[x][y].SetColor(field[x][y-1].GetColor());
            field[x][y].SetBackgroundState(field[x][y-1].IsBackground());
        }
    }
}
