#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin >> n;
    for (int i = 0 ; i < n; ++i)
    {
        int a, b, sum = 0;
        cin >> a >> b;
        for (int x = a; x <= b; ++x)
        {
            if (x % 2 == 0)
                sum += x;
        }
        cout << sum << endl;
    }
    return 0;
}