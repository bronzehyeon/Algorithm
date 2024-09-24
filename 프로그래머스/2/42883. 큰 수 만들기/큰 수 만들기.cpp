#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int N =number.length();
    int len = N - k;
    int start = 0;
    
    for(int i = 0; i < len; i++){
        int maxNum = -1;
        int idx = i;
        for(int j = start; j < N - len + i + 1;j++){
            if(maxNum < number[j] - '0'){
                maxNum = number[j] - '0';
                idx = j;
            }
        }
        answer += number[idx];
        start = idx + 1;
    }
    
    return answer;
}