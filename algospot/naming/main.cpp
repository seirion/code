// http://algospot.com/judge/problem/read/NAMING
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

char in[400 * 1000 + 1];
int pre[400 * 1000 + 1];

int main() {
    gets(in);
    gets(in + strlen(in));
    int size = strlen(in);

    memset(pre, 0, sizeof(int) * (400 * 1000 + 1));

    int i(1), match(0);
    while (i + match < size) {
        if (in[i + match] == in[match]) {
            match++;
            pre[i + match - 1] = match;
        }
        else {
            if (match == 0) {
                i++;
            }
            else {
                i += match - pre[match - 1];
                match = pre[match - 1];
            }
        }
    }

    vector<int> result;
    i = size;
    while (i > 0) {
        result.push_back(i);
        i = pre[i - 1];
    }
    vector<int>::const_reverse_iterator ri = result.rbegin();
    for (; ri != result.rend(); ri++) {
        printf("%d ", *ri);
    }
    printf("\n");

    return 0;
}
