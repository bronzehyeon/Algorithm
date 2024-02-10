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
        string word;
        cin >> word;

        mm.insert(pair<int, string>(word.length(), word));
    }

    multimap<int, string>::iterator miter = mm.begin();

    for(int i = 1; i <= 50; i++) {
        set<string> same_len;
        while (miter != mm.upper_bound(i)) {
            same_len.insert(miter->second);
            miter++;
        }
        set<string>::iterator siter = same_len.begin();
        while (siter != same_len.end()) {
            cout <<  *siter << '\n';
            siter++;
        }
    }  
}