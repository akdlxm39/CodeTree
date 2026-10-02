#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};
Node node_pool[10000] = { 0 };
int node_cnt = 0;

class DLL {
    Node* head = nullptr;
    Node* tail = nullptr;
    int size_ = 0;
public:

    void push_front(int x) {
        Node* new_node = &node_pool[node_cnt++];
        new_node->data = x;
        new_node->prev = nullptr;
        new_node->next = head;
        if (size_ == 0) {
            head = tail = new_node;
        }
        else {
            head->prev = new_node;
            head = new_node;
        }   
        size_++;
    }
    void push_back(int x) {
        Node* new_node = &node_pool[node_cnt++];
        new_node->data = x;
        new_node->prev = tail;
        new_node->next = nullptr;
        if (size_ == 0) {
            head = tail = new_node;
        }
        else {
            tail->next = new_node;
            tail = new_node;
        }
        size_++;
    }

    int pop_front() {
        if (size_ == 0) {
            return -1;
        }
        int result = head->data;
        if (size_ == 1) {
            head = tail = nullptr;
        }
        else {
            head = head->next;
            head->prev = nullptr;
        }
        size_--;
        return result;
    }

    int pop_back() {
        if (size_ == 0) {
            return -1;
        }
        int result = tail->data;
        if (size_ == 1) {
            head = tail = nullptr;
        }
        else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        size_--;
        return result;
    }

    int size() {
        return size_;
    }

    int empty() {
        if (size_ == 0) {
            return 1;
        }
        else {
            return 0;
        }
    }

    int front() {
        if (size_ == 0) {
            return -1;
        }
        return head->data;
    }

    int back() {
        if (size_ == 0) {
            return -1;
        }
        return tail->data;
    }
};

int main() {
    // Please write your code here.
    DLL list;

    int N = 0;
    cin >> N;

    string s = "";
    int x = 0;
    for (int i = 0 ; i < N; ++i) {
        cin >> s;
        if (s == "push_front") {
            cin >> x;
            list.push_front(x);
        }
        else if (s == "push_back") {
            cin >> x;
            list.push_back(x);
        }
        else if (s == "pop_front") {
            cout << list.pop_front() << endl;
        }
        else if (s == "pop_back") {
            cout << list.pop_back() << endl;
        }
        else if (s == "size") {
            cout << list.size() << endl;
        }
        else if (s == "empty") {
            cout << list.empty() << endl;
        }
        else if (s == "front") {
            cout << list.front() << endl;
        }
        else if (s == "back") {
            cout << list.back() << endl;
        }
    }
    return 0;
}