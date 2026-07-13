#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int start, end, ans = 0;
    cin >> start >> end;
    for (int i = start; i <= end; ++i) {
        for (int j = 2; j * j <= i; ++j) {
            if (j * j == i) 
                ans++;
            else if (i % j == 0)
                break;
        }
    }
    cout << ans << endl;
    return 0;
}