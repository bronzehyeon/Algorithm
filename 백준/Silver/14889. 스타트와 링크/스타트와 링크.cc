#include <iostream>
using namespace std;

int N;
int synergy[21][21];
int minDiffer = 10000000;
int teamA[21];


void solve(int idx, int cnt) {

    
    if (cnt == N / 2) {
        int differ = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i; j < N; j++) {
                if (teamA[i] != 0 && teamA[j] != 0) {
                    differ += synergy[i][j] + synergy[j][i];
                }
                else if (teamA[i] == 0 && teamA[j] == 0) {
                    differ -= synergy[i][j] + synergy[j][i];
                }
            }
        }
        if (abs(differ) < minDiffer)
            minDiffer = abs(differ);
        return;
    }

    for (int i = idx; i < N; i++) {
        teamA[i] = 1;
        solve(i + 1, cnt + 1);
        teamA[i] = 0;
    }

}

int main() {
    cin >> N;


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> synergy[i][j];
        }
    }

    solve(0, 0);

    cout << minDiffer;

}