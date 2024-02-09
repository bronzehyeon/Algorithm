#include <iostream>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    set<int> s;
    
    for (int i = 0; i < N; i++) {
        int X;
        cin >> X;

        s.insert(X);
    }
    if (s.size() == 1) {
        set<int>::iterator iter = s.begin();
        cout << *iter * *iter;
    }
    else{
        set<int>::iterator first = s.begin();
        set<int>::iterator last = s.end();
        last--;
        cout << *first * *last;

    }
  
}