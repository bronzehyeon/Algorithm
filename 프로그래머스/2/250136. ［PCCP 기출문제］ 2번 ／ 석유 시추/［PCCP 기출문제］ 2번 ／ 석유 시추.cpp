#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
#include <iostream>

using namespace std;

vector<vector<bool>> visited;
int N, M;
int dxy[2][4] = {{1,-1,0,0}, {0,0,1,-1}};
vector<int> v;
unordered_set<int> oil;

void bfs(int i, int j, vector<vector<int>>& land){
    int cnt = 0;
    queue<pair<int,int>> q;
    q.push({i,j});
    unordered_set<int> col;
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        cnt++;
        col.insert(y);
        oil.insert(y);
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = x + dxy[0][i];
            int ny = y + dxy[1][i];
            
            if(nx < 0 || ny < 0 || nx >= N || ny >= M || visited[nx][ny] || !land[nx][ny]){
                continue;
            }
            
            visited[nx][ny] = true;
            q.push({nx,ny});
        }
    }
    auto iter = col.begin();
    while(iter != col.end()){
        v[*iter] += cnt;
        iter++;
    }
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    
    N = land.size();
    M = land[0].size();
    
    visited.resize(N, vector<bool>(M, 0));
    v.resize(M,0);
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(land[i][j] == 1 && !visited[i][j]){
                visited[i][j] = true;
                bfs(i,j,land);
            }
        }
    }

    auto iter = oil.begin();
    while(iter != oil.end()){
        answer = max(answer,v[*iter]);
        iter++;
    }
    
    return answer;
}