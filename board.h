#pragma once
#include <vector>

class board {
public:
    board()= default;
    board(int size, int to_win, char player);
    [[nodiscard]] int getSize() const { return size; }
    void changeTurn(bool player) { player ? turn = true : turn = false; }
    void print() const;
    void set(int x, int y);
    void remove(int x, int y);
    void reset();
    [[nodiscard]] char check(int x, int y) const;
    [[nodiscard]] bool isOccupied(int x, int y) const;
    [[nodiscard]] bool isFull() const;
    [[nodiscard]] bool isPlayerTurn() const;
    [[nodiscard]] int gameState() const;

private:
    int size{};
    int to_win{};
    bool turn{};
    char player_symbol{}, ai_symbol{};
    std::vector<std::vector<char>> entries;
};