#include<iostream>
#include<queue>
#include<deque>
#include<string.h>
#include<math.h>
#include<cmath>
#include<stack>
#include<algorithm>

using namespace std;

vector<int> graph[100001];
int visited[100001];
int result[100001];
int cnt = 0;

void dfs(int r) {
	if (visited[r] == 1) { // 방문 한 곳이면 return
		return;
	}

	visited[r] = 1; // 방문하지 않았다면 방문했다고 표시
	cnt++;
	result[r] = cnt;

	for (int i = 0; i < graph[r].size(); i++) {
		dfs(graph[r][i]);
	}
}
int main() {
	int N, M, R;
	cin >> N >> M >> R;
	for (int i = 1; i <= M; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v); // (1,4) (1,2) (2,3) (2,4) (3,4)
		graph[v].push_back(u); // (4,1) (2,1) (3,2) (4,2) (4,3)	
	}

	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(R);

	for (int i = 1; i <= N; i++) {
		cout << result[i] << '\n';
	}

}