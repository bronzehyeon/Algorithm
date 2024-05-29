#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		string s;
		cin >> s;
		if (s[0] == '0') break;

		string rs = s;
		reverse(rs.begin(), rs.end());

		for (int i = 0; i < s.size(); i++) {
			if (s[i] != rs[i]) {
				cout << "no\n";
				break;
			}
			if (i == s.size() - 1) {
				cout << "yes\n";
			}
		}

	}
}