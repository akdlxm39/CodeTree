#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
    // Please write your code here.
    int n, m;
    string s;
    cin >> n >> m >> s;
    list<char> l;
    for (char c : s) {
        l.push_back(c);
    }
    list<char>::iterator iter = l.end();
    for (int i = 0 ; i < m; ++i) {
        cin >> s;
        if (s == "L") {
            if (iter != l.begin())
                iter--;
        }
        else if (s == "R") {
            if (iter != l.end())
                iter++;
        }
        else if (s == "D") {
            if (iter != l.end())
                iter = l.erase(iter);
        }
        else if (s == "P") {
            char c;
            cin >> c;
            l.insert(iter, c);
        }
    }

    for (char c : l) {
        cout << c;
    }

    return 0;
}