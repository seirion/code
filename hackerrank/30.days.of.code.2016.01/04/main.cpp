// hackerrank 30 Days of Code
// https://www.hackerrank.com/contests/30-days-of-code/challenges/day-4-boolean-operators-class-vs-instance
// Day 4: Logical Operators + Class vs. Instance!

#include <iostream>

using namespace std;

class Person{
public:
   int age ;
   Person(int initial_Age);
   void amIOld();
   void yearPasses();
};

Person::Person(int initial_Age){
    if (initial_Age < 0) {
        cout << "This person is not valid, setting age to 0.\n";
        age = 0;
    }
    else {
        age = initial_Age;
    }
}

void Person::amIOld(){
    if (age < 13) {
        cout << "You are young.\n";
    }
    else if (age < 18) {
        cout << "You are a teenager.\n";
    }
    else {
        cout << "You are old.\n";
    }
}
    
void Person::yearPasses(){
    age++;
}

int main() {
    int T,age;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        cin>>age;
        Person p(age);
        p.amIOld();
        for(int j=0;j<3;j++)
        {
            p.yearPasses();
            
        }
        p.amIOld();
        cout<<"\n";
    }
    return 0;
}
