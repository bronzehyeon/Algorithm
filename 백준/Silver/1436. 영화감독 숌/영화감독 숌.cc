#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    int count = 0;
    int i = 665;
    while (count < N) {
        i++;
        string str = to_string(i);
        if (str.find("666") != string::npos) count++;
    }
    cout << i;
}
