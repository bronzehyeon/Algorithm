#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

bool visited[10001];
vector<pair<int,int>> graph[10001];
int maxNode = 1;
int maxLen = 0;
void dfs(int s, int len) {
	if (maxLen < len) {
		maxLen = len;
		maxNode = s;
	}
	for (int i = 0; i < graph[s].size(); i++) {
		int next = graph[s][i].first;
		int edge = graph[s][i].second;
		//cout << len << " - next : " << next << ", edge : " << edge << '\n';
		if (!visited[next]) {
			visited[next] = true;
			dfs(next, len + edge);
			visited[next] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	while (--N) {
		int n1, n2, e;

		cin >> n1 >> n2 >> e;

		graph[n1].push_back(make_pair(n2, e));
		graph[n2].push_back(make_pair(n1, e));
	}

	visited[1] = true;
	dfs(1, 0);
	visited[1] = false;
	
	visited[maxNode] = true;
	dfs(maxNode, 0);

	cout << maxLen << '\n';


}