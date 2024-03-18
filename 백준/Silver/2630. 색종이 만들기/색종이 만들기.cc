#include <iostream>
using namespace std;

int arr[128][128];
int white = 0;
int blue = 0;

void check(int row, int col, int len) {

    if (len == 0)
        return;

    int color = arr[row][col];

    bool isOk = true;    

    for (int i = row; i < row + len; i++) {
        for (int j = col; j < col + len; j++) {
            if (arr[i][j] != color) {
                isOk = false;
                break;
            }
        }
        if (!isOk) break;
    }

    if (isOk) {
        if (arr[row][col] == 0)
            white++;
        else
            blue++;
    }
    else {
        check(row, col, len / 2);
        check(row + len / 2, col, len / 2);
        check(row, col + len / 2, len / 2);
        check(row + len / 2, col + len / 2, len / 2);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;



    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    check(0, 0, N);

    cout << white << '\n';
    cout << blue << '\n';

}