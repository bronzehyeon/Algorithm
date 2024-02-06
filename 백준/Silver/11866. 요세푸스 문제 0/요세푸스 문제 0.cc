#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    queue<int> Q;
    for (int i = 1; i <= N; i++) {
        Q.push(i);
    }
    cout << "<";
    while (!Q.empty()) {
        for (int i = 0; i < K - 1; i++){
            int tmp = Q.front();
            Q.pop();
            Q.push(tmp);
        }
        cout << Q.front();
        Q.pop();
        if (!Q.empty())
            cout << ", ";
    }
    cout << ">";
}