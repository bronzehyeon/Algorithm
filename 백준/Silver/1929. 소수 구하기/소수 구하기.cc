#include <iostream>
using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, N;
    cin >> M >> N;

    for (int i = M; i <= N; i++) {
        bool prime = true;
        for (int j = 2; (j * j) <= i; j++) {
            if (i % j == 0) {
                prime = false;
                break;
            }
        }
        if (prime && i != 1) {
            cout << i << '\n';
        }
    }
}