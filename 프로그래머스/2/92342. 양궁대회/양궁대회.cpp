#include <string>
#include <vector>
#include <iostream>

using namespace std;

int N;

vector<int> ryan(11);
vector<int> apeach;

vector<int> answer;

int maxDiff = 0;

void cmp() {
    for(int i = 10; i >= 0; i--) {
        if (ryan[i] > answer[i]){
            answer = ryan;
            return;
        }
        else if(ryan[i] < answer[i]){
            return;
        }
    }
}


void diff(){
    int rs = 0;
    int as = 0;
    for(int i = 0; i < 10;i++){
        int score = 10 - i;
        if(ryan[i] > apeach[i]){
            rs += score;
        }
        else{
            if(apeach[i]){
                as += score;
            }
        }
    }
    if(rs - as > 0 && rs - as >= maxDiff){
        if(rs - as == maxDiff){
            cmp();
            return;
        }
        answer = ryan;
        maxDiff = rs - as;
    }
}

void solve(int idx, int arrows){
    if(idx == 11 || arrows == 0){
        ryan[10] += arrows;
        diff();
        ryan[10] -= arrows;
        return;
    }
    
    if(arrows > apeach[idx]){//점수 얻고 통과
        ryan[idx] += apeach[idx] + 1;
        solve(idx + 1, arrows - apeach[idx] - 1);
        ryan[idx] -= apeach[idx] + 1;
    }
    
    solve(idx + 1, arrows);//얻지 않고 통과
}

vector<int> solution(int n, vector<int> info) {
    
    apeach = info;
    solve(0, n);
    
    if(answer.size() == 0){
        answer.push_back(-1);
    }
    
    return answer;
}