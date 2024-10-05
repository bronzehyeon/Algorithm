#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<long long int> rest;

    for (int i = 0; i < M; i++) {
        rest.push_back(0);
    }

    int sum = 0;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        sum = (sum + num) % M;

        rest[sum]++;
    }

    long long int answer = rest[0];


    for (int i = 0; i < M; i++) {
        answer += rest[i] * (rest[i] - 1) / 2;//nC2
    }


    cout << answer;

}