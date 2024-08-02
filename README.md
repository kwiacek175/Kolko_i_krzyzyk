# Gra w Kółko-krzyżyk z AI

## Przegląd

Ten projekt to implementacja gry w kółko-krzyżyk w trybie tekstowym z przeciwnikiem komputerowym. Umożliwia dostosowanie rozmiaru planszy, liczby symboli potrzebnych do wygranej oraz głębokości rekurencji AI. AI wykorzystuje algorytm Minimax z przycinaniem alfa-beta do podejmowania strategicznych ruchów.

## Funkcje

- **Konfigurowalny Rozmiar Planszy**: Wybierz wymiary planszy.
- **Dostosowywalne Warunki Wygranej**: Ustaw liczbę symboli potrzebnych do wygranej.
- **Gracz vs. AI**: Graj przeciwko komputerowi z różnymi poziomami trudności.
- **Głębokość AI**: Skonfiguruj głębokość przeszukiwania AI, aby wyważyć wydajność i inteligencję.

## Użytkowanie

### Konfiguracja Gry

1. Podczas pierwszego uruchomienia, wprowadź rozmiar planszy (minimalnie 3x3).
2. Ustaw liczbę kolejnych symboli potrzebnych do wygranej.
3. Wybierz swój symbol (x lub o).
4. Określ głębokość rekurencji AI dla strategii komputerowej.

### Gra

1. Jeśli to Twoja tura, zostaniesz poproszony o wprowadzenie współrzędnych (`x` i `y`) dla swojego ruchu.
2. Komputer wykona swój ruch automatycznie po Twoim.
3. Gra toczy się do momentu, gdy jeden z graczy wygra lub plansza będzie pełna (remis).

### Powtórzenie Gry

1. Po zakończeniu gry zostaniesz zapytany, czy chcesz zagrać ponownie. Wprowadź `t`, aby zagrać jeszcze raz, lub `n`, aby zakończyć grę.

## Struktura Plików

- `main.cpp`: Zawiera główną pętlę gry i logikę interakcji z użytkownikiem.
- `board.h`: Definiuje klasę `board`, odpowiedzialną za zarządzanie planszą i stanem gry.
- `board.cpp`: Implementuje metody klasy `board`, takie jak ustawianie i usuwanie ruchów, sprawdzanie zajętości pól, oraz kontrolowanie stanu gry.
- `ai.h`: Definiuje klasę `ai`, która implementuje algorytm Minimax z przycinaniem alfa-beta dla przeciwnika komputerowego.
- `ai.cpp`: Implementuje metody klasy `ai`, w tym algorytm Minimax z przycinaniem alfa-beta, aby wybrać optymalny ruch dla komputera.

## Kompilacja

Aby skompilować program, użyj kompilatora C++ (np. `g++` lub `clang++`). Wprowadź następujące polecenie w terminalu:

```sh
g++ -o kolko_i_krzyzyk main.cpp board.cpp ai.cpp
