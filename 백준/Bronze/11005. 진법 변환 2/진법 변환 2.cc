#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    long N, B;
    cin >> N >> B;
    string answer;
    long digit = 1;

    while (N / (digit * B) != 0) {
        digit *= B;
    }

    while (digit >= 1) {
        int tmp = N / digit;
        N %= digit;
        digit /= B;

        if (tmp >= 10) {
            char add = 'A' + (tmp - 10);
            answer += add;
        }
        else {
            char add = '0' + tmp;
            answer += add;
        }
    }

    cout << answer;
    return 0;
}
