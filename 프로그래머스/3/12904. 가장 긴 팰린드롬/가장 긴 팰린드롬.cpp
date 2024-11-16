#include <iostream>
#include <string>
#include <vector>

using namespace std;
int solution(string s)
{
    int answer=1;
    
    int N = s.length();
    
    vector<vector<bool>> dp(N, vector<bool>(N, false));
    
    dp[0][0] = true;
    for (int i = 1; i < N; i++) {
        dp[i][i] = true;
        if (s[i - 1] == s[i]) {
            dp[i - 1][i] = true;
            answer = max(answer, 2);
        }
        for (int j = 0; j < i; j++) {
            if (dp[j + 1][i - 1] && s[j] == s[i]) {
                dp[j][i] = true;
                if (i - j + 1 > answer) {
                    answer = i - j + 1;
                }
            }
        }
    }

    return answer;
}