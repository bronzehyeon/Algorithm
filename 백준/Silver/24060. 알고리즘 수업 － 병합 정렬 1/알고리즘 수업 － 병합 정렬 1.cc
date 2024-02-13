#include <iostream>
using namespace std;

int store = 0;
int K = 0;

void merge(int* arr, int p, int q, int r) {
    int i = p, j = q + 1, t = 0;
    int *tmp = new int[r - p + 1];
    while (i <= q && j <= r) {
        if (arr[i] <= arr[j]) {
            tmp[t++] = arr[i++];
        }
        else {
            tmp[t++] = arr[j++];
        }
    }
    while (i <= q)
        tmp[t++] = arr[i++];
    while (j <= r)
        tmp[t++] = arr[j++];
    i = p;
    t = 0;
    while (i <= r) {
        arr[i++] = tmp[t++];
        store++;
        if (store == K)
            cout << arr[i - 1];
    }
}

void merge_sort(int* arr, int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        merge_sort(arr, p, q);
        merge_sort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T >> K;

    int *array = new int[T];

    for (int i = 0; i < T; i++){
        cin >> array[i];
    }
    merge_sort(array, 0, T - 1);
    /*for (int i = 0; i < T; i++) {
        cout << array[i] << " ";
    }*/
    if (store < K) {
        cout << -1;
    }
    
}