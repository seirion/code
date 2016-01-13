// hackerrank 30 Days of Code
// https://www.hackerrank.com/contests/30-days-of-code/challenges/day-12-inheritance
// Day 12: Inheritance!

#include <iostream>

using namespace std;

class Student{
public:
    Student(string fname, string lname, int p) {
        firstName = fname;
        lastName = lname;
        phone = p;
    }

    void display() {
        cout << "First Name: " << firstName <<
                "\nLast Name: "<< lastName << "\nPhone: " << phone; 
    }

protected:
    string firstName;
    string lastName;
    int phone;
};

class Grade : public Student {
public:
    Grade(string fname, string lname, int p, int s) : Student(fname, lname, p), score(s){}
    char calculate() {
        if (score < 40) return 'D';
        if (score < 60) return 'B';
        if (score < 75) return 'A';
        if (score < 90) return 'E';
        return 'O';
    }

private:
    int score;
};

int main() {
    string firstName,lastName;
    int score,phone;
    cin>>firstName;
    cin>>lastName;
    cin>>phone;
    cin>>score;    
    Student *stu=new Grade(firstName,lastName,phone,score);
    stu->display();
    Grade *g=(Grade*)stu;
    cout<< "\nGrade: "<<g->calculate();
    return 0;
}
