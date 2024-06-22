#include <iostream>
#include <string>
#include <map>
using namespace std;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	map<string, string> m;

	for (int i = 0; i < N; i++) {
		string site, pw;
		cin >> site >> pw;
		m[site] = pw;
	}
	
	for (int i = 0; i < M; i++) {
		string site;
		cin >> site;
		cout << m[site] << '\n';
	}
}