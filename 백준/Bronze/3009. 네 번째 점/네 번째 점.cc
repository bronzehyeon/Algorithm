#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int dotx[4], doty[4];
    cin >> dotx[0] >> doty[0];
    cin >> dotx[1] >> doty[1];
    cin >> dotx[2] >> doty[2];
    if (dotx[0] == dotx[1]) dotx[3] = dotx[2];
    else if (dotx[0] == dotx[2]) dotx[3] = dotx[1];
    else if (dotx[1] == dotx[2]) dotx[3] = dotx[0];
    if (doty[0] == doty[1]) doty[3] = doty[2];
    else if (doty[0] == doty[2]) doty[3] = doty[1];
    else if (doty[1] == doty[2]) doty[3] = doty[0];
    cout << dotx[3] << " " << doty[3];
}
