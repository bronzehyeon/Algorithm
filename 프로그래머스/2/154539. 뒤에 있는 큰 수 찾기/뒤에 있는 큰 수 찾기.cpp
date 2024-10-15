#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    
    int N = numbers.size();
    vector<int> answer(N, -1);
        
    int maxN = numbers[N-1];
    
    for(int i = N-2; i >= 0; i--){
        if(maxN <= numbers[i]){
            maxN = numbers[i];
            continue;
        }
        else {
            for(int j = i + 1; j < N; j++){
                if(numbers[j] <= numbers[i]){
                    if(answer[j] > numbers[i]){
                        answer[i] = answer[j];
                        break;
                    }
                }
                else{
                    answer[i] = numbers[j];
                    break;
                }
            }
        }
    }
    
    return answer;
}