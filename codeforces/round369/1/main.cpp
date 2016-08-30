#include <iostream>
#include <string>

using namespace std;

int n;
string in[1000];

using namespace std;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> in[i];

    for (int i = 0; i < n; i++) {
        if (in[i][0] == 'O' && in[i][1] == 'O') {
            in[i][0] = in[i][1] = '+';
            goto OUT_YES;
        }

        if (in[i][3] == 'O' && in[i][4] == 'O') {
            in[i][3] = in[i][4] = '+';
            goto OUT_YES;
        }
    }

OUT_NO:
    cout << "NO" << endl;
    return 0;

OUT_YES:
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) cout << in[i] << endl;
    return 0;
}
