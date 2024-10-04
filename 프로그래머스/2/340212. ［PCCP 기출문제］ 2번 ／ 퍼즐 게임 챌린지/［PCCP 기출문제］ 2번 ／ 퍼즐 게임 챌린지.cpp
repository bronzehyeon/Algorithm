#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 2147483647;
    
    int N = diffs.size();
    
    int s = 1;
    int e = 100000;
    
    while(s <= e){
        int m = (s + e) / 2;
        long long time_prev = 0;
        long long total_time = 0;
        for(int i = 0; i < N; i++){
            long long time_cur = times[i];
            if(diffs[i] <= m){
                time_prev = time_cur;
                total_time += time_cur;
            }
            else{
                total_time += (time_cur + time_prev) * (diffs[i] - m) + times[i];
                time_prev = time_cur;
            }
        }
        if(total_time <= limit){
            answer = min(answer,m);
            e = m - 1;
        }
        else{
            s = m+1;
        }
    }
    return answer;
}