// http://algospot.com/judge/problem/read/BOOKSTORE
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Book { public:
    Book(int pr, int po) : price(pr), point(po) {}
    int price, point;
    bool operator >(const Book &n) const {
        return (point == n.point ? price > n.price : point > n.point);
    }
};

vector<Book> store[100];
int numStore = 0;

void input() {
    int i, price, point, numBook;
    for (i = 0; i < numStore; i++) { store[i].clear(); } // init

    cin >> numBook >> numStore;
    for (i = 0; i < numBook; i++) {
        for (int j = 0; j < numStore; j++) {
            cin >> price >> point;
            store[j].push_back(Book(price, point));
        }
    }
}

int get_min(vector<Book> &book) {

    for (int i = 1, s = book.size(); i < s; i++) {
        if (book[i].price < book[i-1].point) {
            book[i].point += book[i-1].point - book[i].price;
            book[i].price = book[i-1].price;
        }
        else {
            book[i].price += book[i-1].price - book[i-1].point;
        }
    }

    return book[book.size() - 1].price;
}

void solve() {
    int mini = 0X7FFFFFFF;
    for (int i = 0; i < numStore; i++) {
        sort(store[i].begin(), store[i].end(), greater<Book>());
        mini = min(mini, get_min(store[i]));
    }

    cout << mini << endl;
}

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {input(); solve();}
    return 0;
}
