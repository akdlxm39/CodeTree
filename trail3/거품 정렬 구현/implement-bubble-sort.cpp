#include <iostream>
using namespace std;


int main() {
    // Please write your code here.
    int arr[101] = { 0 };
    int n = 0;
    cin >> n;
    for (int i = 0 ; i < n; ++i) {
        cin >> arr[i];
    }
    
    bool sorted = true;
    do {
        sorted = true;
        for (int i = 0 ; i < n - 1; ++i) {
            if (arr[i] > arr[i + 1]) {
                int tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                sorted = false;
            }
        }
    } while(sorted == false);

    for (int i = 0 ; i < n; ++i) {
        cout << arr[i] << ' ';
    }

    return 0;
}