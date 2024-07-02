#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N, M;
vector<int> v;
char P[2] = { 'I', 'O' };
string str;

int countP(int idx) {
	int cnt = 0;
	for (int i = idx; i < M; i++) {
		if (str[i] != P[(i - idx) % 2]) {
			break;
		}
		cnt++;
	}
	if (cnt % 2 == 1) {
		v.push_back(cnt / 2);
	}
	else {
		v.push_back(cnt / 2 - 1);
	}
	return cnt;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	cin >> str;

	for (int i = 0; i < M; i++) {
		if (str[i] == 'I') {
			int P = countP(i);
			if (P > 1) {
				i += P - 1;
			}
		}
	}

	int ans = 0;

	for (int i = 0; i < v.size(); i++) {
		if (v[i] >= N) {
			ans += v[i] - N + 1;
		}
	}

	cout << ans;
}