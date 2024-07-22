#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int dp[101][101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		dp[i][i] = 0;
	}

	while (M--) {
		int a, b, c;
		cin >> a >> b >> c;
		
		if(dp[a][b] == 0 || dp[a][b] > c)
			dp[a][b] = c;
	}

	for (int s = 1; s <= N; s++) {
		for (int d = 1; d <= N; d++) {
			if (dp[s][d] == 0) {
				continue;
			}
			int len = dp[s][d];
			for (int k = 1; k <= N; k++) {
				if (dp[k][s] == 0) {
					continue;
				}
				if (dp[k][d] == 0 && k != d) {
					dp[k][d] = dp[k][s] + len;
				}
				else {
					dp[k][d] = min(dp[k][d], dp[k][s] + len);
				}
			}
		}
	}

	for (int s = 1; s <= N; s++) {
		for (int d = 1; d <= N; d++) {
			cout << dp[s][d] << " ";
		}
		cout << '\n';
	}
}