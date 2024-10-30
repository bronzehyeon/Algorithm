#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer(n, 0);
    
    if(s / n == 0){
        vector<int> v = {-1};
        return v;
    }
    
    for (int i = 0; i < n; i++) {
        answer[i] = s / n;
    }
    
    s -= s / n * n;
    int idx = n - 1;
    while (s > 0) {
        answer[idx]++;
        idx--;
        s--;
    }
    
    return answer;
}