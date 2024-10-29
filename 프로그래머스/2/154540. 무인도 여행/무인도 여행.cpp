#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    vector<pair<int,int>> island;
    int N = maps.size();
    int M = maps[0].length();
    
    vector<vector<int>> visited(N, vector<int>(M, 0));
    int dxy[2][4] = {{1,-1,0,0},{0,0,1,-1}};
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(!visited[i][j] && maps[i][j] != 'X'){
                int cnt = 0;
                queue<pair<int,int>> q;
                q.push({i,j});
                visited[i][j] = true;
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    cnt += maps[x][y] - '0';
                    q.pop();
                    
                    for(int k = 0; k < 4; k++){
                        int nx = x + dxy[0][k];
                        int ny = y + dxy[1][k];
                        if(nx >= N || nx < 0 || ny < 0 || ny >= M 
                           || visited[nx][ny] || maps[nx][ny] == 'X'){
                            continue;
                        }
                        
                        visited[nx][ny] = true;
                        q.push({nx,ny});
                    }
                }
                answer.push_back(cnt);
            }
        }
    }
    sort(answer.begin(),answer.end());
    if(answer.size() == 0){
        answer.push_back(-1);
    }
    
    return answer;
}