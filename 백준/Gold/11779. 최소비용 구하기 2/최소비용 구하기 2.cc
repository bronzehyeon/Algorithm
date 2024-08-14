#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;
vector<pair<int, int>> graph[1001];
int dist[1001];
int path[1001];

int s, d;

int ans;

void bfs() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({ 0, s });
	dist[s] = 0;

	while (!q.empty()) {
		int cnt = q.top().first;
		int cur = q.top().second;
		q.pop();

		//cout << cur << " " << cnt << '\n';

		if (cur == d) {
			ans = cnt;
			return;
		}

		if (dist[cur] < cnt) {
			continue;
		}

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i].first;
			int nextCnt = graph[cur][i].second + cnt;

			if (dist[next] > nextCnt) {
				dist[next] = nextCnt;
				path[next] = cur;
				q.push({ nextCnt, next });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	while (M--) {
		int u, v, c;
		cin >> u >> v >> c;

		graph[u].push_back({ v,c });
	}

	for (int i = 0; i <= N; i++) {
		dist[i] = 200000000;
	}

	cin >> s >> d;

	bfs();

	vector<int> v;
	v.push_back(d);

	while (v[v.size() - 1] != s) {
		int cur = v[v.size() - 1];
		int prev = path[cur];
		v.push_back(prev);
	}

	cout << ans << '\n';
	cout << v.size() << '\n';

	for (int i = v.size() - 1; i >= 0; i--) {
		cout << v[i] << " ";
	}
}

