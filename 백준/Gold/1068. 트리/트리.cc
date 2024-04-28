#include <iostream>
#include <map>
#include <set>

using namespace std;

int N;
map<int, int> m;
set<int> s;

void rm(int parent) {
    for (int i = 0; i < N; i++) {
        if (m[i] == parent) {
            m[i] = -1;
            s.erase(i);
            rm(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    int leaf;
    
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        m.insert({ i,tmp });
        s.insert(i);
        if (tmp == -1) {
            leaf = i;
        }
    }

    m[leaf] = N;

    int del;
    cin >> del;

    m[del] = -1;
    s.erase(del);

    rm(del);

    int answer = 0;


    for (int i = 0; i < N; i++) {
        s.erase(m[i]);
    }

    cout << s.size();

}

