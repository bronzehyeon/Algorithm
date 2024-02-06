#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int standbyNum = 1;

    stack<int> wait;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if (a == standbyNum) {
            standbyNum++;
        }
        else {
            wait.push(a);
        }
        while (!wait.empty() && wait.top() == standbyNum) {
            standbyNum++;
            wait.pop();
        }

        
    }
    if (wait.empty())
        cout << "Nice";
    else
        cout << "Sad";
}