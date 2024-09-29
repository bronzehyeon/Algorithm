#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    vector<vector<int>> dist(m + 1, vector<int>(n + 1, 1));
    
    for(int i = 0; i < puddles.size(); i++){
        int x = puddles[i][0];
        int y = puddles[i][1];
        dist[x][y] = 0;
        if(x == 1){
            for(int i = y; i <= n; i++){
                dist[1][i] = 0;
            }
        }
        if(y == 1){
            for(int i = x; i <= m; i++){
                dist[i][1] = 0;
            }
        }
    }
    
    for(int i = 2; i <= m; i++){
        for(int j = 2; j <= n; j++){
            if(dist[i][j] == 0){
                continue;
            }
            dist[i][j] = (dist[i - 1][j] + dist[i][j - 1]) % 1000000007;
        }
    }
    answer = dist[m][n];
    return answer;
}