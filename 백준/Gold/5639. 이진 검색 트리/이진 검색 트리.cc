#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> v;

void solve(int s, int e) {
	if (s >= e) 
		return;

	if (s == e - 1) {
		cout << v[s] << '\n';
		return;
	}

	int idx = s + 1;

	while (idx < e) {
		if (v[s] < v[idx]) break;
		idx++;
	}

	solve(s + 1, idx);
	solve(idx, e);

	cout << v[s] << '\n';
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	int n;
	while (cin >> n) {
		v.push_back(n);
	}

	solve(0, v.size());


}

