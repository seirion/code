#include <iostream>
#include <string>

using namespace std;

int main() {
    int n; cin >> n;
    int consecutive = 0;
    int unlock(0), all(0);
    while (n--) {
        int x; cin >> x;
        if (x == 1) {
            all ++;
            consecutive++;
            if (consecutive % 2 == 1) unlock++;
        } else {
            consecutive = 0;
        }

    }
    cout << unlock << " " << all << endl;
    return 0;
}
