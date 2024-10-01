#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;


vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    
    vector<vector<pair<int,int>>> graph(n + 1);
    vector<int> intensity(n + 1, -1);
    vector<bool> isSummit(n + 1, false);
    
    vector<int> course;
    
    int minDist = 10000000;
    
    for(int i = 0 ;i < paths.size();i++){
        int u = paths[i][0];
        int v = paths[i][1];
        int dist = paths[i][2];
        
        graph[u].push_back({dist, v});
        graph[v].push_back({dist, u});
    
    }
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    for(int i = 0; i < gates.size(); i++){
        pq.push({0, gates[i]});
        intensity[gates[i]] = 0;
    }
    for(int i = 0; i < summits.size(); i++){
        isSummit[summits[i]] = true;
    }
    
    while(!pq.empty()){
        int dist = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        if(dist > intensity[cur]){
            continue;
        }
        
        if(isSummit[cur] && dist <= minDist){
            minDist = dist;
            course.push_back(cur);
            continue;
        }
        
        for(int i = 0; i < graph[cur].size(); i++){
            int w = graph[cur][i].first;
            int next = graph[cur][i].second;
            
            if(intensity[next] == -1 || intensity[next] > max(w, dist)){
                intensity[next] = max(w, dist);
                pq.push({intensity[next], next});
            }
        }
    }
    
    sort(course.begin(), course.end());
    answer.push_back(course[0]);
    answer.push_back(minDist);
    
    return answer;
}