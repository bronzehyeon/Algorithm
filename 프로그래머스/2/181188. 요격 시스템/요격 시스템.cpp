#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0;
    int N = targets.size();
    
    sort(targets.begin(), targets.end());
    
    for(int i = 0; i < N; i++){
        int s = targets[i][0];
        int e = targets[i][1];
        int j = i + 1;
        while(j < N){
            if(targets[j][0] < e){
                e = min(e,targets[j][1]);
            }
            else{
                break;
            }
            j++;
        }
        i = j - 1;
        answer++;
    }
    return answer;
}