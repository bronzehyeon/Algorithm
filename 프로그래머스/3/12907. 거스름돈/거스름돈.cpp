#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> money) {
    int answer = 0;
    
    int N = money.size();
    
    sort(money.begin(), money.end());
    
    vector<int> dp(n+1, 0);

    dp[0] = 1;
    
    for (int i = 0; i < N; i++) {
        int coin = money[i];
        for (int j = coin; j <= n; j++) {
            dp[j] += dp[j - coin];
        }
    }
    
    return dp[n];
}