#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    int N = jobs.size();
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    sort(jobs.begin(), jobs.end());
    
    int time = 0;
    int idx = 0;
    int startTime;
    int arriveTime;
    int executionTime;
    bool isRun =false;
    while(idx < N || isRun || !pq.empty()){
        while(idx < N && jobs[idx][0] <= time){
            pq.push({jobs[idx][1], jobs[idx][0]});
            idx++;
        }
        if(isRun && time - startTime >= executionTime){
            answer += time - arriveTime;
            isRun = false;
        }
        if(!isRun && !pq.empty()){
            isRun = true;
            arriveTime = pq.top().second;
            startTime = time;
            executionTime = pq.top().first;
            pq.pop();
        }
        time++;
    }
    
    answer /= N;
    
    return answer;
}