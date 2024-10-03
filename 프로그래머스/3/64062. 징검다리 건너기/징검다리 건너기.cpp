#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 1;
    
    int s = *min_element(stones.begin(), stones.end());
    int e = *max_element(stones.begin(), stones.end());
    
    
    
    while(s<=e){
        int m = (s + e) / 2;
        
        int skip = 0;
        int maxSkip = 0;
        
        for(int i = 0; i < stones.size(); i++){
            int num = stones[i];
            if(num - m < 0){//0이 포함되지 않는 이유, m번째가 건너야 0이 되는 거니 m번째 사람 까지는 건널 수 있다
                skip++;
                maxSkip = max(maxSkip, skip);
            }
            else{
                skip = 0;
            }
        }
        
        if(maxSkip >= k){
            e = m - 1;
        }
        else{
            answer = max(answer, m);
            s = m + 1;
        }
    }
    
    return answer;
}