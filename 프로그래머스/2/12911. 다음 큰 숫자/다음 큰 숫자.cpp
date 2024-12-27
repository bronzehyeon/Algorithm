#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int countOne(int n) {
    int binary = 0;

    while (n > 0) {
        if (n % 2 == 1) {
            binary ++;
        } 
        n /= 2;
    }
    
    return binary;
}

int solution(int n) {
    
    int oneCount = countOne(n);
    
    while (++n) {
        if (countOne(n) == oneCount) {
            return n;
        }
    }
    
}