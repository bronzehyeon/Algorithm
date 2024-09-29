#include <vector>
#include <string>
#include <iostream>
using namespace std;

int solution(vector<string> arr)
{
    int answer = -1;
    int N = arr.size() / 2 + 1;
    vector<int> num;
    vector<bool> op;//true -> 덧셈, false -> 뺄셈
    for(int i = 0; i  < arr.size(); i++){
        if(i % 2){//홀수 -> 연산자
            if(arr[i][0] == '+'){
                op.push_back(true);
            }
            else{
                op.push_back(false);
            }
        }
        else{
            int n = 0;
            for(int j = 0; j < arr[i].length(); j++){
                n = n * 10 + arr[i][j] - '0';
            }
            num.push_back(n);
        }
    }
    
    //vector<vector<int>> dp(N, vector<int>(N, -110000));
    int dp[N][N][2];
    for(int i = 0; i < N; i++){
        dp[i][i][0] = num[i];//i부터 i까지 최댓값
        dp[i][i][1] = num[i];//i부터 i까지 최솟값
    }
    
    for(int l = 1; l < N; l++){
        for(int i = 0; i + l < N; i++){
            dp[i][i+l][0] = -110000;
            dp[i][i+l][1] = 110000;
            for(int k = i; k < i+l; k++){
                if(op[k]){
                    dp[i][i+l][0] = max(dp[i][i+l][0], dp[i][k][0] + dp[k + 1][i + l][0]);
                    dp[i][i+l][1] = min(dp[i][i+l][1], dp[i][k][1] + dp[k + 1][i + l][1]);
                }
                else{
                    dp[i][i+l][0] = max(dp[i][i+l][0], dp[i][k][0] - dp[k + 1][i + l][1]);
                    dp[i][i+l][1] = min(dp[i][i+l][1], dp[i][k][1] - dp[k + 1][i + l][0]);
                }   
            }
        }
    }
    
    answer = dp[0][N-1][0];
    
    return answer;
}