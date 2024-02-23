#include <iostream>
using namespace std;


int main() {
    int T;
    cin >> T;

    long long int lastNum[10] = { 0,1,1,1,1,1,1,1,1,1 };
    long long int tmp[10];
    for (int t = 1; t < T; t++) {
        tmp[0] = lastNum[1];
        for (int i = 1; i < 9; i++) {
            tmp[i] = lastNum[i - 1] + lastNum[i + 1];
        }
        tmp[9] = lastNum[8];
        for (int i = 0; i < 10; i++) {
            lastNum[i] = tmp[i] % 1000000000;
        }
    }
    long long int answer = 0;
    for (int i = 0; i < 10; i++) {
        answer += lastNum[i];
    }
    cout << answer % 1000000000;
}