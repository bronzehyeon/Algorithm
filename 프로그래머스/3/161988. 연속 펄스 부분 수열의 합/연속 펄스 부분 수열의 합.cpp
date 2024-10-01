#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(vector<int> sequence) {
    long long answer = 0;
    
    int N = sequence.size();
    
    if(N == 1){
        return max(sequence[0], -sequence[0]);
    }
        
    long long dp[500001][2];
    
    long long maxSum = 0;
    long long minSum = 0;
    
    dp[0][0] = -sequence[0];
    dp[0][1] = -sequence[0];

    for(int i = 1; i < N; i++){
        if(i % 2 == 0){
            sequence[i] *= -1;
        }
        long long s = sequence[i];
        dp[i][0] = max(dp[i-1][0] + s, s);
        dp[i][1] = min(dp[i-1][1] + s, s);
        maxSum = max(maxSum, dp[i][0]);
        minSum = min(minSum, dp[i][1]);
    }
    
    answer = max(maxSum, -minSum);
    
    return answer;
}