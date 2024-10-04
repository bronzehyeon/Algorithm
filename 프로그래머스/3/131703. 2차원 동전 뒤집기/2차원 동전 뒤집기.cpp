#include <string>
#include <vector>
#include <iostream>

using namespace std;

int N, M;
vector<int> row;

vector<vector<int>> diff;
int answer = 30;

int solve(){
    int cnt = 0;
    
    for(int i = 0; i < N; i++){
        if(row[i]){
            //cout<<i<<" ";
            cnt++;
        }
    }
    //cout<<'\n';
    
    for(int j = 0; j < M; j++){
        int base = diff[0][j] ^ row[0];
        for(int i = 1;i < N;i++){
            if((diff[i][j] ^ row[i]) != base){
                //cout<<i<< ", "<<j<<" : "<<diff[i][j]<<'\n';
                return 30;
            }
        }
        if(base){//다르면
            cnt++;
        }
    }
    
    return cnt;
}

void chooseRow(int idx){
    if(idx == N){
        answer = min(answer, solve());
        return;
    }
    row[idx] = true;
    chooseRow(idx + 1);
    row[idx] = false;
    chooseRow(idx + 1);
}

int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    N = beginning.size();
    M = beginning[0].size();
    
    row.resize(N, false);
    diff.resize(N, vector<int>(M));
    
    for(int i = 0; i < N ; i++){
        for(int j = 0; j < M;j++){
            diff[i][j] = (beginning[i][j] != target[i][j]);
            //cout<<diff[i][j]<<" ";
        }
        //cout<< '\n';
    }
    chooseRow(0);
    if(answer == 30){
        return -1;
    }
    return answer;
}