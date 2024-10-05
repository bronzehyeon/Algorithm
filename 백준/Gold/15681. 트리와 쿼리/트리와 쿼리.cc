#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> ans;
vector<bool> visited;
int dfs(int cur, vector<vector<int>>& v){
	int cnt = 1;
	for(int i = 0; i < v[cur].size(); i++){
		int next = v[cur][i];
		if(!visited[next]){
			visited[next] = true;
			cnt += dfs(next, v);
		}
	}
	ans[cur] = cnt;
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	int N, R, Q;

	cin >> N >> R >> Q;

	ans.resize(N+1);
	visited.resize(N+1);
	vector<vector<int>> v(N + 1);

	for(int i = 0; i < N - 1; i++){
		int a, b;
		cin>>a>>b;

		v[a].push_back(b);
		v[b].push_back(a);
	}
	visited[R] = true;
	dfs(R, v);

	for(int i = 0; i < Q; i++){
		int U;
		cin>>U;
		cout<<ans[U]<<'\n';
	}
}