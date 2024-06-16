#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	set<int> s;
	
	set<int> all;
	for (int j = 1; j <= 20; j++) {
		all.insert(j);
	}

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		if (str == "add") {
			int x;
			cin >> x;
			s.insert(x);
		}
		else if (str == "remove") {
			int x;
			cin >> x;
			s.erase(x);
		}
		else if (str == "check") {
			int x;
			cin >> x;
			if (s.find(x) == s.end()) {
				cout << 0 << '\n';
			}
			else {
				cout << 1 << '\n';
			}
		}
		else if (str == "toggle") {
			int x;
			cin >> x;
			if (s.find(x) == s.end()) {
				s.insert(x);
			}
			else {
				s.erase(x);
			}
		}
		else if (str == "all") {
			s = all;
		}
		else if (str == "empty") {
			s.clear();
		}
	}

	


}