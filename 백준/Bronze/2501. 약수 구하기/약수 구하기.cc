#include <iostream>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    int count = 0;
    for (int i = 1; i <= N; i++) {
        if (N % i == 0) {
            count++;
            if (count == K) {
                cout << i << '\n';
                break;
            }
        }
        if (i == N && count < K) {
            cout << '0' << '\n';
        }
    }
}
