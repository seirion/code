// https://www.facebook.com/hackercup/problems.php?pid=582062045257424&round=742632349177460
// Facebook Hacker Cup 2015 Qualification Round
// #1. Cooking the Books
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;
int in, small, large;

void swap(char *buffer, int i, int j) {
    char temp = buffer[i];
    buffer[i] = buffer[j];
    buffer[j] = temp;
}

void find() {
    char buffer[20];
    sprintf(buffer, "%d", in);
    int size = strlen(buffer);
    for (int i = 0; i < size; i++) {
        for (int j = i+1; j < size; j++) {
            swap(buffer, i, j);
            if (buffer[0] != '0') {
                int temp = atoi(buffer);
                small = min(small, temp);
                large = max(large, temp);
            }
            swap(buffer, i, j);
        }
    }
}

int main() {
    int c;
    scanf("%d", &c);
    for (int i = 0; i < c; i++) {
        scanf("%d", &in);
        small = large = in;
        find();
        printf("Case #%d: %d %d\n", i+1, small, large);
    }
}

