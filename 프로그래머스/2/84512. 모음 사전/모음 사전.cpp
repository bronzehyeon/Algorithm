#include <string>
#include <vector>

using namespace std;

int change(char c){
    switch(c){
        case 'A':
            return 1;
        case 'E':
            return 2;
        case 'I':
            return 3;
        case 'O':
            return 4;
        case 'U':
            return 5;
    }
}

int solution(string word) {
    int answer = 0;
    
    int N = word.length();
    
    answer += N;
    
    int arr[5] = {781, 156, 31, 6, 1};
    
    for(int i = 0; i < N;i++){
        answer += (change(word[i]) - 1) * arr[i];
    }
    
    return answer;
}