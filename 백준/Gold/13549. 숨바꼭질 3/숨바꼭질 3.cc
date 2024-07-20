#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool visited[100001];

int bfs(int s, int d) {
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
	q.push(make_pair(0, s));
	visited[s] = true;

	while (!q.empty()) {
		int cnt = q.top().first;
		int loc = q.top().second;
		q.pop();

		//cout << loc << " : " << cnt << '\n';

		if (loc == d) {
			return cnt;
		}

		if (2 * loc <= 100000 && !visited[loc * 2] && loc < d) {
			visited[loc * 2] = true;
			q.push(make_pair(cnt, loc * 2));
		}
		if (loc + 1 <= 100000 && !visited[loc + 1]) {
			visited[loc + 1] = true;
			q.push(make_pair(cnt + 1, loc + 1));
		}
		if (loc - 1 >= 0 && !visited[loc - 1]) {
			visited[loc - 1] = true;
			q.push(make_pair(cnt + 1, loc - 1));
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	cout << bfs(N, K);
};