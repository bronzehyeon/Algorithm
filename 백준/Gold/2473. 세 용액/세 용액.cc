#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
long long arr[6000];

long long ans[3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);

	long long best = abs(arr[0] + arr[1] + arr[2]);
	//cout << "best : " << best << '\n';

	for (int i = 0; i < N; i++) {
		int p1 = 0;
		int p2 = N - 1;

		while (p1 < p2) {
			if (p1 == i) {
				p1++;
				continue;
			}
			if (p2 == i) {
				p2--;
				continue;
			}
			long long cur = arr[i] + arr[p1] + arr[p2];
			//cout << "cur : " << cur << '\n';
			//cout << arr[i] << ", " << arr[p1] << ", " << arr[p2] << '\n';

			if (abs(cur) <= best) {
				best = abs(cur);
				ans[0] = arr[p1];
				ans[1] = arr[p2];
				ans[2] = arr[i];
			}

			if (cur == 0) {
				break;
			}
			else if (cur > 0) {
				p2--;
			}
			else {
				p1++;
			}
		}
	}

	sort(ans, ans + 3);

	cout << ans[0] << " " << ans[1] << " " << ans[2];

}

