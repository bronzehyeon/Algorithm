#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

void Cantor(char* str, int s, int e) {
    for (int i = s + (e - s) / 3; i < e - (e - s) / 3; i++) {
        str[i] = ' ';
    }
    if (s + 1 < s + (e - s) / 3) {
        //cout << "왼쪽 : " << s << ", " << e / 3 << endl;
        Cantor(str, s, s + (e - s) / 3);
    }
    if (e - (e - s) / 3 + 1 < e){
        //cout << "오른쪽 : " << e * 2 / 3 << ", " << e << endl;
        Cantor(str, e - (e - s) / 3, e);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;

    while (cin >> N) {
        int line = pow(3, N);

        char* str = new char[line];

        for (int i = 0; i < line; i++) {
            str[i] = '-';
        }
        str[line] = '\0';

        if(line > 1)
            Cantor(str, 0, line);

        cout << str << '\n';
    }
}