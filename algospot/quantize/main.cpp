// http://algospot.com/judge/problem/read/QUANTIZE
#include <iostream>
#include <algorithm>

using namespace std;

int n; // input num
int s;
int in[100];
int vIndex[100]; // temp
int vList[10]; // vList of s

void getInput() {
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }
    sort(in, in + n);
}

int closest(int in) {
    int minIndex = 0;
    int minValue = abs(vList[minIndex] - in);
    for (int i = 1; i < s; i++) {
        if (abs(vList[i] - in) < minValue) {
            minValue = abs(vList[i] - in);
            minIndex = i;
        }
    }
    return minIndex;
}

void avg() {
    int i, j;
    for (i = 0; i < s; i++) {
        int sum = 0, count = 0;
        int mean = vList[i];
        for (j = 0; j < n; j++) {
            if (vIndex[j] == i) {
                sum += in[j];
                count++;
            }
        }
        if (count == 0) {
            vList[i] = 0;
        }
        else {
            vList[i] = (int)((double)sum / count + 0.5);
        }
    }
}

void solve() {
    int i;
    // 1. init
    vList[0] = in[0];
    for (i = 1; i < s; i++) {
        vList[i] = in[(n-1)/(s-i)];
    }
    for (i = 0; i < n; i++) {
        vIndex[i] = closest(in[i]);
    }

    // 2. loop
    bool changed = true;
    int error;
    while (changed) {
        avg();
        changed = false;
        for (i = 0; i < n; i++) {
            //int org = closest(vIndex[i]);
            int org = vIndex[i];
            vIndex[i] = closest(in[i]);
            if (org != vIndex[i]) {
                changed = true;
            }
        }
    }

    // 3. error sum
    int sum = 0;
    for (i = 0; i < n; i++) {
        int error = in[i] - vList[vIndex[i]];
        sum += error * error;
    }
    cout << sum << endl;

}

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {getInput(); solve();}
    return 0;
}
