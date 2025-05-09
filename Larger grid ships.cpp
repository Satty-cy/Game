#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int GRID_SIZE = 8; // Larger grid size
const int SHIP_COUNT = 10; // More ships

void initializeGrid(char grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; ++i)
        for (int j = 0; j < GRID_SIZE; ++j)
            grid[i][j] = '.';
}

void placeShips(char grid[GRID_SIZE][GRID_SIZE]) {
    srand(time(0));
    int shipsPlaced = 0;

    while (shipsPlaced < SHIP_COUNT) {
        int row = rand() % GRID_SIZE;
        int col = rand() % GRID_SIZE;

        if (grid[row][col] == '.') {
            grid[row][col] = 'S';
            shipsPlaced++;
        }
    }
}

void displayGrid(char grid[GRID_SIZE][GRID_SIZE], bool revealShips = false) {
    cout << "  ";
    for (int i = 0; i < GRID_SIZE; ++i) cout << i << " ";
    cout << "\n";

    for (int i = 0; i < GRID_SIZE; ++i) {
        cout << i << " ";
        for (int j = 0; j < GRID_SIZE; ++j) {
            if (revealShips || grid[i][j] == 'X' || grid[i][j] == 'O') {
                cout << grid[i][j] << " ";
            } else {
                cout << ". ";
            }
        }
        cout << "\n";
    }
}

void playGame() {
    char grid[GRID_SIZE][GRID_SIZE];
    initializeGrid(grid);
    placeShips(grid);

    int attempts = 15; // Increased attempts
    int shipsDestroyed = 0;

    cout << "Battleship: Larger Grid Edition!\n";

    while (attempts > 0 && shipsDestroyed < SHIP_COUNT) {
        displayGrid(grid);
        int row, col;

        cout << "Enter your attack coordinates (row and column): ";
        cin >> row >> col;

        if (row < 0 || row >= GRID_SIZE || col < 0 || col >= GRID_SIZE) {
            cout << "Invalid coordinates! Try again.\n";
            continue;
        }

        if (grid[row][col] == 'S') {
            cout << "Hit!\n";
            grid[row][col] = 'X';
            shipsDestroyed++;
        } else if (grid[row][col] == '.') {
            cout << "Miss!\n";
            grid[row][col] = 'O';
        } else {
            cout << "Already targeted!\n";
        }
        attempts--;
    }

    if (shipsDestroyed == SHIP_COUNT)
        cout << "Congratulations! You destroyed all ships!\n";
    else
        cout << "Game over! You ran out of attempts.\n";

    cout << "Final grid:\n";
    displayGrid(grid, true);
}

int main() {
    playGame();
    return 0;
}
