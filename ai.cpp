#include "ai.h"
#include <algorithm>
#include <limits>

int int_max = std::numeric_limits<int>::max();

int ai::minimax(board _board, int depth, int alpha, int beta, bool maximizing) {
    int game_state = _board.gameState();

    if (game_state != 0 || _board.isFull() || depth == 0)
        return game_state;


    if (maximizing) {
        int max = -int_max;
        for (int i = 1; i < _board.getSize() + 1; i++)
            for (int j = 1; j < _board.getSize() + 1; j++)
                if (!_board.isOccupied(i, j)) {
                    _board.changeTurn(1);
                    _board.set(i, j);
                    max = std::max(max, minimax(_board, depth - 1, alpha, beta, false));
                    _board.remove(i, j);
                    alpha = std::max(alpha, max);
                    if (alpha >= beta)
                        return alpha;
                }
        return max;
    }
    else {
        int min = int_max;
        for (int i = 1; i < _board.getSize() + 1; i++)
            for (int j = 1; j < _board.getSize() + 1; j++)
                if (!_board.isOccupied(i, j)) {
                    _board.changeTurn(0);
                    _board.set(i, j);
                    min = std::min(min, minimax(_board, depth - 1, alpha, beta, true));
                    _board.remove(i, j);
                    beta = std::min(beta, min);
                    if (beta <= alpha)
                        return beta;
                }
        return min;
    }
}

void ai::move(board _board) {
    int current, best = int_max;
    for (int i = 1; i < _board.getSize() + 1; i++)
        for (int j = 1; j < _board.getSize() + 1; j++)
            if (!_board.isOccupied(i, j)) {
                _board.changeTurn(0);
                _board.set(i, j);
                current = minimax(_board, depth_limit, -int_max, int_max, true);
                _board.remove(i, j);
                if (current < best) {
                    x = i;
                    y = j;
                    best = current;
                }
            }
}
