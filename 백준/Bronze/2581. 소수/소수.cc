#include <iostream>

using namespace std;

int main() {
    int M, N;
    cin >> M >> N;
    int min = 0;
    int sum = 0;
    if (M <= 2 && N >= 2) {
        min = 2;
        sum = 2;
    }
    for (int i = M; i <= N; i++) {
        bool isPrime = true;
        for (int j = 2; j <= i; j++) {
            if (i % j == 0) isPrime = false;
            if (j == i - 1 && isPrime) {
                if (min == 0) min = i;
                sum += i;
            }
        }
    }
    if (sum != 0) {
        cout << sum << '\n';
        cout << min << '\n';
    }
    else cout << "-1" << '\n';
}