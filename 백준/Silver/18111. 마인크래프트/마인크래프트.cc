#include <iostream>
#include <algorithm>
using namespace std;

int arr[501][501];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, B;
	cin >> N >> M >> B;
	
	int total = 0;
	int minHeight = 256;
	int maxHeight = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];

			total += arr[i][j];
			minHeight = min(minHeight, arr[i][j]);
			maxHeight = max(maxHeight, arr[i][j]);
		}
	}

	long long ansTime = (total - (minHeight * N * M)) * 2;
	int ansHeight = minHeight;

	for (int h = minHeight; h <= maxHeight; h++) {
		if (h * M * N - total > B) {
			break;
		}
		long long time = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] > h) {
					time += (arr[i][j] - h) * 2;
				}
				else {
					time += (h - arr[i][j]);
				}
			}
		}
		if (time <= ansTime) {
			ansTime = time;
			ansHeight = h;
		}
	}
	cout << ansTime << " " << ansHeight;
}