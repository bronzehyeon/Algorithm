#include <string>
#include <vector>
#include <set>

using namespace std;

int dir[8][2] = {{0, 1}, {1,1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};

int solution(vector<int> arrows) {
    int answer = 0;
    
    int N = arrows.size();
    
    set<pair<pair<int,int>,pair<int,int>>> s;
    
    set<pair<int,int>> visited;

    int curX = 0;
    int curY = 0;
    visited.insert({0,0});
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 2; j++) {
            int nx = curX + dir[arrows[i]][0];
            int ny = curY + dir[arrows[i]][1];

            if(visited.find({nx,ny}) != visited.end() && 
               s.find({{curX, curY},{nx, ny}}) == s.end() && s.find({{nx, ny}, {curX, curY}}) == s.end()){
                answer++;
            }
            visited.insert({nx,ny});
            s.insert({{curX,curY}, {nx,ny}});
            curX = nx;
            curY = ny;
        }
    }
    return answer;
}