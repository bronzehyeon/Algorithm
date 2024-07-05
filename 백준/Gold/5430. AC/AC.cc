#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		string p;
		cin >> p;

		int n;
		cin >> n;

		char left, right;
		cin >> left;

		char comma;

		deque<int> dq;

		for (int i = 0; i < n * 2 - 1; i++) {
			if (i % 2 == 0) {
				int tmp;
				cin >> tmp;
				dq.push_back(tmp);
			}
			else{
				cin >> comma;
			}
		}
		cin >> right;

		//cout << dq.size()<<'\n';

		bool error = false;
		bool rv = false;

		for (int i = 0; i < p.size(); i++) {
			if (p[i] == 'R') {
				rv = !rv;
			}
			else if (p[i] == 'D') {
				if (dq.empty()) {
					error = true;
					break;
				}
				else {
					if (rv) {//뒤집혔다면 뒤에서 팝
						dq.pop_back();
					}
					else {
						dq.pop_front();
					}
				}
			}
		}

		if (error) {
			cout << "error" << '\n';
			continue;
		}
		int len = dq.size();
		cout << "[";
		for (int i = 0; i < len * 2 - 1; i++) {
			if (i % 2 == 0) {
				if (rv) {
					cout << dq.back();
					dq.pop_back();
				}
				else {
					cout << dq.front();
					dq.pop_front();
				}
			}
			else {
				cout << ",";
			}
		}
		cout << "]" << '\n';
	}

	
}