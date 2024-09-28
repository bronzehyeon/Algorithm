#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> pr, int location) {
    int answer = 1;
    
    queue<pair<int,int>> q;
    vector<int> v;
    for(int i = 0; i < pr.size(); i++){
        q.push({pr[i], i});
        v.push_back(pr[i]);
    }
    
    sort(v.begin(), v.end(), greater<>());
    int idx = 0;
    while(true){
        while(q.front().first != v[idx]){
            int pri = q.front().first;
            int loc = q.front().second;
            q.pop();
            q.push({pri, loc});
        }
        
        if(q.front().second == location){
            break;
        }
        q.pop();
        idx++;
        answer++;
    }
    
    return answer;
}