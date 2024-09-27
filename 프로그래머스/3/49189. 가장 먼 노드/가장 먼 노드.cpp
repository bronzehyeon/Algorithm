#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    vector<int> graph[n + 1];
    vector<bool> visited(n + 1,0);
    
    for(int i = 0; i < edge.size(); i++){
        int u = edge[i][0];
        int v = edge[i][1];
        
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    vector<int> dist(n+1, 0);
    
    queue<pair<int,int>> q;
    q.push({1, 0});
    int maxDist = 0;
    visited[1] = true;
    
    while(!q.empty()){
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        maxDist = max(maxDist, cnt);
        dist[cnt]++;
        
        for(int i = 0; i < graph[cur].size(); i++){
            int next = graph[cur][i];
            if(!visited[next]){
                visited[next] = true;
                q.push({next, cnt + 1});
            }
        }
    }
    
    answer = dist[maxDist];
    return answer;
}