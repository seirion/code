// http://algospot.com/judge/problem/read/PACKING
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Stuff { public:
    Stuff() {}
    ~Stuff() {}
    string name;
    int volume, value;
};

int n, W;
Stuff in[101];
int memo[1001][101];

void getInput() {
    cin >> n >> W;
    for (int i = 0; i < n; i++) {
        cin >> in[i].name >> in[i].volume >> in[i].value;
    }
    memset(memo, 0xFF, sizeof(int) * 1001 * 101);
}

int pack(int w, int index) {
    if (index == n) return 0;
    int &maxi = memo[w][index];
    if (maxi != -1) return maxi;

    maxi = pack(w, index+1); // not contain
    if (w >= in[index].volume) { // contain
        maxi = max(maxi, pack(w-in[index].volume, index+1) + in[index].value);
    }
    return maxi;
}

void find_path(int w, int index, vector<int> &out) {
    if (index == n) return;

    if (pack(w, index) == pack(w, index+1)) {
        find_path(w, index+1, out);
    }
    else {
        out.push_back(index);
        find_path(w - in[index].volume, index+1, out);
    }
}

void solve() {
    int v = pack(W, 0);
    cout << v << " ";

    vector<int> out;
    find_path(W, 0, out);
    cout << out.size() << endl;
    vector<int>::const_iterator i = out.begin();
    for (; i != out.end(); i++) {
        cout << in[*i].name << endl;
    }
}

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {getInput(); solve();}
    return 0;
}
