#include <iostream>
#include <string>

#include "ai.h"
#include "board.h"

int main() {

    int size, to_win, depth_limit;
    char player_symbol = 0, ai_symbol = 0;
    char answer = 'n';

    while (answer == 'n') {
        std::cout << '.' << std::string(20, '-') << ".\n"
                  << "| ustawienia planszy |\n\'" << std::string(20, '-') << "\'\n";

        do {
            std::cout << "rozmiar planszy: ";
            std::cin >> size;
            std::cin.clear();
            std::cin.ignore(1024, '\n');
            if (size < 3)
                std::cout << "# minimalne wymiary  to 3x3\n";
        } while (size < 3);

        do {
            std::cout << "znaki do wygranej: ";
            std::cin >> to_win;
            std::cin.clear();
            std::cin.ignore(1024, '\n');
            if (to_win < 2 || to_win > size)
                std::cout << "# wartosc powinna znajdowac sie w przedziale [2," << size << "]\n";
        } while (to_win < 2 || to_win > size);

        std::cout << "\n." << std::string(19, '-') << ".\n"
                  << "| ustawienia graczy |\n\'" << std::string(19, '-') << "\'\n";

        do {
            std::cout << "znak gracza (x/o): ";
            std::cin >> player_symbol;
            std::cin.clear();
            std::cin.ignore(1024, '\n');
        } while (!(player_symbol == 'x' || player_symbol == 'o'));

        if (player_symbol == 'x')
            ai_symbol = 'o';
        else
            ai_symbol = 'x';

        do {
            std::cout << "glebokosc rekursji AI: ";
            std::cin >> depth_limit;
            std::cin.clear();
            std::cin.ignore(1024, '\n');
        } while (depth_limit <= 0);

        std::cout << '\n';
        do {
            std::cout << "rozpoczac gre? (t/n): ";
            std::cin >> answer;
            std::cin.clear();
            std::cin.ignore(1024, '\n');
        } while (answer != 't' && answer != 'n');
        std::cout << '\n';
    }

    board _board(size, to_win, player_symbol);
    ai _ai(depth_limit);

    do {
        _board.reset();
        _board.print();

        while (_board.gameState() == 0 && !_board.isFull()) {

            if (_board.isPlayerTurn()) {
                int x, y;
                std::cout << "twoj ruch!\n";
                do {

                    do {
                        x = 0;
                        std::cout << "x > ";
                        std::cin >> x;
                        std::cin.clear();
                        std::cin.ignore(1024, '\n');
                        if (x < 1 || x > size)
                            std::cout << "# x wybierz z przedzialu [1," << size << "]\n";
                    } while (x < 1 || x > size);


                    do {
                        y = 0;
                        std::cout << "y > ";
                        std::cin >> y;
                        std::cin.clear();
                        std::cin.ignore(1024, '\n');
                        if (y < 1 || y > size)
                            std::cout << "# y wybierz z przedzialu [1," << size << "]\n";
                    } while (y < 1 || y > size);


                    if (_board.isOccupied(x, y)) {
                        std::cout << "pole (" << x << "," << y << ") jest zajete przez ";
                        if (_board.check(x, y) == player_symbol)
                            std::cout << "gracza (" << player_symbol << ")";
                        else
                            std::cout << "komputer (" << ai_symbol << ")";

                        std::cout << '\n';
                    }
                } while (_board.isOccupied(x, y) || x < 1 || x > size || y < 1 || y > size);
                _board.set(x, y);
                _board.changeTurn(false);
            }

            else {
                std::cout << "komputer wykonuje ruch... ";
                _ai.move(_board);
                _board.set(_ai.getx(), _ai.gety());
                 _board.changeTurn(true);
            }

            _board.print();


            if (_board.isFull() && _board.gameState() == 0)
                std::cout << "remis!";
            else if (_board.gameState() != 0) {
                std::cout << "koniec gry! wygrywa ";
                if (!_board.isPlayerTurn())
                    std::cout << "gracz (" << player_symbol << ")";
                else
                    std::cout << "komputer (" << ai_symbol << ")";
            }
            std::cout << '\n';
        }

        do {
            std::cout << "powtorzyc gre? (t/n): ";
            std::cin >> answer;
            std::cin.clear();
            std::cin.ignore(1024, '\n');
        } while (answer != 't' && answer != 'n');
    } while (answer == 't');
}
