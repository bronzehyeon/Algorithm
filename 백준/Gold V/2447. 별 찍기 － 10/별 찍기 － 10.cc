#include <iostream>
using namespace std;

void star(int row, int col, int N){
    if (row / N % 3 == 1 && col / N % 3 == 1)
        cout << ' ';
    else {
        if (N == 1) {
            cout << '*';
        }
        else
            star(row, col, N / 3);
    }
}

int main() {
    int N;
    cin >> N;

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            star(row, col, N);
        }
        cout << '\n';
    }
    
}