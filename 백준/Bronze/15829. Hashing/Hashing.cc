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
		sum += pow(31, i) * (s[i] - 'a' + 1);
	}
	
	cout << sum % 1234567891 << '\n';
}