// http://codeforces.com/contest/515/problem/C
// C. Drazil and Factorial
#include <cstdio>
#include <cstring>

using namespace std;

void print(int result[]) {
    for (int i = 9; i >= 2; i--) {
        while (result[i] > 0) {
            printf("%d", i);
            result[i]--;
        }
    }
    printf("\n");
}

int main() {

    int size;
    char buffer[20];
    scanf("%d\n", &size);
    gets(buffer);

    int result [10] = {0,};
    int length = strlen(buffer);
    for (int i = 0; i < length; i++) {
        switch (buffer[i] - '0') {
            case 2: result[2]++; break;
            case 3: result[3]++; break;
            case 4: result[3]++; result[2]+=2; break;
            case 5: result[5]++; break;
            case 6: result[5]++; result[3]++; break;
            case 7: result[7]++; break;
            case 8: result[7]++; result[2]+=3; break;
            case 9: result[7]++; result[3]+=2; result[2]++; break;
        }
    }
    print(result);
    return 0;
}
