#include <iostream>
#include <string>
using namespace std;

int main() {
    // Please write your code here.
    int arr[10000] = { 0 };
    int size = 0;

    int N = 0;
    cin >> N;
    
    string s = "";
    int x = 0;
    for (int i = 0; i < N; ++i) {
        cin >> s;
        if (s == "push_back") {
            cin >> x;
            arr[size++] = x;
        }
        else if (s == "pop_back") {
            size--;
        }
        else if (s == "size") {
            cout << size << endl;
        }
        else if (s == "get") {
            cin >> x;
            cout << arr[x - 1] << endl;
        }
    }


    return 0;
}