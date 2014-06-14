#include <iostream>
#include <vector>
#include <set>

using namespace std;


vector<int> getDivisors(int input) {
    vector<int> divisors;
    divisors.push_back(1); // default
    for (int i = 2; i <= input/2; i++) {
        if (input % i == 0) {
            divisors.push_back(i);
        }
    }
    return divisors;
}

int getSumOf(const vector<int> &list) {
    int sum = 0;
    vector<int>::const_iterator it = list.begin();
    for(; it != list.end(); it++) {
        sum += (*it);
    }
    return sum;
}

bool exceed(const vector<int> &divisors, int input) {
    int sum = getSumOf(divisors);
    return (sum > input);
}

bool exist(vector<int> &set, int sum, int input, int index) {
    if (sum < input || input < 0) return false;
    if (sum == input) return true;

    int last = set[index];
    if (exist(set, sum - last, input - last, index-1)) {
        return true;
    }
    return (exist(set, sum - last, input, index-1));
}

bool hasExactSum(vector<int> &divisors, int input) {
    return exist(divisors, getSumOf(divisors), input, divisors.size()-1);
}

void print(bool weird) {
    if (!weird) {
        cout << "not ";
    }
    cout << "weird" << endl;
}

void solve() {
    int input;
    cin >> input;

    vector<int> divisors = getDivisors(input);
    print(exceed(divisors, input) && !hasExactSum(divisors, input));
}

int main() {
    int num;
    cin >> num;

    for (int i = 0; i < num; i++) {
        solve();
    }

    return 0;
}
