#include <iostream>
#include <set>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    set<string, greater<string>> attendance;
    set<string>::iterator iter;
    for (int i = 0; i < N; i++) {
        string name, state;
        cin >> name >> state;
        if (state == "enter")
            attendance.insert(name);
        else if (state == "leave") {
            iter = attendance.find(name);
            attendance.erase(iter);
        }
    }

  
    for (iter = attendance.begin(); iter != attendance.end(); iter++) {
        cout << *iter << '\n';
    }

    return 0;
}