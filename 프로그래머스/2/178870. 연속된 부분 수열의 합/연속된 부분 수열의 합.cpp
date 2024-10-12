#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int N = sequence.size();
    vector<int> dp(N);
    
    int s = 0;
    int e = 0;
    int p = 0;
    int sum = 0;
    
    int minLen = N;
    
    for(int i = 0; i < N; i++){
        sum += sequence[i];
        
        if(sum > k){
            while(sum > k){
                sum -= sequence[p];
                p++;
            }
                
        }
        if(sum == k){
            if(i - p < minLen){
                minLen = i - p;
                s = p;
                e = i;
            }
        }
        
    }
    
    answer.push_back(s);
    answer.push_back(e);
    
    return answer;
}