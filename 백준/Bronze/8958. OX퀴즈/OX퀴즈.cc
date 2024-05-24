#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		int cnt = 0;
		int continuous = 0;
		for (int j = 0; j < str.length(); j++) {
			if (str[j] == 'O') {
				continuous++;
				cnt += continuous;
			}
			else {
				continuous = 0;
			}
		}
		cout << cnt << '\n';
	}

}