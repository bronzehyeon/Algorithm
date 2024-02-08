#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N, M;
        cin >> N >> M;

        int answer = 1;

        for (int i = 0; i < N; i++) {
            answer *= (M - i);
            answer /= (i + 1);
        }

        cout << answer << '\n';
    }
}