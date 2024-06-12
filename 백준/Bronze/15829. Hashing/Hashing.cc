#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int L;
	cin >> L;

	string s;
	cin >> s;

	long long sum = 0;

	for (int i = 0; i < L; i++) {
		long long k = 1;
		for (int j = 0; j < i; j++) {
			k *= 31;
			k %= 1234567891;
		}
		long long p = k % 1234567891;
		sum += p * (s[i] - 'a' + 1);
		sum %= 1234567891;
	}
	
	cout << sum << '\n';
}