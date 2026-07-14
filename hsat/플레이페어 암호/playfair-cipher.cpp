#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;


void make_cipher(string key, vector<vector<char>> &cipher_mat, unordered_map<char, pair<int, int>> &cipher_map) {
    cipher_mat.assign(5, vector<char>(5));
    cipher_map.clear();
    int row = 0, col = 0;
    for (char c : key) {
        if (cipher_map.find(c) != cipher_map.end()) continue;
        cipher_mat[row][col] = c;
        cipher_map[c] = {row, col};
        if (++col == 5) {
            row++;
            col = 0;
        }
    }
    for (char c = 'A'; c <= 'Z'; ++c) {
        if (cipher_map.find(c) != cipher_map.end() || c == 'J') continue;
        cipher_mat[row][col] = c;
        cipher_map[c] = {row, col};
        if (++col == 5) {
            row++;
            col = 0;
        }
    }
}

void pair_string(string str, vector<pair<char, char>> &char_pair) {
    char_pair.clear();
    for (int i = 0; i < str.length(); ++i) {
        if (i + 1 == str.length())
            char_pair.push_back({str[i], 'X'});
        else if (str[i] == str[i + 1]) {
            if (str[i] != 'X')
                char_pair.push_back({str[i], 'X'});
            else
                char_pair.push_back({str[i], 'Q'});
        }
        else {
            char_pair.push_back({str[i], str[++i]});
        }
    }
}

int main() {
    string str, key;
    cin >> str >> key;

    vector<vector<char>> cipher_mat;
    unordered_map<char, pair<int, int>> cipher_map;
    make_cipher(key, cipher_mat, cipher_map);
    
    vector<pair<char, char>> char_pair;
    pair_string(str, char_pair);

    string ans;
    for (auto [a, b] : char_pair) {
        auto [ar, ac] = cipher_map[a];
        auto [br, bc] = cipher_map[b];
        if (ar == br) {
            ans.push_back(cipher_mat[ar][(ac + 1) % 5]);
            ans.push_back(cipher_mat[br][(bc + 1) % 5]);
        }
        else if (ac == bc) {
            ans.push_back(cipher_mat[(ar + 1) % 5][ac]);
            ans.push_back(cipher_mat[(br + 1) % 5][bc]);
        }
        else {
            ans.push_back(cipher_mat[ar][bc]);
            ans.push_back(cipher_mat[br][ac]);
        }
    }
    cout << ans << endl;

    return 0;
}