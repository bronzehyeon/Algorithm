#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int V, E;
int parent[100001];

vector < pair<int, pair<int, int>>> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E;

	for (int i = 0; i < E; i++) {
		int A, B, C;
		cin >> A >> B >> C;

		v.push_back({ C, {A,B} });
	}
	
	sort(v.begin(), v.end());
	
	int select = 0;
	int i = 0;
	int sum = 0;

	while (select < V - 1) {
		int cost = v[i].first;
		int v1 = v[i].second.first;
		int v2 = v[i].second.second;

		if (parent[v1] == 0 && parent[v2] == 0) {
			parent[v1] = v1;
			parent[v2] = v1;
			sum += cost;
			select++;
		}
		else if (parent[v1] == 0) {
			parent[v1] = parent[v2];
			sum += cost;
			select++;
		}
		else if (parent[v2] == 0) {
			parent[v2] = parent[v1];
			sum += cost;
			select++;
		}
		else {
			if (parent[v1] != parent[v2]) {
				int pv2 = parent[v2];
				for (int i = 1; i <= V; i++) {
					if (parent[i] == pv2) {
						parent[i] = parent[v1];
					}
				}
				sum += cost;
				select++;
			}
		}
		i++;
	}

	cout<<sum;
}

