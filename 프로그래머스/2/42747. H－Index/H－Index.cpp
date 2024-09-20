#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(),citations.end());
    
    int maxNum = citations[citations.size() - 1];
    
    for(int i = maxNum; i > 0; i--){
        if(citations.size() - (lower_bound(citations.begin(),citations.end(), i) - citations.begin()) >= i){
            answer = i;
            break;
        }
    }
    
    return answer;
}