#include <iostream>
#include <queue>
using namespace std;

int N, K;
int arr[100001];
bool visited[100001];

int ans;


void solve(int a) {
	queue<pair<int, int>> q;
	visited[a] = true;
	q.push({ a, 0 });

	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cur == K) {
			ans = cnt;
			return;
		}

		if (cur * 2 <= 100000 && visited[cur * 2] == false) {
			visited[cur * 2] = true;
			q.push({ cur * 2, cnt + 1 });
		}
		if (cur + 1 <= 100000 && visited[cur + 1] == false) {
			visited[cur + 1] = true;
			q.push({ cur + 1, cnt + 1 });
		}
		if (cur - 1 >= 0 && visited[cur - 1] == false) {
			visited[cur - 1] = true;
			q.push({ cur - 1, cnt + 1 });
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	solve(N);

	cout << ans;
}