#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


int N;
int arr[16][16];
int dp[16][1 << 16];

int dfs(int x, int cnt) {
    if (cnt == (1 << N) - 1) {
        if (arr[x][0] == 0) {
            return 20000000;
        }
        return arr[x][0];
    }

    if (dp[x][cnt] != -1) {
        return dp[x][cnt];
    }

    dp[x][cnt] = 20000000;

    for (int i = 0; i < N; i++) {
        if (arr[x][i] == 0) {
            continue;
        }
        if ((cnt & (1 << i)) == (1 << i)) {
            continue;
        }

        int tmp = dfs(i, cnt | 1 << i);
        dp[x][cnt] = min(dp[x][cnt], tmp + arr[x][i]);
    }

    return dp[x][cnt];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));

    cout << dfs(0, 1) << '\n';

}