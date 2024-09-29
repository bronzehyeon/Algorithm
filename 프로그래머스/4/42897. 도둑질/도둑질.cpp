#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    int N = money.size();
    
    vector<int> dp(N, 0);
    dp[0] = money[0];
    dp[1] = max(money[0], money[1]);
    
    for (int i = 2; i < N - 1; ++i) {
        dp[i] = max(dp[i - 1], dp[i - 2] + money[i]);
    }
    int max1 = dp[N - 2];
    
    dp[0] = 0;
    dp[1] = money[1];
    
    for (int i = 2; i < N; ++i) {
        dp[i] = max(dp[i - 1], dp[i - 2] + money[i]);
    }
    int max2 = dp[N - 1];
    
    answer = max(max1,max2);
    
    return answer;
}