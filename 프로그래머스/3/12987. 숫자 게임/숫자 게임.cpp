#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    int N = A.size();
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int pa = 0;
    int pb = 0;
    
    while (pa < N && pb < N) {
        while (A[pa] >= B[pb] && pb < N) {
            pb++;
        }
        if(pb == N) {
            break;
        }
        pa++;
        pb++;
        answer++;
    }
    
    return answer;
}