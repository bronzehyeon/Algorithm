#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int N, M;
		cin >> N >> M;

		queue<pair<int, int>> q;

		vector<int> v(N);
		for (int i = 0; i < N; i++) {
			int num;
			cin >> num;

			v[i] = num;
			q.push(make_pair(num, i));
		}

		sort(v.begin(), v.end());

		int count = 0;

		for (int i = 0; i < N; i++) {
			while (q.front().first != v[N - 1 - i]) {
				int tmp = q.front().first;
				int idx = q.front().second;
				q.pop();
				q.push(make_pair(tmp, idx));
			}
			count++;

			if (q.front().second == M) {
				cout << count << '\n';
				break;
			}

			q.pop();
		}

		
	}

}