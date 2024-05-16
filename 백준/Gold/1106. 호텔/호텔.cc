#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int C, N;
    cin >> C >> N;

    int cost[20];
    int people[20];

    int dp[1000001];


    for (int i = 0; i < N; i++) {
        cin >> cost[i] >> people[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= 100000; j++) {

            if (j - cost[i] >= 0) {
                dp[j] = max(dp[j], dp[j - cost[i]] + people[i]);
            }
        }
    }

    for (int i = 1; i <= 100000; i++) {
        if (dp[i] >= C) {
            cout << i;
            break;
        }
    }

}
