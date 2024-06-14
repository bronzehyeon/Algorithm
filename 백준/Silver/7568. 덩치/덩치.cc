#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<pair<pair<int, int>, int>> v;
	map<int, int> m;

	for (int i = 0; i < N; i++) {
		int weight, height;
		cin >> weight >> height;

		v.push_back(make_pair(make_pair(weight, height), i));
	}

	sort(v.begin(), v.end());


	for (int i = 0; i < N; i++) {
		int height = v[i].first.second;
		int weight = v[i].first.first;

		m[v[i].second] = 0;

		for (int j = i + 1; j < N; j++) {
			if (weight < v[j].first.first && height < v[j].first.second) {
				m[v[i].second]++;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << m[i] + 1 << " ";
	}


}