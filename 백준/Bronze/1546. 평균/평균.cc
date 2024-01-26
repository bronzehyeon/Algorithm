#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	double score[1000];
	for (int i = 0; i < N; i++) {
		cin >> score[i];
	}
	sort(score, score + N);
	double max = score[N-1];
	for (int i = 0; i < N; i++) {
		score[i] = score[i] / max * 100;
	}
	double sum = 0;
	for (int i = 0; i < N; i++) {
		sum += score[i];
	}
	cout << sum / N;

}