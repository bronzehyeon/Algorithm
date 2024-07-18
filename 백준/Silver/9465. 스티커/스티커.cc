#include <iostream>
#include <algorithm>
using namespace std;


int arr[2][100000];
int dp[2][100000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
			}
		}
		int ans = 0;
		for (int i = 0; i < N; i++) {
			dp[0][i] = arr[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
			dp[1][i] = arr[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
		}
		
		cout << max(dp[0][N - 1], dp[1][N - 1]) << '\n';
	}
	
	
}