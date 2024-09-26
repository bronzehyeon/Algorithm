#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int parent[100];

int find_parent(int x){
    if(x == parent[x]){
        return x;
    }
    return parent[x] = find_parent(parent[x]);
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    priority_queue<pair<int,pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
    
    for(int i = 0;i<costs.size(); i++){
        pq.push({costs[i][2],{costs[i][0],costs[i][1]}});
    }
    int cnt = 0;
    
    for(int i = 0; i < n; i++){
        parent[i]= i;
    }
    
    
    while(cnt < n - 1){
        int cost = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        
        if((x = find_parent(x)) == (y = find_parent(y))){
            continue;
        }
        //cout<<x<<" "<<y<<" "<< cost<<'\n';
        if(x < y)
            parent[y] = x;
        else
            parent[x] = y;
        cnt++;
        answer += cost;
    }
    
    return answer;
}