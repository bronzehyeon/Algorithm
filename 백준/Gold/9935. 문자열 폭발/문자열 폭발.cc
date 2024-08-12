#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;

	string bomb;
	cin >> bomb;

	int blen = bomb.length();

	int cnt = 0;

	stack<pair<char,int>> s;

	for (int i = str.length() - 1; i >= 0; i--) {
		if (str[i] == bomb[blen - 1]) {
			s.push({ str[i], blen - 1 });
		}
		else if (!s.empty() && s.top().second != -1 && str[i] == bomb[s.top().second - 1]) {
			s.push({ str[i], s.top().second - 1 });
		}
		else {
			s.push({ str[i], -1 });
		}
		if (s.top().second == 0) {
			int n = blen;
			while (n--) {
				s.pop();
			}
		}

	}

	if (s.empty()) {
		cout << "FRULA";
	}
	else {
		while (!s.empty()) {
			cout << s.top().first;
			s.pop();
		}
	}
}

