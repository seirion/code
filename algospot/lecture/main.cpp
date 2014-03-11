#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;


void solve() {
    char buffer[1000];
    cin >> buffer;

    vector<int> in;
    size_t size = strlen(buffer)/2;
    for (int i = 0; i < size; i++) {
       in.push_back(buffer[2*i]<<8 | buffer[2*i+1]); 
    }

    sort(in.begin(), in.end());
    for (int i = 0; i < size; i++) {
        int value = in[i];
        cout << (char)((in[i] & 0xFF00) >> 8);
        cout << (char)(in[i] & 0xFF);
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
