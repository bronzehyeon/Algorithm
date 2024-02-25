#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int score[301] = { 0, };
    int direct[301] = { 0, };
    int skip[301] = { 0, };


    int N;
    cin >> N;


    for (int i = 1; i <= N; i++) {
        cin >> score[i];
        direct[i] = score[i];
        skip[i] = score[i];
    }

    for (int i = 2; i <= N; i++) {
        direct[i] += skip[i - 1];
        skip[i] += max(skip[i - 2], direct[i - 2]);
    }
    
    cout << max(skip[N], direct[N]);

}