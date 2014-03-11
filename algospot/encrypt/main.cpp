#include <iostream>
#include <cstring>
#include <vector>

using namespace std;


void solve() {
    char buffer[100] = {0,};
    cin >> buffer;

    vector<int> in0, in1;
    size_t size = strlen(buffer);
    for (int i = 0; i < size; i++) {
        if (i % 2 == 0) in0.push_back(buffer[i]);
        else in1.push_back(buffer[i]);
    }

    size = in0.size();
    for (int i = 0; i < size; i++) {
        cout << (char)(in0[i]);
    }
    size = in1.size();
    for (int i = 0; i < size; i++) {
        cout << (char)(in1[i]);
    }

    cout << endl;
}

int main() {
    int num;
    cin >> num;

    for (int i = 0; i < num; i++) {
        solve();
    }
    return 0;
}
