#ifndef SQUARE
#define SQUARE

#include <cstddef>
#include <raylib.h>

class square {
private:
    size_t squareSize = 40;
    Rectangle rec = {3, 3, static_cast<float>(squareSize), static_cast<float>(squareSize)};
    Color color;
    bool isPartBackground = true;
public:
    square(square& s);
    square(const square& s);
    square();
    square(size_t x, size_t y, Color col);
    Rectangle GetRec();
    void SetColor(Color c);
    Color GetColor();
    bool IsBackground(); 
    void SetBackgroundState(bool state);
};

#endif // !SQUARE
