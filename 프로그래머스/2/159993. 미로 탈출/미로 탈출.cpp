#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<string> maps) {
    int answer = 0;
    int N = maps.size();
    int M = maps[0].length();
    
    int sx,sy,lx,ly,ex,ey;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if (maps[i][j] == 'S'){
                sx = i;
                sy = j; 
            }
            else if (maps[i][j] == 'L') {
                lx = i;
                ly = j;
            }
            else if (maps[i][j] == 'E') {
                ex = i;
                ey = j;
            }
        }
    }
    
    vector<vector<int>> visited(N, vector<int>(M, 0));
    int dxy[2][4] = {{1,-1,0,0},{0,0,1,-1}};
    queue<pair<int,pair<int,int>>> q;
    q.push({0,{sx,sy}});
    visited[sx][sy] = true;
    int SL = -1;
    
    while(!q.empty()){
        int cnt = q.front().first;
        int cx = q.front().second.first;
        int cy = q.front().second.second;
        q.pop();

        if(cx == lx && cy == ly){
            SL = cnt;
            break;
        }
        
        for(int i = 0; i < 4; i++){
            int nx = cx + dxy[0][i];
            int ny = cy + dxy[1][i];
            
            if(nx >= N || nx < 0 
               || ny >= M || ny < 0 
               || visited[nx][ny] || maps[nx][ny] == 'X'){
                continue;
            }
            visited[nx][ny] = true;
            q.push({cnt+1,{nx,ny}});
        }
    }
    if(SL == -1){
        cout<<"SL\n";
        return -1;
    }
    
    q = queue<pair<int,pair<int,int>>>();
    vector<vector<int>> visited2(N, vector<int>(M, 0));
    q.push({0,{lx,ly}});
    visited2[lx][ly] = true;
    int LE = -1;
    
    while(!q.empty()){
        int cnt = q.front().first;
        int cx = q.front().second.first;
        int cy = q.front().second.second;
        q.pop();
        
        if(cx == ex && cy == ey){
            LE = cnt;
            break;
        }
        
        for(int i = 0; i < 4; i++){
            int nx = cx + dxy[0][i];
            int ny = cy + dxy[1][i];
            
            if(nx >= N || nx < 0 
               || ny >= M || ny < 0 
               || visited2[nx][ny] || maps[nx][ny] == 'X'){
                continue;
            }
            visited2[nx][ny] = true;
            q.push({cnt+1,{nx,ny}});
        }
    }
    if(LE == -1){
        return -1;
    }
    answer = SL + LE;
    
    return answer;
}