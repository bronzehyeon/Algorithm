#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scov, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i = 0; i < scov.size(); i++){
        pq.push(scov[i]);
    }
    while(pq.top() < K){
        int a = pq.top();
        pq.pop();
        if(pq.empty()){
            return -1;
        }
        int b = pq.top();
        pq.pop();
        pq.push(a + 2 * b);
        
        answer++;
    }
    return answer;
}