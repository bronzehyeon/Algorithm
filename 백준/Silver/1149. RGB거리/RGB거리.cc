#include <iostream>
#include <algorithm>
using namespace std;

int red, green, blue = 0;

void solve(int r,int g, int b) {

    if (red == 0) {
        red = r;
        green = g;
        blue = b;
    }
    else {
        int minRed = min(green, blue) + r;
        int minGreen = min(red, blue) + g;
        int minBlue = min(red, green) + b;

        red = minRed;
        green = minGreen;
        blue = minBlue;
    }
    
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int R, G, B;
        cin >> R >> G >> B;

        solve(R, G, B);
    }

    cout << min({ red, green, blue });


}