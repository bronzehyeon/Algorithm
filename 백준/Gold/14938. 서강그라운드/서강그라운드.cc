#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n, m, r;
vector<pair<pair<int, int>,int>> graph;

int item[101];
int path[101][101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> r;

	for (int i = 1; i <= n; i++) {
		cin >> item[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			path[i][j] = 3001;
		}
	}

	for (int i = 1; i <= r; i++) {
		int a, b, l;
		cin >> a >> b >> l;

		path[a][b] = l;
		path[b][a] = l;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				path[i][j] = min(path[i][j], path[i][k] + path[k][j]);
			}
		}
	}


	int arr[101];

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		arr[i] = item[i];
		for (int j = 1; j <= n; j++) {
			if (path[i][j] <= m && i != j) {
				arr[i] += item[j];
			}
		}
		ans = max(ans, arr[i]);
	}
	cout << ans;

}
