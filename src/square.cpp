#include "square.hpp"

square::square(square& s) {
    rec = s.rec;
    color = s.color;
}

square::square(const square& s) {
    rec = s.rec;
    color = s.color;
}

square::square() {
    rec.x = 0;
    rec.y = 0;
    color = BLACK;
}

square::square(size_t x, size_t y, Color col) {
    rec.x = x*squareSize;
    rec.y = y*squareSize-200;
    color = col;
    isPartBackground = true;
}

Rectangle square::GetRec() {
    return rec;
}

void square::SetColor(Color c) {
    color = c;
}

Color square::GetColor() {
    return color;
}

bool square::IsBackground() {
    return isPartBackground;
}

void square::SetBackgroundState(bool state) {
    isPartBackground = state;
}
