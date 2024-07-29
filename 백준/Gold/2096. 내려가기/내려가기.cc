#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int maxSum[2][3];
int minSum[2][3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int a, b, c;
	cin >> a >> b >> c;
	maxSum[0][0] = a;
	maxSum[0][1] = b;
	maxSum[0][2] = c;

	minSum[0][0] = a;
	minSum[0][1] = b;
	minSum[0][2] = c;

	for (int i = 1; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		
		maxSum[i % 2][0] = max(maxSum[(i + 1) % 2][0], maxSum[(i + 1) % 2][1]) + a;
		maxSum[i % 2][1] = max(maxSum[(i + 1) % 2][0], maxSum[(i + 1) % 2][1]);
		maxSum[i % 2][1] = max(maxSum[i % 2][1], maxSum[(i + 1) % 2][2]);
		maxSum[i % 2][1] += b;
		maxSum[i % 2][2] = max(maxSum[(i + 1) % 2][1], maxSum[(i + 1) % 2][2]) + c;

		minSum[i % 2][0] = min(minSum[(i + 1) % 2][0], minSum[(i + 1) % 2][1]) + a;
		minSum[i % 2][1] = min(minSum[(i + 1) % 2][0], minSum[(i + 1) % 2][1]);
		minSum[i % 2][1] = min(minSum[i % 2][1], minSum[(i + 1) % 2][2]);
		minSum[i % 2][1] += b;
		minSum[i % 2][2] = min(minSum[(i + 1) % 2][1], minSum[(i + 1) % 2][2]) + c;
	}


	int maxAns = 0;
	int minAns = 9 * N;
	for (int i = 0; i < 3; i++) {
		if (maxSum[(N - 1) % 2][i] > maxAns) {
			maxAns = maxSum[(N - 1) % 2][i];
		}
		if (minSum[(N - 1) % 2][i] < minAns) {
			minAns = minSum[(N - 1) % 2][i];
		}
	}

	cout << maxAns << " " << minAns;
}
