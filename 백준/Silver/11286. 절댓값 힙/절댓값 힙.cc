#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    priority_queue<int> plus;
    priority_queue<int> minus;

    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;

        if (tmp == 0) {
            if (!plus.empty() && !minus.empty()) {
                if (plus.top() > minus.top()) {
                    cout << -plus.top() << '\n';
                    plus.pop();
                }
                else {
                    cout << minus.top() << '\n';
                    minus.pop();
                }
            }
            else if (!plus.empty()) {
                cout << -plus.top() << '\n';
                plus.pop();
            }
            else if (!minus.empty()) {
                cout << minus.top() << '\n';
                minus.pop();
            }
            else {
                cout << 0 << '\n';
            }

        }
        else if (tmp > 0)
            plus.push(-tmp);
        else
            minus.push(tmp);
    }



}

    