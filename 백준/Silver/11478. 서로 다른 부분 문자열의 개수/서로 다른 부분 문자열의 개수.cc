#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string word;
    cin >> word;

    unordered_map<string, int> answer;

    for (int str_len = 1; str_len <= word.length(); str_len++) {
        for (int start = 0; start + str_len <= word.length(); start++) {
            string tmp = word.substr(start, str_len);
            answer.insert({ tmp, 1 });
        }
    }
    cout << answer.size();
}