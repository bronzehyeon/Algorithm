#include <iostream>
using namespace std;

int N;
long long arr[500][2];

long long dp[500][500];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }

    dp[0][1] = arr[0][0] * arr[0][1] * arr[1][1];


    for (int i = 2; i < N; i++) {
        dp[i - 1][i] = arr[i - 1][0] * arr[i][0] * arr[i][1];
        //cout<<i - 1 << "~" << i << " : " << dp[i - 1][i] << '\n';
        for (int j = i - 2; j >= 0; j--) {
            dp[j][i] = dp[j][i - 1] + arr[j][0] * arr[i - 1][1] * arr[i][1];
            /*cout << "dp[j][i-1] : " << dp[j][i - 1] << "\n";
            cout << "arr[j][0] * arr[i - 1][1] + arr[i][1] : " << arr[j][0] * arr[i - 1][1] * arr[i][1] << '\n';
            cout << j << "~" << i << " : " << dp[j][i] << '\n';*/
            for (int k = j; k < i; k++) {
                dp[j][i] = min(dp[j][i], dp[j][k] + dp[k + 1][i] + arr[j][0] * arr[k][1] * arr[i][1]);
                //cout << j << "~" << i << " : " << dp[j][i] << '\n';
            }
        }
    }

    cout << dp[0][N - 1];
}
