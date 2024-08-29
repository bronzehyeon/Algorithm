#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

vector<pair<int, int>> v;

int parent[500000];

int ans = 0;

int findParent (int x) {
	if (x == parent[x]) {
		return x;
	}
	
	return parent[x] = findParent(parent[x]);
}

void solve() {
	for (int i = 0; i < M; i++) {
		int a = v[i].first;
		int b = v[i].second;

		if (findParent(a) == findParent(b)) {
			ans = i + 1;
			return;
		}
		else {
			int par = min(parent[a], parent[b]);
			parent[parent[a]] = par;
			parent[parent[b]] = par;
		}
	}
}

int main() {

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		v.push_back({ a, b });
	}

	for (int i = 0; i < N; i++) {
		parent[i] = i;
	}

	solve();

	cout << ans;

}