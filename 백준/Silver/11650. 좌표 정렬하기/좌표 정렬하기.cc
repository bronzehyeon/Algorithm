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

    multimap<int, int> mm;

    for (int i = 0; i < N; i++){
        int x, y;
        cin >> x >> y;

        mm.insert(pair<int, int>(x, y));
    }

    multimap<int, int>::iterator iter = mm.begin();

    while (iter != mm.end()) {
        int x = iter->first;
        set<int> y;
        while (iter != mm.upper_bound(x)) {
            y.insert(iter->second);
            iter++;
        }
        set<int>::iterator y_iter = y.begin();
        while (y_iter != y.end()) {
            cout << x << " " << *y_iter << '\n';
            y_iter++;
        }
    }  
}