#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> acid;
vector<int> alkali;

long sum;
int a, b;


void search(int s, int e, long plus) {
	int m = (s + e) / 2;
	long minus = alkali[m];
	

	if (abs(plus + minus) < sum) {
		sum = abs(plus + minus);
		a = plus;
		b = minus;
	}

	if (s >= e) {
		return;
	}

	if (abs(minus) > plus) {
		search(m + 1, e, plus);
	}
	else if (abs(minus) < plus) {
		search(s, m - 1, plus);
	}
	else {
		a = plus;
		b = minus;
		sum = 0;
		return;
	}

}


void solve() {
	for (int i = 0; i < acid.size(); i++) {
		long plus = acid[i];
		search(0, alkali.size() - 1, plus);
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		int liq;
		cin >> liq;
		if (liq < 0) {
			alkali.push_back(liq);
		}
		else {
			acid.push_back(liq);
		}
	}


	if (acid.size() == 0) {
		cout << alkali[alkali.size()-2] << " " << alkali[alkali.size()-1] << '\n';
	}
	else if (alkali.size() == 0) {
		cout << acid[0] << " " << acid[1] << '\n';
	}
	else {
		a = acid[0];
		b = alkali[0];
		sum = abs(a + b);
		if (alkali.size() >= 2) {
			if (sum > -alkali[alkali.size() - 2] - alkali[alkali.size() - 1]) {
				sum = -alkali[alkali.size() - 2] - alkali[alkali.size() - 1];
                b = alkali[alkali.size() - 2];
                a = alkali[alkali.size() - 1];
			}
		}
		if (acid.size() >= 2) {
			if (sum > acid[0] + acid[1]) {
				sum = acid[0] + acid[1];
                b = acid[0];
                a = acid[1];
			}
		}
		solve();
		cout << b << " " << a << '\n';
	}
	
	
}

