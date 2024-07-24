#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M, X;
vector<pair<int,int>> graph[1001];
int dist[1001];

int bfs(int s, int d) {
	memset(dist, 0, sizeof(dist));
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
	q.push({ 0, s });

	bool visited[1001] = { false, };
	
	while (!q.empty()) {
		int cnt = q.top().first;
		int cur = q.top().second;
		q.pop();

		if (cur == d) {
			return cnt;
		}

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i].first;
			int nextCnt = graph[cur][i].second + cnt;
			if (dist[next] == 0 || dist[next] > nextCnt) {
				dist[next] = nextCnt;
				q.push({ nextCnt, next });
			}
		}

	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> X;

	while (M--) {
		int s, d, l;
		cin >> s >> d >> l;

		graph[s].push_back({ d,l });
	}

	int ans = 0;

	for (int i = 1; i <= N; i++) {
		int tmp = bfs(i, X) + bfs(X, i);
		if (tmp > ans) {
			ans = tmp;
		}
	}

	cout << ans << '\n';
}