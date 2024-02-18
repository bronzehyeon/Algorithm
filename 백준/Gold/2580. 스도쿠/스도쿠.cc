#include <iostream>
using namespace std;

int sudoku[9][9];
bool isEnd = false;

bool isPromising(int n, int row, int col, int sector) {
    for (int i = 0; i < 9; i++) {
        if (sudoku[row][i] == n)
            return false;
    }
    for (int i = 0; i < 9; i++) {
        if (sudoku[i][col] == n)
            return false;
    }
    int baseRow = sector / 3 * 3;
    int baseCol = sector % 3 * 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (sudoku[baseRow + i][baseCol + j] == n)
                return false;
        }
    }
    return true;
}

void solve(int row, int col) {
    if (row > 8) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << sudoku[i][j] << " ";
            }
            cout << '\n';
        }
        isEnd = true;
        return;
    }
    if (isEnd) {
        return;
    }
    if (sudoku[row][col] != 0) {
        if (col == 8) 
            solve(row + 1, 0);
        else
            solve(row, col + 1);
    }
    else {
        for (int i = 1; i <= 9; i++) {
            if (isPromising(i, row, col, (row / 3) * 3 + col / 3)) {
                sudoku[row][col] = i;
                if (col == 8)
                    solve(row + 1, 0);
                else
                    solve(row, col + 1);
                sudoku[row][col] = 0;
            }
        }
    }
}

int main() {

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> sudoku[i][j];
        }
    }
    solve(0, 0); 
}