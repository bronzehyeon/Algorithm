#include <iostream>
#include <string>
#include <stack>
using namespace std;

string str;


int sol(int idx) {
	stack<char> s;

	
	for (int i = idx; i < str.length(); i++) {
		if (str[i] == '(') {
			i = sol(i + 1);
		}
		else if (str[i] == ')') {
			while (!s.empty()) {
				cout << s.top();
				s.pop();
			}
			return i;
		}
		else if (str[i] == '+' || str[i] == '-') {
			while (!s.empty()) {
				cout << s.top();
				s.pop();
			}
			s.push(str[i]);
		}
		else if (str[i] == '*' || str[i] == '/') {
			if (!s.empty() && (s.top() == '*' || s.top() == '/')) {
				cout << s.top();
				s.pop();
			}
			s.push(str[i]);
		}
		else {
			cout << str[i];
		}
	}
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
	return idx;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> str;

	sol(0);
	
}