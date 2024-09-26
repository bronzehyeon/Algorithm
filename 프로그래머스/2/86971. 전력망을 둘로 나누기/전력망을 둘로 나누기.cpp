#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<int> graph[101];

int bfs(int s, int x){
    queue<int> q;
    q.push(s);
    int cnt = 0;
    bool visited[101];
    
    memset(visited,false,sizeof(visited));
    visited[s] = true;
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cnt++;
        
        for(int i = 0; i < graph[cur].size(); i++){
            int next = graph[cur][i];
            if(next!= x && !visited[next]){
                visited[next] = true;
                q.push(next);
            }
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 100;
    
    for(int i = 0; i < wires.size(); i++){
        int u = wires[i][0];
        int v = wires[i][1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    for(int i = 0; i < wires.size(); i++){
        int u = wires[i][0];
        int v = wires[i][1];
        
        int diff = abs(n - 2 * bfs(u,v));
        if(diff < answer){
            answer = diff;
        }
    }
    
    return answer;
}