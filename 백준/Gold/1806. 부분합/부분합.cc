#include <iostream>
using namespace std;

int N, S;

int arr[100001];
int sum[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int start = 0;
	int end = 0;
	int sum = arr[0];
	int ans = N;

	while (start < N) {
		if (sum >= S) {
			if (end - start < ans) {
				ans = end - start;
			}
			sum -= arr[start];
			start++;
		}
		else {
			if (end + 1 < N) {
				end++;
				sum += arr[end];
			}
			else {
				break;
			}
		}
	}
	if (ans == N) {
		cout << 0;
	}
	else{
		cout << ans + 1;
	}
}

