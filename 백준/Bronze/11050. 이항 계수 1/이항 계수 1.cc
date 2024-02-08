#include <iostream>
using namespace std;

int dataStructure[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    int answer = 1;

    for (int i = 0; i < K ; i++) {
        answer *= (N - i);
    }
    for (int i = 0; i < K ; i++) {
        answer /= (K - i);
    }

    cout << answer;
}