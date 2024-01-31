#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    map<string, int> pocketmon;
    vector<string> vec;

    for (int i = 0; i < N; i++) {
        string name;
        cin >> name;
        pocketmon.insert({ name, i + 1 });
        vec.push_back(name);

    }

    for (int i = 0; i < M; i++) {
        string quiz;
        cin >> quiz;
        if (quiz[0] >= 'A') {
            map<string, int>::iterator iter = pocketmon.begin();
            cout << pocketmon.find(quiz)->second << '\n';
        }
        else {
            cout << vec[stoi(quiz) - 1] << '\n';
        }
    }

    return 0;
}