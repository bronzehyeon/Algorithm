#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

pair<int,int> move(int cx, int cy, int dx, int dy){
    if(cx < dx){
        return {cx + 1, cy};
    }
    else if(cx > dx){
        return {cx - 1, cy};
    }
    else if(cy < dy){
        return {cx, cy + 1};
    }
    else{
        return {cx, cy - 1};
    }
}

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    
    int n = points.size();
    int r = routes.size();//로봇 갯수
    int m = routes[0].size();
    
    vector<map<pair<int,int>, int>> v(20001);
    
    for(int i = 0; i < r; i++){
        int point = routes[i][0] - 1;

        int curx = points[point][0];
        int cury = points[point][1];
        v[0][{curx,cury}]++;
        int time = 1;
        for(int j = 1; j < routes[i].size(); j++){
            int destx = points[routes[i][j] - 1][0];
            int desty = points[routes[i][j] - 1][1];
            while(true){
                if(curx == destx && cury == desty){
                    break;
                }
                pair<int,int> p = move(curx,cury,destx,desty);
                curx = p.first;
                cury = p.second;
                
                v[time][{curx,cury}]++;
                time++;
                
            }
        }
    }
    
    for(int i = 0; i < v.size(); i++){
        auto iter = v[i].begin();
        while(iter != v[i].end()){
            if(iter->second > 1){
                answer++;
            }
            iter++;
        }
    }
    
    return answer;
}