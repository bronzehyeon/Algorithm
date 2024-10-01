#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> scores) {
    int answer = 1;
    
    int fs = scores[0][0];
    int ss = scores[0][1];
    
    sort(scores.begin() + 1, scores.end());
    
    for(int i = 1; i<scores.size(); i++){
        //cout << scores[i][0]<< " "<< scores[i][1]<<'\n';
        int sum = scores[i][0] + scores[i][1];
        if(sum <= fs+ss){//완호보다 낮은 등수는 고려 x
            continue;
        }
        if(scores[i][0] > fs && scores[i][1] > ss){
            return -1;
        }
        bool noInsen = false;
        for(int j = i + 1; j < scores.size(); j++){
            if(scores[j][0] > scores[i][0] && scores[j][1] > scores[i][1]){
                noInsen = true;
                break;
            }
        }
        if(!noInsen){
            answer++;
        }
    }
    
    return answer;
}