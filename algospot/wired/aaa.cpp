#include <iostream>
#include <vector>

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

int printSet(const vector<int> &list) {
    vector<int>::const_iterator it = list.begin();
    for(; it != list.end(); it++) {
        cout << (*it) << " ";
    }
    cout << endl;
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

bool hasExactSum(const vector<int> &divisors, int index, int current, int N, int sumOfRemains) {
    //cout << "====" << endl << "i :" << index << "\tc: " << current << "\tsum: " << sumOfRemains << endl;
    if (current == N) return true;

    // not promising
    if (current + sumOfRemains < N || (current > N)) {
        return false;
    }

    if (!hasExactSum(divisors, index+1, current + divisors[index], N, sumOfRemains - divisors[index])) {
        return hasExactSum(divisors, index+1, current, N, sumOfRemains - divisors[index]);
    }
    return true;
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
    print(exceed(divisors, input) && !hasExactSum(divisors, 0, 0, input, getSumOf(divisors)));
}

int main() {
    int num;
    cin >> num;

    for (int i = 0; i < num; i++) {
        solve();
    }

    return 0;
}
