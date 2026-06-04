#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // Please write your code here.
    int n, m, cnt = 0;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (int k = 0; k < n + m - 1; ++k)
    {
        for (int i = 0; i <= min(k, n-1); ++i)
        {   
            int j = k - i;
            if (j >= m) continue;
            v[i][j] = ++cnt;
        }
    }
    for (auto line : v)
    {
        for (auto x : line)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}