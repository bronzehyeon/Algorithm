#include <iostream>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int size[6];

	int tshirts = 0;

	for (int i = 0; i < 6; i++) {
		cin >> size[i];
	}

	int T, P;
	cin >> T >> P;

	for (int i = 0; i < 6; i++) {
		tshirts += size[i] / T;

		if (size[i] % T != 0) {
			tshirts++;
		}
	}
	cout << tshirts << '\n';

	cout << N / P << " " << N % P<< '\n';
	
}