#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int T;
int N, K;
int W;
int D[1001];
int dist[1001];

vector <int> v[1001];


int bfs(int s) {
	queue<pair<int, int>> q;
	q.push({ s, D[s]});

	memset(dist, 0, sizeof(dist));

	int ans = 0;

	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cnt < dist[cur]) {
			continue;
		}

		if (ans < cnt) {
			ans = cnt;
		}

		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			if (dist[next] < cnt + D[next]) {
				q.push({ next, cnt + D[next] });
				dist[next] = cnt + D[next];
			}
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	
	while (T--) {

		cin >> N >> K;

		for (int i = 1; i <= N; i++) {
			cin >> D[i];
		}


		for (int i = 0; i < K; i++) {
			int X, Y;
			cin >> X >> Y;

			v[Y].push_back(X);
		}

		cin >> W;

		cout << bfs(W) << '\n';
        
        for (int i = 1; i <= N; i++) {
        	v[i].clear();
        }
	}
}

