#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    

    while (true) {

        string sentence;
        getline(cin, sentence);

        if (sentence == ".")
            break;

        stack<char> bracket;
        bool isBalanced = true;
        
        for (int i = 0; i < sentence.length(); i++) {
            if (sentence[i] == '(') {
                bracket.push(sentence[i]);
            }
            else if (sentence[i] == ')') {
                if (!bracket.empty() && bracket.top() == '(') {                    
                    bracket.pop();
                }
                else {
                    isBalanced = false;
                    break;
                }
                
            }
            else if (sentence[i] == '[') {
                bracket.push(sentence[i]);
            }
            else if (sentence[i] == ']') {
                if (!bracket.empty() && bracket.top() == '[') {
                    bracket.pop();
                }
                else {
                    isBalanced = false;
                    break;
                }
            }
        }
        if (bracket.empty() && isBalanced)
            cout << "yes" << '\n';
        else
            cout << "no" << '\n';

    }
}