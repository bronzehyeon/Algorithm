#include <string>
#include <vector>
#include <algorithm>

using namespace std;
    
int answer = 0;

void isPrime(long long x){
    if(x == 1){
        return;
    }
    for(long long i = 2; i * i <= x; i++){
        if(x % i == 0){
            return;
        }
    }
    answer++;
}

int solution(int n, int k) {
    
    string num = "";
    
    while(n > 0){
        int tmp = n % k;        
        n /= k;
        if(tmp == 0){
            if(num.length() == 0){
                continue;
            }
            reverse(num.begin(), num.end());
            isPrime(stoull(num));
            num = "";
            continue;
        }
        num += to_string(tmp);
    }
    if(num.length() != 0){
        reverse(num.begin(), num.end());
        isPrime(stoull(num));
    }
    
    
    return answer;
}