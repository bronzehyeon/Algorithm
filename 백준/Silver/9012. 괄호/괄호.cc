#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    

    int T;
    cin >> T;
    for (int t = 0; t < T; t++){
        stack<char> stack;
        string str;
        cin >> str;
        bool isVPS = true;
        for (int i = 0; i < str.length(); i++) {
            if(str[i] == '(')
                stack.push(str[i]);
            else {
                if (stack.empty()) {
                    isVPS = false;
                    break;
                }
                else
                    stack.pop();
            }
        }
        if (isVPS && stack.empty())
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}