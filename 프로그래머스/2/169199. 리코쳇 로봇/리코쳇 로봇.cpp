#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<string> board) {
    int answer = -1;
    int N = board.size();
    int M = board[0].length();
    vector<vector<bool>> visited(N, vector<bool>(M,0));
    vector<vector<int>> arr(N, vector<int>(M,0));
    
    queue<pair<int,pair<int,int>>> q;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M;j++){
            if(board[i][j] == 'R'){
                q.push({0,{i,j}});
                visited[i][j] = true;
                break;
            }
        }
    }
    
    while(!q.empty()){
        int cnt = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();
        
        if(board[x][y] == 'G'){
            answer = cnt;
            break;
        }
        
        int i = 1;
        if(x + i < N && board[x + i][y] != 'D'){
            while(x + i < N && board[x + i][y] != 'D'){
                i++;
            }
            if(!visited[x+i-1][y]){
                q.push({cnt+1,{x+i-1,y}});
                visited[x+i-1][y] = true;
            }
        }
        i = 1;
        if(x - i >= 0 && board[x - i][y] != 'D'){
            while(x - i >= 0 && board[x - i][y] != 'D'){
                i++;
            }
            if(!visited[x-i+1][y]){
                q.push({cnt+1,{x-i+1,y}});
                visited[x-i+1][y] = true;
            }
        }
        i = 1;
        if(y + i < M && board[x][y + i] != 'D'){
            while(y + i < M && board[x][y + i] != 'D'){
                i++;
            }
            if(!visited[x][y+i-1]){
                q.push({cnt+1,{x,y+i-1}});
                visited[x][y+i-1] = true;
            }
        }
        i = 1;
        if(y - i >= 0 && board[x][y - i] != 'D'){
            while(y - i >= 0 && board[x][y - i] != 'D'){
                i++;
            }
            if(!visited[x][y-i+1]){
                q.push({cnt+1,{x,y-i+1}});
                visited[x][y-i+1] = true;
            }
        }
    }
    
    return answer;
}