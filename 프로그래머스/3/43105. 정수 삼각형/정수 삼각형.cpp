#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int dp[500][500];
    memset(dp,0,sizeof(dp));
    dp[0][0] = triangle[0][0];
    for(int i = 1; i < triangle.size(); i++){
        dp[i][0] = triangle[i][0] + dp[i-1][0];
        for(int j = 1; j < triangle[i].size();j++){
            dp[i][j] = max(dp[i-1][j - 1], dp[i-1][j]) + triangle[i][j];
        }
    }
    
    int n = triangle.size();
    for(int i = 0; i < n; i++){
        if(dp[n - 1][i] > answer){
            answer = dp[n-1][i];
        }
    }
    
    return answer;
}