// https://www.hackerrank.com/contests/code-cpp-september-2015/challenges/abstract-classes-polymorphism
#include <iostream>
#include <string>
#include <map>

using namespace std;

struct Node {
    Node* next;
    Node* prev;
    int value;
    int key;
    Node(Node* p, Node* n, int k, int val): prev(p), next(n), key(k), value(val) {};
    Node(int k, int val): prev(NULL), next(NULL), key(k), value(val) {};
};

class Cache {
protected:
    map<int, Node*> mp; //map the key to the node in the linked list
    int cp;  //capacity
    Node* tail; // double linked list tail pointer
    Node* head; // double linked list head pointer
    virtual void set(int, int) = 0; //set function
    virtual int get(int) = 0; //get function
};

class LRUCache : public Cache {
public:
    LRUCache(int capacity)  { cp = capacity; head = tail = 0; }
    ~LRUCache()  { clear(); }
    virtual void set(int key, int value) {
        auto it = mp.find(key);
        if (it != mp.end()) { // found
            Node *node = it->second;
            erase(node);
            mp.erase(it);
        }
        else if (!mp.empty()) { // not fount
            if (mp.size() == cp) mp.erase(--mp.end()); // remove the last one
        }
        Node *node = new Node(key, value);
        mp[key] = node;

        if (head) head->prev = node;
        node->next = head;
        head = node;
        if (!tail) tail = node;
    }
    virtual int get(int key) {
        auto it = mp.find(key);
        if (it == mp.end()) return -1;

        int value = it->second->value;
        set(key, value);
        return value;
    }
private:
    void erase(Node *node) {
        if (node == head) head = node->next;
        if (node == tail) tail = node->prev;
        if (node->prev) node->prev->next = node->next;
        if (node->next) node->next->prev = node->prev;
        delete node;
    }
    void insert_front(Node *node) {
        if (head == 0) {
            head = tail = node;
        }
        else {
            node->prev = 0;
            node->next = head;
            head = node;
        }
    }
    void clear() {
        Node *now = head;
        while (now) {
            Node *next = now->next;
            delete now;
            now = next;
        }
    }
};

int main() {
    int n, capacity, i;
    cin >> n >> capacity;
    LRUCache l(capacity);
    for (i = 0; i < n; i++) {
        string command;
        cin >> command;
        if (command == "get") {
            int key;
            cin >> key;
            cout << l.get(key) << endl;
        } 
        else if (command == "set") {
            int key, value;
            cin >> key >> value;
            l.set(key, value);
        }
    }
    return 0;
}

#if 0
int n, capacity;

void input() {
    cin >> n >> capacity;
    LRUCache cache(capacity);
    while (n--) {
        string str; cin >> str;
        if (str[0] == 's') { // set
            int k, v; cin >> k >> v;
            cache.set(k, v);
        }
        else { // get
            int k; cin >> k;
            cout << cache.get(k) << endl;
        }
    }
}

int main() {
    input();
    return 0;
}
#endif
