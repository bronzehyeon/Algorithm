#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    set<string> s;
    
    int answer = 0;
    string str;
    for (int i = 0; i < N; i++) {
        cin >> str;

        if (str == "ENTER") {
            answer += s.size();
            s.clear();
        }
        else {
            s.insert(str);
        }
    }

    if(str!="ENTER")
        answer += s.size();

    cout << answer;
    
  
}