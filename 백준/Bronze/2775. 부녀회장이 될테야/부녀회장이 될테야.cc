#include <iostream>
//#include <queue>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int k, n;
		cin >> k >> n;

		int arr[15][14];

		for (int floor = 0; floor <= k; floor++) {
			arr[floor][0] = 1;
			for (int i = 1; i < n; i++) {
				if (floor == 0) {
					arr[floor][i] = i + 1;
				}
				else {
					arr[floor][i] = arr[floor - 1][i] + arr[floor][i - 1];
				}
			}
		}

		cout << arr[k][n - 1] << '\n';
	}
		


}