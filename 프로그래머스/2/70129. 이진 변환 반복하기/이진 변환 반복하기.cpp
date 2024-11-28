#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2, 0);
    
    int N = s.length();

    int len = 0;

    for (int i = 0; i < N; i++) {
        if (s[i] == '1') {
            len++;
        } else {
            answer[1]++;
        }
    }
    
    int num = len;
    
    while (num != 1) {
        len = 0;
        while (num > 0) {
            if (num % 2 == 0) {
                answer[1]++;
            } else {
                len++;
            }
            num /= 2;
        }
        num = len;
        answer[0]++;
    }
    
    answer[0]++;
    
    return answer;
}