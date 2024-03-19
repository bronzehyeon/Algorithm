#include <iostream>
#include <string>
using namespace std;

int N;
int arr[64][64];

void solve(int row, int col, int len) {

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
        cout << color;
    }
    else {
        cout << "(";
        solve(row, col, len / 2);
        solve(row, col + len / 2, len / 2);
        solve(row + len / 2, col, len / 2);
        solve(row + len / 2, col + len / 2, len / 2);
        cout << ")";
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    string str;

    for (int i = 0; i < N; i++) {
        cin >> str;
        for (int j = 0; j < N; j++) {
            arr[i][j] = str[j] - '0';
        }
    }


    solve(0, 0, N);

}