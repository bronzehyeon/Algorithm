#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    multimap<int, string> mm;

    for (int i = 0; i < N; i++){
        int age;
        string name;
        cin >> age >> name;

        mm.insert(pair<int, string>(age, name));
    }

    multimap<int, string>::iterator iter = mm.begin();

    while (iter != mm.end()) {
        cout << iter->first << " " << iter->second << '\n';
        iter++;
    }
}