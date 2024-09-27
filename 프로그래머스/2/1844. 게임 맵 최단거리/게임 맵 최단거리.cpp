#include<vector>
#include<queue>

using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = -1;
    
    int n = maps.size();
    int m = maps[0].size();
    
    int dxy[2][4] = {{1,-1,0,0} , {0,0,1,-1}};
    
    vector<vector<bool>> visited(n, vector<bool>(m, 0));
    
    queue<pair<int,pair<int,int>>> q;
    q.push({1,{0,0}});
    visited[0][0] = true;
    
    while(!q.empty()){
        int curx = q.front().second.first;
        int cury = q.front().second.second;
        int cnt = q.front().first;
        q.pop();
        
        if(curx == n-1 && cury == m-1){
            answer = cnt;
            break;
        }
        
        for(int i = 0; i < 4; i++){
            int nx = curx+dxy[0][i];
            int ny = cury+dxy[1][i];
            
            if(nx < 0 || ny < 0 || nx>=n || ny>= m){
                continue;
            }
            
            if(!visited[nx][ny] && maps[nx][ny] == 1){
                q.push({cnt + 1, {nx,ny}});
                visited[nx][ny] = true;
            }
        }
    }
    
    return answer;
}