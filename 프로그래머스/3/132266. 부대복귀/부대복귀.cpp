#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    
    queue<pair<int,int>> q;
    q.push({destination, 0}); 
     
    vector<vector<int>> v(100001);
    
    vector<int> dist(100001, -1);
    dist[destination] = 0;
    for(int i = 0; i < roads.size();i++){
        int x = roads[i][0];
        int y = roads[i][1];
        
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    while(!q.empty()){
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        for(int i = 0; i < v[cur].size(); i++){
            int next = v[cur][i];
            if(dist[next] == -1){
                q.push({next, cnt+1});
                dist[next] = cnt + 1;
            }
        }
    }
    
    for(int i = 0; i < sources.size();i++){
        answer.push_back(dist[sources[i]]);
    }
    
    return answer;
}