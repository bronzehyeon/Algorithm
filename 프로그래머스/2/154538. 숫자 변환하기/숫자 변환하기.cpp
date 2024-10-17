#include <string>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

int solution(int x, int y, int n) {
    int answer = -1;
    
    unordered_set<int> us;
    
    queue<pair<int,int>> q;
    q.push({x,0});
    if(x == y){
        return 0;
    }
    
    while(!q.empty()){
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if(cur > y){
            continue;
        }
        
        int nx[3];
        nx[0] = cur + n;
        nx[1] = cur * 2;
        nx[2] = cur * 3;
        
        for(int i = 0; i < 3; i++){
            if(us.find(nx[i]) == us.end()){
                if(nx[i] == y){
                    return cnt + 1;
                }
                else{
                    us.insert(nx[i]);
                    q.push({nx[i], cnt + 1});
                }
            }
        }
        
    }
    
    return answer;
}