#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    
    if(n == 1){
        if(lost.size()<=reserve.size()){
            return 1;
        }
        else{
            return 0;
        }
    }
    
    vector<int> v(n+1, 1);
    
    for(int i = 0; i < reserve.size(); i++){
        v[reserve[i]]++;
    }
    
    for(int i = 0; i < lost.size();i++){
        v[lost[i]]--;
    }
    
    if(v[1] == 0){
        if(v[2] == 2){
            v[2]--;
            v[1]++;
        }
        else{
            answer--;
        }
    }
    
    for(int i = 2; i < n; i++){
        if(v[i] == 0){
            if(v[i-1] == 2){
                v[i - 1]--;
                v[i]++;
            }
            else if(v[i+1] == 2){
                v[i + 1]--;
                v[i]++;
            }
            else{
                answer--;
            }
        }
        
    }
    
    if(v[n] == 0){
        if(v[n - 1] == 2){
            v[n - 1]--;
            v[n]++;
        }
        else{
            answer--;
        }
    }
    return answer;
}