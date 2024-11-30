#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    int N = A.size();

    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<>());
    
    for (int i = 0; i < N; i++) {
        answer += A[i] * B[i];
        // cout << A[i] << " " << B[i] << '\n';
    }

    return answer;
}