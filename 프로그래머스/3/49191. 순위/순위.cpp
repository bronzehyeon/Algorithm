#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    vector<vector<int>> result(n + 1, vector<int>(n + 1, 0));
    
    for (int i = 0; i < results.size(); i++) {
        int winner = results[i][0];
        int loser = results[i][1];
        
        result[winner][loser] = 1;
        result[loser][winner] = -1;
    }
    
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (result[i][j] != 0) {
                    continue;
                }
                if (i == j) {
                    result[i][j] = 1;
                    continue;
                }
                if (result[i][k] == 1 && result[k][j] == 1) {
                    result[i][j] = 1;
                    result[j][i] = -1;
                }
                if (result[i][k] == -1 && result[k][j] == -1) {
                    result[i][j] = -1;
                    result[j][i] = 1;
                }
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (result[i][j] == 0) {
                break;
            }
            if (j == n){
                answer++;
            }
        }
    }
    
    return answer;
}