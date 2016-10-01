#include <iostream>
#include <cstdio>

using namespace std;

int format, h, m;

int main() {
    scanf("%d\n", &format);
    scanf("%02d:%02d", &h, &m);

    if (format == 24) {
        if (24 <= h) {
            h = h % 10;
        }
    }
    else {
        if (0 == h) {
            h = 1;
        }
        else if (12 < h) {
            h = h % 10;
            if (h == 0) h = 10;
        }
    }

    if (60 <= m) {
        m = m % 10;
    }

    printf("%02d:%02d\n", h, m);
    return 0;
}
