#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int N;
    cin >> N;

    map<int, int> m;

    int sum = 0;
    set<int> modeset;
    int count = 0;

    for (int i = 0; i < N; i++) {
        int X;
        cin >> X;

        if (m.find(X) == m.end())
            m[X] = 1;
        else
            m[X] = m[X] + 1;
        if (m[X] > count) {
            modeset.clear();
            modeset.insert(X);
            count = m[X];
        }
        else if (m[X] == count) {
            modeset.insert(X);
        }
        sum += X;
    }

    map<int, int>::iterator iter = m.begin();
    /*
    while (iter != m.end()) {
        cout << iter->first << " : " << iter->second << '\n';
        iter++;
    }
    vector<int>::iterator vit = modeset.begin();
    while (vit != modeset.end()) {
        cout << *vit << endl;
        vit++;
    }*/
    int min = iter->first;

    int i = N / 2;
    while (i > 0) {
        i -= iter->second;
        iter++;
    }
    if (i < 0) iter--;
    int middle = iter->first;
    
    iter = m.end();
    iter--;
    int max = iter->first;
    set<int>::iterator ms = modeset.begin();
    if (modeset.size() > 1)
        ms++;

    //cout << "정답" << '\n';
    if (sum >= 0) {
        if (sum % N > N / 2)
            cout << sum / N + 1 << '\n';
        else
            cout << sum / N << '\n';
    }
    else {
        if ((- sum) % N > N / 2)
            cout << sum / N - 1 << '\n';
        else
            cout << sum / N << '\n';
    }
    cout << middle << '\n';       
    cout << *ms << '\n';
    cout << max - min << '\n';
    
}