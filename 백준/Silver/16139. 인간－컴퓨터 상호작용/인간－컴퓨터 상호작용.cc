#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<char> str;

    char tmp;

    while (cin.get(tmp)) {
        if (tmp == '\n')
            break;
        str.push_back(tmp);
    }

    int N;
    cin >> N;

    int length = str.size();

    map<char, vector<int>> m;

    char a;
    int l, r;

    for (int i = 0; i < N; i++) {
        cin >> a >> l >> r;

        if (m.find(a) == m.end()) {
            int sum = 0;

            for (int i = 0; i < length; i++) {
                if (str[i] == a)
                    sum++;
                m[a].push_back(sum);
            }
        }

        if (l > 0)
            cout << m[a][r] - m[a][l - 1] << '\n';
        else
            cout << m[a][r] << '\n';
    }

}