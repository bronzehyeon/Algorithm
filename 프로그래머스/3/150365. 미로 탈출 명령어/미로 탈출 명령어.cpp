#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int dxy[4][2] = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
char dir[4] = {'d', 'l', 'r', 'u'};

int R, C, N, M, K;
string answer = "impossible";

bool dfs(int cx, int cy, string path){
    int shortest = abs(R - cx) + abs(C - cy);
    int remain = K - path.length();
    if(shortest > remain || (remain - shortest) % 2 != 0){
        return false;
    }
    if(cx == R && cy == C && path.length() == K){
        answer = path;
        return true;
    }
    
    for(int i = 0; i < 4; i++){
        int nx = cx + dxy[i][0];
        int ny = cy + dxy[i][1];
        if(nx > N || ny > M || nx < 1 || ny < 1){
            continue;
        }
        string np = path+dir[i];
        if(dfs(nx, ny, np)){
            return true;
        }
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    
    R = r;
    C = c;
    N = n;
    M = m;
    K = k;
    
    dfs(x,y,"");
    
    return answer;
}