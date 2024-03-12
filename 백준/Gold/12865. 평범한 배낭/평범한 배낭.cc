#include <iostream>
#include <vector>
using namespace std;

int dp[101][100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> weight;
    vector<int> value;


    for (int i = 0; i < N; i++) {
        int w, v;
        cin >> w >> v;

        weight.push_back(w);
        value.push_back(v);       
    }



    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            if (weight[i - 1] <= j) {
                dp[i][j] = max(dp[i - 1][j - weight[i - 1]] + value[i - 1], dp[i - 1][j]);
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }

        }
    }

    cout << dp[N][K];

}

