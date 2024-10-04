#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<bool>> visitedB(4, vector<bool>(4, false));
vector<vector<bool>> visitedR(4, vector<bool>(4, false));

int N, M;
int dxy[2][4] = {{1,-1,0,0}, {0,0,1,-1}};

int minMove = 20;

void dfs(int rx, int ry, int bx, int by, int cnt, bool red, bool blue, vector<vector<int>>& maze){
    if(red && blue){
        minMove = min(cnt, minMove);
        return;
    }
    if(red){
        for(int j = 0; j < 4; j++){
            int nbx = bx + dxy[0][j];
            int nby = by + dxy[1][j];

            if(nbx >= N || nby >= M || nbx < 0 || nby < 0 || visitedB[nbx][nby] || maze[nbx][nby] == 5){
                continue;
            }
            if(nbx == rx && nby == ry){
                continue;
            }
            if(maze[nbx][nby] == 4){
                blue = true;
            }
            visitedB[nbx][nby] = true;
            dfs(rx,ry,nbx,nby,cnt + 1,red,blue, maze);
            visitedB[nbx][nby] = false;
            blue = false;
        }
        return;
    }
    
    if(blue){
        for(int i = 0; i < 4; i++){
            int nrx = rx + dxy[0][i];
            int nry = ry + dxy[1][i];

            if(nrx >= N || nry >= M || nrx < 0 || nry < 0 || visitedR[nrx][nry] || maze[nrx][nry] == 5){
                continue;
            }
            if(nrx == bx && nry == by){
                continue;
            }
            if(maze[nrx][nry] == 3){
                red = true;
            }
            visitedR[nrx][nry] = true;
            dfs(nrx,nry,bx,by,cnt + 1,red,blue, maze);
            visitedR[nrx][nry] = false;
            red = false;
        }
        return;
    }
    for(int i = 0; i < 4; i++){
        int nrx = rx + dxy[0][i];
        int nry = ry + dxy[1][i];
        if(nrx >= N || nry >= M || nrx < 0 || nry < 0 || visitedR[nrx][nry] || maze[nrx][nry] == 5){
            continue;
        }
        
        visitedR[nrx][nry] = true;
        if(maze[nrx][nry] == 3){
            red = true;
        }
        for(int j = 0; j < 4; j++){
            int nbx = bx + dxy[0][j];
            int nby = by + dxy[1][j];
            if(nbx >= N || nby >= M || nbx < 0 || nby < 0 || visitedB[nbx][nby] || maze[nbx][nby] == 5 || (nbx == nrx && nby == nry)){
                continue;
            }
            if(nbx == rx && nby == ry && nrx == bx && nry == by){
                continue;
            }
            if(maze[nbx][nby] == 4){
                blue = true;
            }
            visitedB[nbx][nby] = true;
            dfs(nrx,nry,nbx,nby,cnt + 1,red,blue, maze);
            visitedB[nbx][nby] = false;
            blue = false;
        }
        visitedR[nrx][nry] = false;
        red = false;
    }
}

int solution(vector<vector<int>> maze) {
    int answer = 0;
    
    N = maze.size();
    M = maze[0].size();
    
    int srx, sry, sbx, sby;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(maze[i][j] == 1){
                visitedR[i][j] = true;
                srx = i;
                sry = j;
            }
            else if(maze[i][j] == 2){
                visitedB[i][j] = true;
                sbx = i;
                sby = j;
            }
        }
    }
    
    dfs(srx,sry,sbx,sby,0,false,false,maze);
    
    if(minMove == 20){
        return 0;
    }
    answer = minMove;
    return answer;
}