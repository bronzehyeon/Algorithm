#include <iostream>
#include <string>

using namespace std;

int main() {
    while (true) {
        int N;
        cin >> N;
        if (N == -1) break;
        int sum = 1;
        string perfect = to_string(N) + " = 1";
        for (int i = 2; i < N; i++) {
            if (N % i == 0) { 
                sum += i; 
                perfect += " + " + to_string(i);
            }
        }
        if (sum == N) {
            cout << perfect << '\n';
        }
        else {
            cout << to_string(N) + " is NOT perfect." << '\n';
        }
    } 
}
