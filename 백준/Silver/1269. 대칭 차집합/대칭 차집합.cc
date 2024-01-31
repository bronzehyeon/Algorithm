#include <iostream>
#include <set>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int countA_B = N;
    int countB_A = 0;

    set<int> A;

    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        A.insert(tmp);
    }

    for (int i = 0; i < M; i++) {
        int tmp;
        cin >> tmp;
        if (A.find(tmp) != A.end())
            countA_B--;
        else
            countB_A++;
    }

    cout << countA_B + countB_A;
    
    return 0;
}