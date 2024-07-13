#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int N, M;
set<int> s;
int arr[8];

void dfs(int cnt, set<int>::iterator it) {
	if (cnt + 1 == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}
	
	auto iter = it;
	while(iter != s.end()) {
		arr[cnt + 1] = *iter;
		dfs(cnt + 1, iter);
		iter++;
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;


	while (N--) {
		int tmp;
		cin >> tmp;
		s.insert(tmp);
	}

	auto iter = s.begin();

	while (iter != s.end()) {
		arr[0] = *iter;
		dfs(0, iter);
		iter++;
	}

	return 0;

}