#include <iostream>
using namespace std;

int chess[15];
int cnt = 0;

bool isPromising(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (chess[i] == col || abs(row - i) == abs(chess[i] - col))
            return false;
    }
    return true;
}


void nQueen(int N, int row) {

    if (N == row) {
        cnt++;
        return;
    }

    for (int i = 0; i < N; i++) {
        if (isPromising(row, i)) {
            chess[row] = i;
            nQueen(N, row + 1);
        }
    }

}

int main() {
    int N;
    cin >> N;

    nQueen(N, 0);

    cout << cnt;
}