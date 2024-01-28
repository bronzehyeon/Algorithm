#include <iostream>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int card[101];
    int difference = M;
    for (int i = 0; i < N; i++) {
        cin >> card[i];
    }
    for (int i = 0; i < N; i++){
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                if (card[i] + card[j] + card[k] <= M && M - (card[i] + card[j] + card[k]) < difference) {
                    difference = M - (card[i] + card[j] + card[k]);
                }
            }
        }
    }
    cout << M - difference;   
}