#include <iostream>
#include <vector>
using namespace std;

int v[1001][1001];

long long comb(int n, int r)
{
	//cout << "n : " << n << ", r : " << r << '\n';
	if (n == r || r == 0)
		return 1;
	else if (v[n][r] != 0) {
		return v[n][r];
	}
	else {
		v[n][r] = (comb(n - 1, r - 1) + comb(n - 1, r) % 10007);
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
		cnt += comb(i + l, l);
		cnt %= 10007;
	}

	cout << cnt << '\n';
	
}