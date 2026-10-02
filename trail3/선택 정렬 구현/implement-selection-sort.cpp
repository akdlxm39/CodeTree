#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int arr[101] = { 0 };
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; ++i) {
        int min = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        int tmp = arr[i];
        arr[i] = arr[min];
        arr[min] = tmp;
    }

    for (int i = 0; i < n; ++i) {
        cout << arr[i] << ' ';
    }
    return 0;
}