#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
    
    long long answer = 0;
    
    long long l1 = r1;
    long long l2 = r2;
    
    long long c1 = l1 * l1;
    long long c2 = l2 * l2;
    
    for(long long i = 1; i <= r2; i++){
        long long ipow = i * i;
        long long a = sqrt(c1 - ipow);
        if(a * a + ipow < c1){
            a++;
        }
        long long b = sqrt(c2 - ipow);
        answer += b - a + 1;
    }
    
    answer *= 4;
    
    return answer;
}