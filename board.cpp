#include "board.h"

#include <iomanip>
#include <iostream>
#include <string>

board::board(int size, int to_win, char player_symbol) : size(size), to_win(to_win), player_symbol(player_symbol), entries(size, std::vector<char>(size)) {
    if (size < 3) {
        size = 3;
        entries.resize(size);
    }

    if (to_win < 2)
        to_win = 2;
    if (to_win > size)
        to_win = size;

    for (int x = 0; x < size; x++)
        for (int y = 0; y < size; y++)
            entries[x][y] = 0;

    if (player_symbol == 'x')
        ai_symbol = 'o';
    else if (player_symbol == 'o')
        ai_symbol = 'x';
    else {
        player_symbol = 'x';
        ai_symbol = 'o';
    }

    turn = 1;
}

void board::print() const {
    system("cls");

    std::cout << std::string(5, ' ');
    for (int x = 0; x < size; x++) {
        if (x < 9)
            std::cout << std::setw(1) << x + 1 << "   ";
        else
            std::cout << std::setw(2) << x + 1 << "  ";
    }
    std::cout << '\n';

    std::cout << std::string(3, ' ') << '.' << std::string(4 * size - 1, '-') << ".\n";

    for (int y = 0; y < size; y++) {
        std::cout << std::setw(2) << y + 1 << " | ";
        for (int x = 0; x < size; x++) {
            if (entries[x][y] == 0)
                std::cout << ' ';
            else
                std::cout << entries[x][y];
            if (x < size - 1)
                std::cout << " | ";
        }
        std::cout << " | " << y + 1;

        if (y < size - 1) {
            std::cout << "\n   |";
            for (int i = 0; i < size - 1; i++)
                std::cout << std::string(3, '-') << '+';
            std::cout << std::string(3, '-') << "|";
        }
        std::cout << '\n';
    }

    std::cout << std::string(3, ' ') << '\'' << std::string(4 * size - 1, '-') << "\'\n";

    std::cout << std::string(5, ' ');
    for (int x = 0; x < size; x++) {
        if (x < 9)
            std::cout << std::setw(1) << x + 1 << "   ";
        else
            std::cout << std::setw(2) << x + 1 << "  ";
    }
    std::cout << "\n\n";
}

void board::set(int x, int y) {
    if (x >= 1 && x <= size && y >= 1 && y <= size) {
        if (isPlayerTurn())
            entries[x - 1][y - 1] = player_symbol;
        else
            entries[x - 1][y - 1] = ai_symbol;
    }
}

void board::reset() {
    for (int x = 0; x < size; x++)
        for (int y = 0; y < size; y++)
            entries[x][y] = 0;
    turn = 1;
}

void board::remove(int x, int y) {
    entries[x - 1][y - 1] = 0;
}

char board::check(int x, int y) const {
    if (x >= 1 && x <= size && y >= 1 && y <= size)
        return entries[x - 1][y - 1];
    else
        return 0;
}

bool board::isOccupied(int x, int y) const {
    return check(x, y);
}

bool board::isFull() const {
    for (int x = 1; x < size+1; x++) {
        for (int y = 1; y < size+1; y++)
            if (!isOccupied(x, y))
                return false;
    }
    return true;
}

bool board::isPlayerTurn() const {
    return turn;
}

int board::gameState() const {

    int player_counter, ai_counter;

    for (int x = 0; x < size; x++) {
        player_counter = ai_counter = 1;
        for (int y = 0; y < size - 1; y++) {
            if (entries[x][y] == entries[x][y + 1]) {
                if (entries[x][y] == player_symbol)
                    player_counter++;
                else if (entries[x][y] == ai_symbol)
                    ai_counter++;
                if (player_counter == to_win)
                    return 1;
                if (ai_counter == to_win)
                    return -1;
            }
        }
    }

    for (int y = 0; y < size; y++) {
        player_counter = ai_counter = 1;
        for (int x = 0; x < size - 1; x++) {
            if (entries[x][y] == entries[x + 1][y]) {
                if (entries[x][y] == player_symbol)
                    player_counter++;
                else if (entries[x][y] == ai_symbol)
                    ai_counter++;
                if (player_counter == to_win)
                    return 1;
                if (ai_counter == to_win)
                    return -1;
            }
        }
    }

    for (int x = 1; x < size - to_win + 1; x++) {
        player_counter = ai_counter = 1;
        for (int y = 0; y < (size - x - 1); y++) {
            if (entries[y][x + y] == entries[y + 1][x + y + 1]) {
                if (entries[y][x + y] == player_symbol)
                    player_counter++;
                else if (entries[y][x + y] == ai_symbol)
                    ai_counter++;
                if (player_counter == to_win)
                    return 1;
                if (ai_counter == to_win)
                    return -1;
            }
        }
    }
    for (int x = 0; x < size - to_win + 1; x++) {
        player_counter = ai_counter = 1;
        for (int y = 0; y < (size - x - 1); y++) {
            if (entries[x + y][y] == entries[x + y + 1][y + 1]) {
                if (entries[x + y][y] == player_symbol)
                    player_counter++;
                else if (entries[x + y][y] == ai_symbol)
                    ai_counter++;
                if (player_counter == to_win)
                    return 1;
                if (ai_counter == to_win)
                    return -1;
            }
        }
    }
    for (int x = 0; x < size - to_win + 1; x++) {
        player_counter = ai_counter = 1;
        for (int y = 0; y < (size - x - 1); y++) {
            if (entries[size - 1 - y][x + y] == entries[size - 1 - (y + 1)][x + y + 1]) {
                if (entries[size - 1 - y][x + y] == player_symbol)
                    player_counter++;
                else if (entries[size - 1 - y][x + y] == ai_symbol)
                    ai_counter++;
                if (player_counter == to_win)
                    return 1;
                if (ai_counter == to_win)
                    return -1;
            }
        }
    }
    for (int x = 1; x < size - to_win + 1; x++) {
        player_counter = ai_counter = 1;
        for (int y = 0; y < (size - x - 1); y++) {
            if (entries[size - 1 - x - y][y] == entries[size - x - y - 2][y + 1]) {
                if (entries[size - 1 - x - y][y] == player_symbol)
                    player_counter++;
                else if (entries[size - 1 - x - y][y] == ai_symbol)
                    ai_counter++;
                if (player_counter == to_win)
                    return 1;
                if (ai_counter == to_win)
                    return -1;
            }
        }
    }

    return 0;
}