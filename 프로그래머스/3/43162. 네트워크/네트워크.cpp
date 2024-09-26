#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    
    vector<bool> visited(n,0);
    
    for(int i = 0; i < n; i++){
        if(visited[i]){
            continue;
        }
        answer++;
        queue<int> q;
        q.push(i);
        visited[i] = true;
        
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(int j = 0; j < n; j++){
                if(!visited[j] && computers[cur][j] == 1){
                    q.push(j);
                    visited[j] = true;
                }
            }
        }
    }
    
    return answer;
}