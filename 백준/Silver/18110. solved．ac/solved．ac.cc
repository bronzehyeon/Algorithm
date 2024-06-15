#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	float N;
	cin >> N;

	if (N == 0) {
		cout << 0;
		return 0;
	}

	vector<int> v;

	float exclude = round(N * 15 / 100);

	//cout << exclude << '\n';

	int sum = 0;

	for (int i = 0; i < N; i++) {
		int difficulty;
		cin >> difficulty;

		v.push_back(difficulty);
		sum += difficulty;
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < exclude; i++) {
		sum -= v[i];
	}
	
	for (int i = N - exclude; i < N; i++) {
		sum -= v[i];
	}

	//cout << sum / (N - 2 * exclude) << '\n';

	float answer = round(sum / (N - 2 * exclude));
	
	cout << (int) answer;


}