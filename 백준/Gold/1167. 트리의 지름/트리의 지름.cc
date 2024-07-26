#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int N;
vector<pair<int, int>> graph[100001];
bool visited[100001];
int length = 0;
int idx = 1;

void bfs(int s) {
	queue<pair<int, int>> q;
	q.push({ 0, s });
	visited[s] = true;

	while (!q.empty()) {
		int cnt = q.front().first;
		int cur = q.front().second;
		q.pop();
		//cout << cnt << " " << cur << '\n';

		if (length < cnt) {
			length = cnt;
			idx = cur;
		}

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i].first;
			int nextCnt = graph[cur][i].second + cnt;
			if (!visited[next]) {
				visited[next] = true;
				q.push({ nextCnt, next });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	while (N--) {
		int s;
		cin >> s;

		while (true) {
			int d;
			cin >> d;
			if (d == -1) {
				break;
			}
			int len;
			cin >> len;

			graph[s].push_back({ d, len });
		}
	}

	bfs(1);
	//cout << "bfs1" << '\n';
	memset(visited, false, sizeof(visited));
	bfs(idx);

	cout << length << '\n';
}