#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long long v[1001][1001];

long long comb(int n, int r)
{
	//cout << "n : " << n << ", r : " << r << '\n';
	if (n == r || r == 0)
		return 1;
	else if (v[n][r] != 0) {
		return v[n][r];
	}
	else {
		v[n][r] = (comb(n - 1, r - 1) + comb(n - 1, r)) % 10007;
		return v[n][r];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int N;
	cin >> N;

	long long cnt = 0;
	int t = N / 2;

	for (int i = 0; i <= t; i++) {
		int l = N - 2 * i;
		long long tmp = comb(i + l, l);
		tmp %= 10007;
		for (int j = 0; j < i; j++) {
        	tmp *= 2;
	        tmp %= 10007;
        }
		cnt += tmp;
		cnt %= 10007;
	}

	cout << cnt << '\n';

}