#include <string>
#include <vector>
#include <queue>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    priority_queue<int> pq;
    
    for(int i = 0; i < works.size(); i++){
        pq.push(works[i]);
    }
    
    while(n-- && !pq.empty() ){
        int x = pq.top();
        pq.pop();
        x--;
        
        if (x > 0) {
            pq.push(x);
        }
    }
    
    while(!pq.empty()){
        long long x = pq.top();
        pq.pop();
        answer += x * x;
    }
    
    return answer;
}