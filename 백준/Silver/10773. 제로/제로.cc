#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<int> stack;

    int K;
    cin >> K;
    for (int i = 0; i < K; i++){
        int N;
        cin >> N;
        if (N == 0) {
            stack.pop();
        }
        else {
            stack.push(N);
        }
    }
    int sum = 0;
    while (!stack.empty()) {
        sum += stack.top();
        stack.pop();
    }
    cout << sum;
}