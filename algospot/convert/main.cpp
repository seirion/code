#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

// 1.000 kg     2.2046 pounds
double kg2lb(double kg) {
    return kg * 2.2046;
}

// 1.000 lb    0.4536 kg
double lb2kg(double lb) {
    return lb * .4536;
}

// 1.000 l      0.2642 g
double l2g(double lb) {
    return lb * .2642;
}

// 1.000 g      3.7854 l
double g2l(double lb) {
    return lb * 3.7854;
}

void print(double in) {
    int value = static_cast<int>((in + 0.00005) * 10000);
    printf("%d.%04d", value/10000, value%10000);
}

void solve() {
    double input;
    cin >> input;
    
    char buffer[4];
    cin >> buffer;

    static int num = 1;
    cout << num++ << " ";
    if (strcmp("kg", buffer) == 0) {
        print(kg2lb(input));
        cout << " lb" << endl;
    }
    else if (strcmp("lb", buffer) == 0) {
        print(lb2kg(input));
        cout << " kg" << endl;
    }
    else if (strcmp("l", buffer) == 0) {
        print(l2g(input));
        cout << " g" << endl;
    }
    else if (strcmp("g", buffer) == 0) {
        print(g2l(input));
        cout << " l" << endl;
    }

}

int main() {
    int num;
    cin >> num;

    for (int i = 0; i < num; i++) {
        solve();
    }
    return 0;
}
