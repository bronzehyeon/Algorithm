#include <iostream>
#include <algorithm>
using namespace std;

int dp[501][501];
int sum[501];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);
    sum[0] = 0;
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int K;
        cin >> K;
        for (int i = 1; i <= K; i++) {
            int tmp;
            cin >> tmp;
            sum[i] = sum[i - 1] + tmp;
        }

        for (int k = 1; k < K; k++) {
            int i = 1;
            int j = k + 1;
            for (int u = 0; u < K - k; u++) {
                dp[i][j] = 1e9;
                for (int m = j - k; m <= j - 1; m++) {
                    dp[i][j] = min(dp[i][j], dp[i][m] + dp[m + 1][j] + sum[j] - sum[i - 1]);
                }
                i++;
                j++;
            }
        }

        cout << dp[1][K] << "\n";
    }
    return 0;
}