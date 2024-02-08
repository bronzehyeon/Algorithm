#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int answer = 1;

    for (int i = 1; i <= N; i++) {
        answer *= i;
    }

    cout << answer;
}