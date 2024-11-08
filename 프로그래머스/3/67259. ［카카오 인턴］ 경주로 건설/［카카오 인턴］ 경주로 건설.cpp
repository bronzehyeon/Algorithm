#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board) {
    int answer = 0;
    int N = board.size();
    int M = board[0].size();
    
    queue<pair<pair<int,int>,pair<int,int>>> q; // prev_dir, cost, curx, cury
    
    vector<vector<vector<int>>> v(N, vector<vector<int>>(M, vector<int>(4, 400000)));
    
    if (board[0][1] == 0) {
        v[0][1][2] = 100;
        q.push({{2,100},{0,1}});
    }
    if (board[1][0] == 0) {
        v[1][0][0] = 100;
        q.push({{0,100},{1,0}});
    }
    
    int dxy[2][4] = {{1,-1,0,0}, {0,0,1,-1}};

    while (!q.empty()) {
        int prev_dir = q.front().first.first;
        int cost = q.front().first.second;
        int curx = q.front().second.first;
        int cury = q.front().second.second;
        q.pop();
        
        
        if (v[curx][cury][prev_dir] < cost) {
            continue;
        }
        
        for (int i = 0; i < 4; i++) {
            int nx = curx + dxy[0][i];
            int ny = cury + dxy[1][i];

            if (nx >= N || ny >= M || nx < 0 || ny < 0 || board[nx][ny] == 1) {
                continue;
            }

            if (i == prev_dir) {
                if (v[nx][ny][i] > cost + 100) {
                    q.push({{i, cost + 100}, {nx, ny}});
                    v[nx][ny][i] = cost + 100;
                }
            } else {
                if (v[nx][ny][i] > cost + 600) {
                    q.push({{i, cost + 600}, {nx, ny}});
                    v[nx][ny][i] = cost + 600;
                }
            }
        }
    } 
    
    
    answer = min(v[N - 1][M - 1][0],v[N - 1][M - 1][2]);
    
    return answer;
}