#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int N, M;
map<int,int> m;
int arr[8];
bool visited[8];

void dfs(int cnt) {
	if (cnt + 1 == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}
	
	map<int, int>::iterator iter = m.begin();
	while(iter != m.end()) {
		if (iter->second != 0) {
			m[iter->first]--;
			arr[cnt + 1] = iter->first;
			dfs(cnt + 1);
			m[iter->first]++;
		}
		iter++;
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	int t = N;

	while (t--) {
		int tmp;
		cin >> tmp;
		m[tmp]++;
	}

	map<int, int>::iterator iter = m.begin();
	while (iter != m.end()) {
		arr[0] = iter->first;
		m[iter->first]--;
		dfs(0);
		m[iter->first]++;
		iter++;
	}

	return 0;

}