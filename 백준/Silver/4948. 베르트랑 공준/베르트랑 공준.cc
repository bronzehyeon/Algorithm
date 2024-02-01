#include <iostream>
using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true) {
        int N;
        cin >> N;
        if (N == 0)break;

        int count = 0;

        for (int i = N + 1; i <= 2 * N; i++) {
            bool prime = true;
            for (int j = 2; (j * j) <= i; j++) {
                if (i % j == 0) {
                    prime = false;
                    break;
                }
            }
            if (prime) {
                count++;
            }
        }
        cout << count << '\n';
    }
}