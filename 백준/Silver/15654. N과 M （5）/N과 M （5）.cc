#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<int> v;
int arr[8];
bool visited[8];

void dfs(int cnt) {
	if (cnt + 1 == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
	}
	
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			arr[cnt + 1] = v[i];
			dfs(cnt + 1);
			visited[i] = false;
		}
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
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++) {
		arr[0] = v[i];
		visited[i] = true;
		dfs(0);
		visited[i] = false;
	}

	return 0;

}