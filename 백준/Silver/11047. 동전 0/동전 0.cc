#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    int coin[10];
    int count = 0;

    for (int i = 0; i < N; i++) {
        cin >> coin[i];
    }

    for (int i = N - 1; i >= 0; i--) {
        int tmp = K / coin[i];
        K -= tmp * coin[i];
        count += tmp;
    }

    cout << count;
}