#include <iostream>
#include <vector>
using namespace std;

int N;

int prime[4000001];

vector<int> v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 2; i <= N; i++) {
		if (prime[i] == -1) {
			continue;
		}
		v.push_back(i);
		for (int j = 2; j * i <= N; j++) {
			prime[i * j] = -1;
		}
	}

	int ans = 0;
	
	for (int i = 0; i < v.size(); i++) {
		int sum = 0;
		for (int j = i; j < v.size(); j++) {
			sum += v[j];
			if (sum == N) {
				ans++;
				break;
			}
			if (sum > N) {
				break;
			}
		}
	}

	cout << ans;
}