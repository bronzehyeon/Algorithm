#include <iostream>
using namespace std;

int arr[2187][2187];
int minusOne = 0;
int zero = 0;
int one = 0;

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
        if (arr[row][col] == -1)
            minusOne++;
        else if (arr[row][col] == 0)
            zero++;
        else
            one++;
    }
    else {
        check(row, col, len / 3);
        check(row + len / 3, col, len / 3);
        check(row + len * 2 / 3, col, len / 3);
        check(row, col + len / 3, len / 3);
        check(row + len / 3, col + len / 3, len / 3);
        check(row + len * 2 / 3, col + len / 3, len / 3);
        check(row, col + len * 2 / 3, len / 3);
        check(row + len / 3, col + len * 2 / 3, len / 3);
        check(row + len * 2 / 3, col + len * 2 / 3, len / 3);
        
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

    cout << minusOne << '\n';
    cout << zero << '\n';
    cout << one << '\n';

}