#include <iostream>
using namespace std;

int T;

int gcd(int a, int b) {
	if (a % b == 0) {
		return b;
	}

	return gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;


	for (int t = 0; t < T; t++) {
		int M, N, x, y;
		cin >> M >> N >> x >> y;
		
		int max = M * N / gcd(M, N);
		if (x == M && y == N) {
			cout << max << '\n';
		}
		else {
			if (x == M) {
				x -= M;
			}
			if (y == N) {
				y -= N;
			}
			int i = x;
			while (true) {
				if (i > max) {
					cout << -1 << '\n';
					break;
				}
				if (i % N == y) {
					cout << i << '\n';
					break;
				}
				i += M;
			}
		}
		
	}

	
}