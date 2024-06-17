#include <iostream>
using namespace std;

int comb(int n, int r)
{
	if (n == r || r == 0)
		return 1;
	else
		return comb(n - 1, r - 1) + comb(n - 1, r);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;


	for (int i = 0; i < N; i++) {
		int n3;
		cin >> n3;

		int cnt = 0;

		for (int j = 0; j * 3 <= n3; j++) {
			int n2 = n3 - 3 * j;
			for (int k = 0; k * 2 <= n2; k++) {
				int n1 = n2 - 2 * k;
				cnt += comb(j + k + n1, j) * comb(k + n1, k);
			}
		}

		cout << cnt << '\n';
	}

	


}