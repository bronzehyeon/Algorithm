#include <iostream>
#include <vector>
using namespace std;

int dp[100001][5][5];

int cost[5][5];

vector<int> v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//memset(cost, 400000, sizeof(cost));

	cost[1][3] = 4;
	cost[3][1] = 4;
	cost[2][4] = 4;
	cost[4][2] = 4;

	cost[1][2] = 3;
	cost[1][4] = 3;
	cost[2][1] = 3;
	cost[2][3] = 3;
	cost[3][2] = 3;
	cost[3][4] = 3;
	cost[4][1] = 3;
	cost[4][3] = 3;

	for (int i = 1; i <= 4; i++) {
		cost[0][i] = 2;
		cost[i][i] = 1;
	}

	while (true) {
		int n;
		cin >> n;

		if (n == 0) {
			break;
		}

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				dp[v.size()][i][j] = 410000;
			}
		}

		v.push_back(n);
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			dp[v.size()][i][j] = 410000;
		}
	}

	//memset(dp, -1, sizeof(dp));

	dp[0][0][0] = 0;

	int k = 1;
	while (k <= v.size()) {
		int n = v[k - 1];
		//cout << n << "======================\n";

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (dp[k - 1][i][j] == 410000) {
					continue;
				}
				//cout << dp[k - 1][i][j] << '\n';
				//cout << dp[k][i][n] << '\n';
				//cout << dp[k][n][j] << '\n';
				dp[k][i][n] = min(dp[k][i][n], dp[k - 1][i][j] + cost[j][n]);
				dp[k][n][j] = min(dp[k][n][j], dp[k - 1][i][j] + cost[i][n]);
				//cout << n << "(" << i << ", " << j << ") : " << dp[k][i][n] << ", " << dp[k][n][j] << '\n';
			}
		}

		k++;
	}

	int ans = 400000;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (dp[k - 1][i][j] == 410000) {
				continue;
			}
			ans = min(ans, dp[k - 1][i][j]);
		}
	}

	cout << ans;
	
}