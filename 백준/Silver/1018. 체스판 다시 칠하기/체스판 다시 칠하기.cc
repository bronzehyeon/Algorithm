#include <iostream>
#include <string>

using namespace std;

int main() {
    int M, N;
    cin >> M >> N;
    char board[51][51];
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    int repaint = 64;
    for (int i = 0; i <= M - 8; i++) {
        for (int j = 0; j <= N - 8; j++) {
            int count1 = 0;
            int count2 = 0;
            for (int x = 0; x < 8; x++) {
                for (int y = 0; y < 8; y++) {
                    if ((x + y) % 2 == 0) {
                        if (board[i + x][j + y] != 'W') count1++;
                        if (board[i + x][j + y] != 'B') count2++;
                    }
                    else {
                        if (board[i + x][j + y] == 'W') count1++;
                        if (board[i + x][j + y] == 'B') count2++;
                    }
                }
            }
            if (count1 < repaint) repaint = count1;
            if (count2 < repaint) repaint = count2;
        }
    }
    cout << repaint;
}
