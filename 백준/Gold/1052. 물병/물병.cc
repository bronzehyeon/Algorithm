#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;
    if (N <= K) {
        cout << 0;
    }
    else {
        for (int i = 0; i < K - 1; i++) {
                int b = 1;
                while (2 * b < N) {
                    b *= 2;
                }
                N -= b;
                if (N == 0) {
                    break;
                }
            }

        if (N == 0) {
            cout << 0;
        }
        else {
            int b = 1;
            while (2 * b <= N) {
                b *= 2;
            }
            if (b == N) {
                cout << 0;
            }
            else {
                cout << b * 2 - N;
            }
        }
    }
    

}

