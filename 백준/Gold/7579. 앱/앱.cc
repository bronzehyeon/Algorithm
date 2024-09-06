#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

int mem[101];
int cost[101];

int dp[101][10001];

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> mem[i];
    }

	int sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> cost[i];
		sum += cost[i];
    }

	dp[0][cost[0]] = mem[0];

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j <= sum; j++)
		{
			dp[i][j] = dp[i - 1][j];

			if (j - cost[i] >= 0) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + mem[i]);
			}
		}
	}

	for (int i = 0; i <= sum; i++)
	{
		if (dp[N - 1][i] >= M)
		{
			cout << i << endl;
			break;
		}
	}
}
