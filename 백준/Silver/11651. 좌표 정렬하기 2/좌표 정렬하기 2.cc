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

        mm.insert(pair<int, int>(y, x));
    }

    multimap<int, int>::iterator iter = mm.begin();

    while (iter != mm.end()) {
        int y = iter->first;
        set<int> x;
        while (iter != mm.upper_bound(y)) {
            x.insert(iter->second);
            iter++;
        }
        set<int>::iterator x_iter = x.begin();
        while (x_iter != x.end()) {
            cout << *x_iter << " " << y << '\n';
            x_iter++;
        }
    }  
}