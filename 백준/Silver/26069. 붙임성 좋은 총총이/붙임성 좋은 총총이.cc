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

    set<string> dance;
    dance.insert("ChongChong");

    for (int i = 0; i < N; i++) {
        string A, B;
        cin >> A >> B;

        if (dance.find(A) != dance.end() && dance.find(B) == dance.end()) {
            dance.insert(B);
        }
        else if (dance.find(A) == dance.end() && dance.find(B) != dance.end()) {
            dance.insert(A);
        }
    }
    
    cout << dance.size();
  
}
