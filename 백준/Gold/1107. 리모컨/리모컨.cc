#include <iostream>
#include <string>

using namespace std;

int trouble[10];

bool check(int N) {
    string s = to_string(N);
    for (int i = 0; i < s.length(); i++) {
        int num = s[i] - '0';
        if (trouble[num] == 1) {
            return false;
        }
    }
    return true;
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;



    int M;
    cin >> M;


    for (int i = 0; i < M; i++) {
        int tmp;
        cin >> tmp;
        trouble[tmp] = 1;
    }


    // 1번 방법
    int answer = abs(100 - N);

    // 2번 방법
    for (int i = 0; i <= 1000000; i++)
    {
        if (check(i))
        {
            int tmp = abs(N - i) + to_string(i).length();
            answer = min(answer, tmp);
        }
    }
    cout << answer;


    return 0;
}

