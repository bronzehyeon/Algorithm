#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;
bool visited[101] = { 0, };
vector<int> v[101];

int ans = 0;

void solve() {
	queue<int> q;
	q.push(1);
	visited[1] = true;	

	while (!q.empty()) {
		int cur = q.front();
		ans++;
		q.pop();

		for (int i = 0; i < v[cur].size(); i++) {
			if (visited[v[cur][i]] == false) {
				visited[v[cur][i]] = true;
				q.push(v[cur][i]);
			}
		}
	}

}	

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}

	solve();

	cout << ans - 1;


}