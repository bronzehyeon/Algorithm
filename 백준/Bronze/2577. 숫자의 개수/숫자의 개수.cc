#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A, B, C;

	cin >> A >> B >> C;

	int N = A * B * C;

	string s = to_string(N);


	for (int i = 0; i < 10; i++) {
		int cnt = 0;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] - '0' == i) {
				cnt++;
			}
		}
		cout << cnt << '\n';
	}


}