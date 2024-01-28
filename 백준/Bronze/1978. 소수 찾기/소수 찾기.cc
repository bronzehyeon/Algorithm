#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int num;
    int count = 0;
    for (int i = 0; i < N; i++) {
        cin >> num;
        bool isPrime = true;
        if (num == 2)count++;
        for (int j = 2; j < num; j++) {
            if (num % j == 0) isPrime = false;
            if (j == num - 1 && isPrime) count++;
        }
    }
    cout << count << '\n';
}