// https://www.hackerrank.com/contests/code-cpp-september-2015/challenges/classes-objects
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Student {
public:
    Student() { }
    ~Student() { }
    void Input() { // read the scores in 5 subjects
        score.resize(5);
        for (int i = 0; i < 5; i++) {
            cin >> score[i];
        }
    }

    int CalculateTotalScore() { // calculate and return the total score of a student
        return accumulate(score.begin(), score.end(), 0);
    }
private:
    vector<int> score;
};

int main() {
    int n; cin >> n;
    Student krish;
    krish.Input();
    int myscore(krish.CalculateTotalScore()), num(0);

    n--;
    while (n--) {
        Student other;
        other.Input();
        if (myscore < other.CalculateTotalScore()) num++;
    }
    cout << num << endl;
}
