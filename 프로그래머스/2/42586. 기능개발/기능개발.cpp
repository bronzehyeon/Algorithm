#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prog, vector<int> sp) {
    vector<int> answer;
    int N = prog.size();
    int idx = 0;
    while(idx < N){
        int cnt = 0;
        
        for(int i = idx; i < N; i++){
            prog[i] += sp[i];\
        }
        if(prog[idx] >= 100){
            int cnt = 0;
            while(prog[idx] >= 100 && idx <N){
                idx++;
                cnt++;
            }
            answer.push_back(cnt);
        }
    }
    
    return answer;
}