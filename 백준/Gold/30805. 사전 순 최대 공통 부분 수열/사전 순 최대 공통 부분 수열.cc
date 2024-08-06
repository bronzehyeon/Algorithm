#include <iostream>
#include <vector>
using namespace std;

int N, M;
int A[100];
int B[100];

vector<int> ans;

void solve(int aIdx, int bIdx) {
	if (aIdx >= N || bIdx >= M) {
		return;
	}

	for (int i = 100; i >= 1; i--) {
		for (int a = aIdx; a < N; a++) {
			if (A[a] == i) {
				for (int b = bIdx; b < M; b++) {
					if (B[b] == i) {
						ans.push_back(i);
						solve(a + 1, b + 1);
						return;
					}
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> B[i];
	}
	
	solve(0, 0);
	
	if (ans.size()) {
		cout << ans.size() << '\n';

		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << " ";
		}
	}
	else {
		cout << 0;
	}
	
	

}

