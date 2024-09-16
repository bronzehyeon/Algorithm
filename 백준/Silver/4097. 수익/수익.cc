#include <iostream>
#include <algorithm>
using namespace std;

int N;
long arr[250000];
long dp[250000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true) {
        cin >> N;
        if (N == 0) {
            break;
        }
        cin >> arr[0];
        dp[0] = arr[0];
        long ans = dp[0];
        for (int i = 1; i < N; i++) {
            cin >> arr[i];
            dp[i] = max(dp[i - 1] + arr[i], arr[i]);
            ans = max(ans, dp[i]);
        }

        cout << ans << '\n';
    }
    

    
}