#include <iostream>
#include <vector>
using namespace std;

int N;
vector<pair<int, int>> v;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;

		v.push_back({ x,y });
	}

	long long sum = 0;

	for (int i = 1; i < N - 1; i++) {
		long long x1 = v[0].first, y1 = v[0].second;
		long long x2 = v[i].first, y2 = v[i].second;
		long long x3 = v[i + 1].first, y3 = v[i + 1].second;

		long long tri = x1 * y2 + x2 * y3 + x3 * y1 - (x1 * y3 + x2 * y1 + x3 * y2);
		sum += tri;
	}
	
	if (sum % 2 == 0) {
		cout << abs(sum) / 2 << ".0";
	}
	else {
		cout << abs(sum) / 2 << ".5";
	}
	
}

