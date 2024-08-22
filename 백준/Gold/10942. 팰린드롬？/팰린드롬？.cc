#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int S, E;
int ans[2001][2001];

int arr[2001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		ans[i][i] = 1;
	}

	for (int i = 1; i < N; i++) {
		if (arr[i] == arr[i + 1]) {
			ans[i][i + 1] = true;
		}
	}

	for (int len = 2; len < N; len++) {
		for (int i = 1; i <= N - len; i++) {
			if (arr[i] == arr[i + len] && ans[i + 1][i + len - 1]) {
				ans[i][i + len] = 1;
			}
		}
	}

	cin >> M;

	while (M--) {
		cin >> S >> E;

		cout << ans[S][E] << '\n';
	}
}

