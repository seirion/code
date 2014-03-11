#include <iostream>
#include <vector>

using namespace std;


void print(int in) { 
    for (int i = 1; i <= 7; i++) {
        cout << ((in & (0x1 << i)) ? 1 : 0) << " ";
    }
    cout << endl;
}


int syndrome(int in) {
    const int rule [][4] = {
        {1, 3, 5, 7},
        {2, 3, 6 ,7},
        {4, 5, 6, 7},
    };

    int out = 0;
    for (int i = 0 ; i < 3; i++) {
        const int *filter = rule[i];
        out |= (((in & (0x1 << filter[0])) ? 1 : 0) ^
                ((in & (0x1 << filter[1])) ? 1 : 0) ^
                ((in & (0x1 << filter[2])) ? 1 : 0) ^
                ((in & (0x1 << filter[3])) ? 1 : 0)) << i;
    }
    return out;
}

void result(int in) { 
    cout << ((in & (0x1 << 3)) ? 1 : 0);
    cout << ((in & (0x1 << 5)) ? 1 : 0);
    cout << ((in & (0x1 << 6)) ? 1 : 0);
    cout << ((in & (0x1 << 7)) ? 1 : 0);
    cout << endl;
}
void solve() {
    char list[32];
    cin >> list;

    int input = 0;
    for (int i = 0; i < 7; i++) {
        input |= (list[i] - '0') << i;
    }
    input = input << 1;

    int s = syndrome(input);

    int flag = 0x1 << s;
    if (input & flag) {
        input = input - flag;
    }
    else {
        input = input | flag;
    }
    
    result(input);
}

int main() {
    int num;
    cin >> num;

    for (int i = 0; i < num; i++) {
        solve();
    }
    return 0;
}
