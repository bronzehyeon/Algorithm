#include <iostream>
#include <string>

using namespace std;

int main() {
    string N;
    cin >> N;
    bool exist = false;
    for (int i = 0; i < stoi(N); i++) {
        string tmp = to_string(i);
        int cmp = 0;
        for (int j = 0; j < tmp.length(); j++) {
            cmp += int(tmp[j] - '0');
        }
        if (cmp + stoi(tmp) == stoi(N)) {
            exist = true;
            cout << tmp;
            break;
        }
    }
    if (!exist) cout << 0;
}
