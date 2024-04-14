#include <iostream>

using namespace std;

char king_x, king_y, p_x, p_y;

bool solve(int x, int y) {
    if (king_x + x > 'H' || king_y + y > '8' || king_x + x < 'A' || king_y + y < '1') {
        return false;
    }
    if (king_x + x == p_x && king_y + y == p_y) {
        if (p_x + x > 'H' || p_y + y > '8' || p_x + x < 'A' || p_y + y < '1') {
            return false;
        }
        else {
            p_x += x;
            p_y += y;
        }
    }
    king_x += x;
    king_y += y;

    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    cin >> king_x >> king_y >> p_x >> p_y;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        if (s == "R") {
            solve(1, 0);
        }
        else if (s == "L") {
            solve(-1, 0);
        }
        else if (s == "B") {
            solve(0, -1);
        }
        else if (s == "T") {
            solve(0, 1);
        }
        else if (s == "RT") {
            solve(1, 1);
        }
        else if (s == "LT") {
            solve(-1, 1);
        }
        else if (s == "RB") {
            solve(1, -1);
        }
        else if (s == "LB") {
            solve(-1, -1);
        }

    }

    cout << king_x << king_y << '\n';
    cout << p_x << p_y << '\n';

    
}

