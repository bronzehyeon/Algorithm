#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<char> graph[26];

void pre(char c) {
	cout << c;
	if (graph[c - 'A'][0] != '.') {
		pre(graph[c - 'A'][0]);
	}
	if (graph[c - 'A'][1] != '.') {
		pre(graph[c - 'A'][1]);
	}
}

void in(char c) {
	if (graph[c - 'A'][0] != '.') {
		in(graph[c - 'A'][0]);
	}
	cout << c;
	if (graph[c - 'A'][1] != '.') {
		in(graph[c - 'A'][1]);
	}
}

void post(char c) {
	if (graph[c - 'A'][0] != '.') {
		post(graph[c - 'A'][0]);
	}
	if (graph[c - 'A'][1] != '.') {
		post(graph[c - 'A'][1]);
	}
	cout << c;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	while (N--) {
		char a, b, c;
		cin >> a >> b >> c;

		graph[a - 'A'].push_back(b);
		graph[a - 'A'].push_back(c);
	}

	pre('A');
	cout << '\n';
	in('A');
	cout << '\n';
	post('A');
	cout << '\n';

	return 0;

}