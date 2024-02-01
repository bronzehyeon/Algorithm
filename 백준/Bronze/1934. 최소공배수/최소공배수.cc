#include <iostream>
#include <map>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    for (int i = 0; i < T; i++){
        int A, B;
        cin >> A >> B;
        if (A % B == 0) {
            cout << A << '\n';
        }
        else if (B % A == 0) {
            cout << B << '\n';
        }
        else {
            map<int, int> factor;
            for (int i = 2; i <= A && A != 1;) {                
                if (A % i == 0) {
                    int count = 0;
                    while (A % i == 0) {
                        A /= i;
                        count++;
                    }
                    factor.insert({ i, count });
                }
                else
                    i++;
            }
            for (int i = 2; i <= B && B != 1;) {                
                if (B % i == 0) {
                    int count = 0;
                    while (B % i == 0) {
                        B /= i;
                        count++;
                    }
                    if (factor.find(i) != factor.end()) {
                        if (factor.find(i)->second < count)
                            factor[i] = count;
                    }
                    else {
                        factor.insert({ i, count });
                    }  
                }
                else
                    i++;
            }
            int answer = 1;
            for (map<int, int>::iterator iter = factor.begin(); iter != factor.end(); iter++) {
                for (int i = 0; i < iter->second; i++) {
                    answer = answer * iter->first;
                }
            }
            cout << answer << '\n';
        }
    }
    return 0;
}