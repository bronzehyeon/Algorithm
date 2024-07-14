#include <iostream>
#include <queue>
using namespace std;

int ans = -1;

void bfs(int s, int d) {
	queue<pair<long, int>> q;
	q.push(make_pair(s, 1));

	while (!q.empty()) {
		long a = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (a == d) {
			ans = cnt;
		}
		long arr[2];
		arr[0] = a * 2;
		arr[1] = a * 10 + 1;

		for (int i = 0; i < 2; i++) {
			if ( arr[i] <= d) {
				q.push(make_pair(arr[i], cnt + 1));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	bfs(N, M);

	cout << ans;

	return 0;

}