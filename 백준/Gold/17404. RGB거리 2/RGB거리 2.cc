#include <iostream>
using namespace std;

int N;
int cost[1000][3];

int dp[1000][3];

int R = 0;
int G = 1;
int B = 2;

int ans = 110000;

void solve(int first, int x, int y) {
	dp[2][first] = cost[2][first] + cost[0][first] + min(cost[1][x], cost[1][y]);
	dp[2][x] = cost[2][x] + cost[0][first] + cost[1][y];
	dp[2][y] = cost[2][y] + cost[0][first] + cost[1][x];

	for (int i = 3; i < N; i++) {
		dp[i][0] = cost[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = cost[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] = cost[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
	}

	for (int i = 0; i < 3; i++) {
		if (i == first) {
			continue;
		}
		else {
			ans = min(ans, dp[N - 1][i]);
		}
	}
}

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		int r, g, b;
		cin >> r >> g >> b;

		cost[i][R] = r;
		cost[i][G] = g;
		cost[i][B] = b;
	}

	solve(R, G, B);
	solve(G, R, B);
	solve(B, R, G);

	cout << ans;

}