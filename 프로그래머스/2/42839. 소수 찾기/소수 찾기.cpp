#include <string>
#include <vector>
#include <iostream>

using namespace std;

int N;
int answer = 0;
int num[10];

bool check(int x){
    if(x == 1 || x == 0){
        return false;
    }
    for(int i = 2; i * i <= x; i++){
        if(x % i == 0){
            return false;
        }
    }
    return true;
}

void search(int x, int cnt){
    if(check(x)){
        answer++;
    }
    
    if(cnt == N){
        return;
    }
    
    for(int i = 0; i<10;i++){
        if(num[i] > 0){
            num[i]--;
            search(x * 10 + i, cnt + 1);
            num[i]++;
        }
    }
}

int solution(string numbers) {
    N = numbers.length();
    
    for(int i = 0; i < N; i++){
        num[numbers[i] - '0']++;
    }
    
    for(int i = 1; i < 10; i++){
        if(num[i] > 0){
            num[i]--;
            search(i, 1);
            num[i]++;
        }
    }
    
    
    return answer;
}