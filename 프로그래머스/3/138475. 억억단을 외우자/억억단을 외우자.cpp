#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int divisor(long long x){
    int cnt = 0;
    for(long long i = 1; i * i <= x;i++){
        if(x % i == 0){
            cnt+=2;
        }
        if(i * i == x){
            cnt--;
        }
    }
    return cnt;
}

vector<int> solution(int e, vector<int> starts) {
    vector<int> answer;
    
    vector<int> div(e + 1, 1);
    
    vector<int> arr(e+1);
    
    for(int i = 2; i <= e; i++){
        for(int j = 1; j * i <= e; j++){
            div[j*i]++;
        }
    }
    
    int maxNum = div[e];
    arr[e] = e;
    for(int i = e - 1; i >= 1; i--){
        if(div[i] >= maxNum){
            arr[i] = i;
            maxNum = div[i];
        }
        else{
            arr[i] = arr[i+1];
        }
    }
    
    for(int i = 0; i < starts.size(); i++){
        answer.push_back(arr[starts[i]]);
    }
    
    return answer;
}