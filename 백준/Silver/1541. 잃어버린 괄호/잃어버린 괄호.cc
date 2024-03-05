#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string exp;
    cin >> exp;

    int answer = 0;

    bool plus = true;
    int i = 0;
    while(i < exp.length()) {
        if (exp[i] == '-') {
            int minusValue = 0;
            i++;
            while (i < exp.length()) {
                int tmp = 0;
                while (exp[i] >= '0' && exp[i] <= '9') {
                    tmp = tmp * 10 + (int)(exp[i] - '0');
                    i++;
                }
                minusValue += tmp;
                if (exp[i] == '-')
                    break;
                i++;
            }
            answer -= minusValue;
        }
        else {
            int num = 0;
            while (exp[i] >= '0' && exp[i] <= '9') {
                num *= 10;
                int tmp = exp[i] - '0';
                num += tmp;
                i++;
            }
            answer += num;
            if (exp[i] == '+')
                i++;
        }
    }

    cout << answer;

}

    