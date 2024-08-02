#pragma once
#include "board.h"

class ai : public board {
public:
    explicit ai(int depth_limit) : depth_limit(depth_limit) {};
    [[nodiscard]] static int minimax(board _board, int depth, int alpha, int beta, bool maximizing);
    void move(board _board);
    [[nodiscard]] int getx() const { return x; }
    [[nodiscard]] int gety() const { return y; }

private:
    int x{}, y{};
    int depth_limit;
};
