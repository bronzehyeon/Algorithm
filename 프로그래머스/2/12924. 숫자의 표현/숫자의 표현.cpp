#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int s = 1;
    int e = 1;
    
    int sum = 1;
    
    while(e <= n) {
        if (sum < n) {
            e++;
            sum += e;
        } else if (sum == n) {
            answer++;
            sum -= s;
            s++;
        } else if (sum > n) {
            sum -= s;
            s++;
        }
    }
    
    return answer;
}