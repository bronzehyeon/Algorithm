#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	
	vector<pair<int,int>> v;

	int index = 0;

	int start;
	cin >> start;
	
	int prev = start;
	v.push_back(make_pair(start,1));

	for (int i = 1; i < N; i++) {
		int tmp;
		cin >> tmp;
		

		if (tmp == prev) {
			v[index].second++;
		}
		else {
			v.push_back(make_pair(tmp,1));
			prev = tmp;
			index++;
		}
	}

	int ans = v[0].second;

	set<int> s;

	for (int i = 1; i < v.size(); i++) {
		if (s.find(i) != s.end()) {
			continue;
		}
		int cnt = v[i - 1].second + v[i].second;
		int j = i - 1;
		while (j + 2 < v.size()) {
			if (v[j].first != v[j + 2].first) {
				break;
			}
			s.insert(j + 2);
			cnt += v[j + 2].second;
			j++;
		}
		ans = max(ans, cnt);
	}
	
	cout << ans;
}