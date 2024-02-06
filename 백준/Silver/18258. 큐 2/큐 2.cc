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
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;

        if (str == "push") {
            int X;
            cin >> X;
            Q.push(X);
        }
        else if (str == "pop") {
            if (Q.empty())
                cout << -1 << '\n';
            else {
                cout << Q.front() << '\n';
                Q.pop();
            }
        }
        else if (str == "size") {
            cout << Q.size() << '\n';

        }
        else if (str == "empty") {
            cout << Q.empty() << '\n';
        }
        else if (str == "front") {
            if (Q.empty())
                cout << -1 << '\n';
            else
                cout << Q.front() << '\n';
        }
        else if (str == "back") {
            if (Q.empty())
                cout << -1 << '\n';
            else
                cout << Q.back() << '\n';
        }
    }
}