#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    bool possible = false;
    for (int i = N / 5; i >= 0; i--) {
        for (int j = 0; j <= (N - (5 * i)) / 3; j++) {
            if (5 * i + j * 3 == N) {
                possible = true;
                cout << i + j;
                break;
            }
        }
        if (possible) break;
    }
    if(!possible)
        cout << -1;
}
