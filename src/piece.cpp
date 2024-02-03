#include "piece.hpp"


piece::piece(vector<vector<square>>* f) {
    this->field = f;
    NewPiece();
}

void piece::NewPiece() {
    pieceColor = GetRamdomColor();
    pt = static_cast<PieceTypes>(rand() % 7);

    switch (pt) {
        case PieceTypes::I: { 
            squares.clear();//         c          
            squares = {{3,5}, {4,5}, {5,5}, {6,5}};
            PaintSquares(pieceColor);
            ChangePieceBackgroundState(false);
            rotator.SetPiece(pt);
        } break;
        case PieceTypes::O: {
            squares.clear();
            squares = {{4,5}, {5,5}, 
                       {4,6}, {5,6}};
            PaintSquares(pieceColor);
            ChangePieceBackgroundState(false);
        } break;
        case PieceTypes::T: {
            squares.clear();//   c
            squares = {{4,5}, {5,5}, {6,5}, 
                              {5,6}};
            PaintSquares(pieceColor);
            ChangePieceBackgroundState(false);
        } break;
        case PieceTypes::L: {
            squares.clear();//  c
            squares = {{4,5}, {5,5}, {6,5}, 
                       {4,6}};
            PaintSquares(pieceColor);
            ChangePieceBackgroundState(false);
        } break;
        case PieceTypes::J: {
            squares.clear();//  c
            squares = {{4,5}, {5,5}, {6,5},
                                     {6,6}};
            PaintSquares(pieceColor);
            ChangePieceBackgroundState(false);
        } break;
        case PieceTypes::S: {
            squares.clear();//  
            squares = {{5,5}, {6,5}, {4,6}, {5,6}};
            PaintSquares(pieceColor);
            ChangePieceBackgroundState(false);
        } break;
        case PieceTypes::Z: {
            squares.clear();
            squares = {{4,5}, {5,5}, {5,6}, {6,6}};
            PaintSquares(pieceColor);
            ChangePieceBackgroundState(false);
        } break;
        default:
            
        break;
    }
    rotator.SetPiece(pt);
}

void piece::step() {
    if(CanGoDown()) {
        PaintSquares(pieceColor);
        down();
    } else {
        NewPiece();
    }
}

void piece::rotateLeft() {
    PaintSquares(colors.Default);
    ChangePieceBackgroundState(true);
    rotator.RotateLeft(squares);
    PaintSquares(pieceColor);
    ChangePieceBackgroundState(false);
}

void piece::rotateRight() {
    PaintSquares(colors.Default);
    ChangePieceBackgroundState(true);
    rotator.RotateRight(squares);
    PaintSquares(pieceColor);
    ChangePieceBackgroundState(false);
}

void piece::Left() {
    if (CanGoLeft()) {
        PaintSquares(colors.Default);
        ChangePieceBackgroundState(true);
        for (size_t i = 0; i < squares.size(); ++i) {
            --squares[i].x;
        }
        PaintSquares(pieceColor);
        ChangePieceBackgroundState(false);
    }
}

void piece::Right() {
    if (CanGoRight()) {
        PaintSquares(colors.Default);
        ChangePieceBackgroundState(true);
        for (size_t i = 0; i < squares.size(); ++i) {
            ++squares[i].x;
        }
        PaintSquares(pieceColor);
        ChangePieceBackgroundState(false);
    }
}

void piece::down() {
    PaintSquares(colors.Default);
    ChangePieceBackgroundState(true);
    for (size_t i = 0; i < squares.size(); ++i) {
        ++squares[i].y;
    }
    PaintSquares(pieceColor);
    ChangePieceBackgroundState(false);
}

Color piece::GetRamdomColor() {
    int ColorIndex = rand() % 6;
    switch (ColorIndex) {
        case 0: {
            return colors.Yellow;    
        } break;
        case 1: {
            return colors.Purple;
        } break;
        case 2: {
            return colors.Red;
        } break;
        case 3: {
            return colors.Blue;
        } break;
        case 4: {
            return colors.Orange;
        } break;
        case 5: {
            return colors.Grey;
        } break;
    }
    return colors.Default;
}

void piece::PaintSquares(Color squareColor) {
    for (size_t i = 0; i < squares.size(); ++i) {
        (*field)[squares[i].x][squares[i].y].SetColor(squareColor);
    }
}

void piece::ChangePieceBackgroundState(bool state) {
    for (size_t i = 0; i < squares.size(); ++i) {
        (*field)[squares[i].x][squares[i].y].SetBackgroundState(state);
    } 
}

bool piece::CanGoDown() {
    for (auto sq : squares) {
        Vector2 beneathPiece {sq.x, sq.y+1};
        if (sq.y+1 > 24) return false;
        if (IsItSelf(beneathPiece)) continue;
        if (!(*field)[sq.x][sq.y+1].IsBackground()) return false;
    }
    return true;
}

bool piece::CanGoLeft() {
    for (auto sq : squares) {
        if (sq.x-1 < 0) return false;
        square& leftSquare = (*field)[sq.x-1][sq.y];
        Vector2 cords {sq.x-1, sq.y};
        if (IsItSelf(cords)) continue;
        if (!leftSquare.IsBackground()) return false;
    }
    return true;
}

bool piece::CanGoRight() {
    for (auto sq : squares) {
        if (sq.x+1 >= 10) return false;
        square& rightSquare = (*field)[sq.x+1][sq.y];
        Vector2 cords {sq.x+1, sq.y};
        if (IsItSelf(cords)) continue;
        if (!rightSquare.IsBackground()) return false;
    }
    return true;
}

bool piece::IsItSelf(Vector2 cords) {
    for (auto sq: squares) {
        if (sq.x == cords.x && sq.y == cords.y) return true;
    }
    return false;
}
