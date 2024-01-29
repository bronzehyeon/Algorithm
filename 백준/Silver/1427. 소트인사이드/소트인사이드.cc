#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    char arr[11];

    cin >> arr;

    sort(arr, arr + strlen(arr), greater<char>());

    cout << arr;
}