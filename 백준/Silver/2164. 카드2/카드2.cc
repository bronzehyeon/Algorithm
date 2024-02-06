#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    queue<int> Q;
    for (int i = 1; i <= N; i++) {
        Q.push(i);
    }
    while (Q.size() != 1) {
        Q.pop();
        int tmp = Q.front();
        Q.pop();
        Q.push(tmp);
    }
    cout << Q.front();
}