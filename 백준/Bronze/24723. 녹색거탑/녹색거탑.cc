#include <iostream>
using namespace std;

int dataStructure[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int answer = 1;

    for (int i = 0; i < N; i++) {
        answer *= 2;
    }

    cout << answer;
}