#include <iostream>
using namespace std;

int GCD(int a, int b) {
	if (b == 0) return a;
	return GCD(b, a % b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A, B;
	cin >> A >> B;

	int gcd = GCD(A, B);

	cout << gcd << '\n';
	cout << A * B / gcd << '\n';
}