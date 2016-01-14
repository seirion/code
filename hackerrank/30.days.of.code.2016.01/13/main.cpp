// hackerrank 30 Days of Code
// https://www.hackerrank.com/contests/30-days-of-code/challenges/day-13-abstract-classes
// Day 13: Abstract Classes!

#include <iostream>

using namespace std;

class Book{
protected:
    string title;
    string author;
public:
    Book(string t,string a){
        title=t;
        author=a;
    }
    virtual void display()=0;
};

class MyBook : public Book {
public:
    MyBook(string t, string a, int p) : Book(t, a), price(p) {}
    virtual void display() {
        cout << "Title: " << title << endl <<
                "Author: " << author << endl <<
                "Price: " << price << endl;
    }
private:
    int price;
};

int main() {
    string title,author;
    int price;
    getline(cin,title);
    getline(cin,author);
    cin>>price;
    MyBook novel(title,author,price);
    novel.display();
    return 0;
}
