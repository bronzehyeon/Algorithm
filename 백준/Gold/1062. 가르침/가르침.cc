#include <iostream>
#include <string>
#include <set>

using namespace std;

int N, K;
bool alphabet[26] = { 0, };
string words[50];
set<char> need;
int learned = 0;

int maxWord = 0;

void check() {
    int count = 0;
    for (int i = 0; i < N; i++) {
        bool isOkay = true;
        for (int j = 0; j < words[i].length(); j++) {
            if (alphabet[words[i][j] - 'a'] != true) {
                isOkay = false;
                break;
            }
        }
        if (isOkay) {
            count++;
        }
    }
    if (count > maxWord) {
        maxWord = count;
    }
}

void learn(set<char>::iterator iter) {
    while (iter != need.end())
    {
        alphabet[*iter - 'a'] = true;
        learned++;
        if (learned + 5 == K) {
            check();
        }

        set<char>::iterator iter2 = iter;
        iter2++;
        learn(iter2);

        alphabet[*iter - 'a'] = false;
        learned--;

        iter++;
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;

    /*for (int i = 0; i < 26; i++) {
        alphabet[i] = false;
    }*/

    alphabet['a' - 'a'] = true;
    alphabet['n' - 'a'] = true;
    alphabet['t' - 'a'] = true;
    alphabet['i' - 'a'] = true;
    alphabet['c' - 'a'] = true;

    for (int i = 0; i < N; i++) {
        cin >> words[i];

        for (int j = 0; j < words[i].length(); j++) {
            need.insert(words[i][j]);
        }
    }

    need.erase('a');
    need.erase('n');
    need.erase('t');
    need.erase('i');
    need.erase('c');

    set<char>::iterator iter = need.begin();

    if (K < 5) {
        cout << 0;
    }
    else if (need.size()+5 <= K) {
        cout << N;
    }
    else {
        check();
        learn(iter);
        cout << maxWord;
    }


}
