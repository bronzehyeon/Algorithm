#include <iostream>
#include <vector>
#include <map>
using namespace std;

long long T;

int N, M;

long long A[1001];
long long B[1001];

map<long long, long long> m;

long long ans = 0;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		A[i] += A[i - 1];
		for (int j = 0; j < i; j++) {
			long long tmp = A[i] - A[j];
			//cout << "A[i] : " << A[i] << ", A[j] : " << A[j] << '\n';
			//cout << j << "~" << i << " : " << tmp << '\n';
			m[tmp]++;
		}
	}

	/*auto iter = m.begin();
	while (iter != m.end()) {
		cout << iter->first << " : " << iter->second << '\n';
		iter++;
	}*/

	cin >> M;

	for (int i = 1; i <= M; i++) {
		cin >> B[i];
		B[i] += B[i - 1];
		for (int j = 0; j < i; j++) {
			long long tmp = B[i] - B[j];
			long long f = T - tmp;

			ans += m[f];
		}
	}

	cout << ans;
	
}