#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[1001][1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str1, str2;
    cin >> str1 >> str2;

    int N = str1.length();
    int M = str2.length();

    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (str1[i] == str2[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }
            else {
                dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }

    
    string lcs = "";
    int i = N, j = M;
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            lcs += str1[i - 1];
            i--;
            j--;
        }
        else {
            if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            }
            else {
                j--;
            }
        }
    }
    reverse(lcs.begin(), lcs.end());

    
    if (dp[N][M]) {
        cout << dp[N][M] << '\n';
        cout << lcs;
    }
    else {
        cout << dp[N][M];
    }

    return 0;
}
