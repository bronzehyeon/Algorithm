#include <iostream>
#include <set>
#include <map>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for(int t = 0; t < T; t++) {
		int N;
		cin >> N;

		if (N == 0) {
			cout << 0 << '\n';
			continue;
		}

		set<string> s;
		map<string, int> m;

		for (int i = 0; i < N; i++) {
			string name, type;
			cin >> name >> type;
			
			s.insert(type);
			m[type]++;
		}

		int cnt = 1;

		for (auto iter = s.begin(); iter != s.end(); iter++) {
			cnt *= m[*iter] + 1;
		}

		cout << cnt - 1 << '\n';
	}
	return 0;

}