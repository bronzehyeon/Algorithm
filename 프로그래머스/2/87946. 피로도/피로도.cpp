#include <string>
#include <vector>

using namespace std;
int answer = -1;
int N;
bool visited[8];

void dfs(int k, vector<vector<int>> dungeons, int cnt){
    if(cnt > answer){
        answer = cnt;
    }
    for(int i = 0; i < N; i++){
        if(!visited[i] && dungeons[i][0] <= k){
            visited[i] = true;
            dfs(k - dungeons[i][1], dungeons, cnt + 1);
            visited[i] = false;
        }
    }
    return;
}

int solution(int k, vector<vector<int>> dungeons) {
    N = dungeons.size();
    for(int i = 0; i < N; i++){
        if(dungeons[i][0] <= k){
            visited[i] = true;
            dfs(k - dungeons[i][1], dungeons, 1);
            visited[i] = false;
        }
    }
    
    return answer;
}