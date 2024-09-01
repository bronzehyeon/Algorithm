#include <iostream>
#include <vector>
using namespace std;

int N, M;

vector<int> v[32001];

bool visited[32001];


void pr(int a) {
	//cout << a << " called" << '\n';
	for (int i = 0; i < v[a].size(); i++) {
		//cout << v[a][i] << '\n';
		int prev = v[a][i];
		if (!visited[prev]) {
			visited[prev] = true;
			pr(prev);
		}
	}
	cout << a << " ";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;

		v[B].push_back(A);
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			pr(i);
		}
	}

	
	
}