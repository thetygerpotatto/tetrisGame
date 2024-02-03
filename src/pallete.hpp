#ifndef PALLETE
#define PALLETE

#include <raylib.h>

struct pallete {
    Color Cyan = {0, 255, 255, 255};
    Color Yellow = {255, 255, 0, 255};
    Color Purple = {0, 255, 0, 255};
    Color Red = {255, 0 ,0, 255};
    Color Blue = {0, 0, 255, 255};
    Color Orange = {255, 0x7f, 0, 255};
    Color Grey = {0x7f, 0x7f, 0x7f, 0xff};
    Color Default = Cyan;
};
#endif // !PALLETE
