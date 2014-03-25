// http://algospot.com/judge/problem/read/DOBRA
#include <iostream>

using namespace std;

char buffer[101];
bool in[101];
bool existL = false;
size_t bufferSize;
size_t blankSize;
vector<int> blank;

void getInput() {
    gets(buffer);
    bufferSize = strlen(buffer);

    for (int i = 0; i < blankSize; i++) {
        switch (buffer[i]) {
            case '_':
                blank.push_back(i);
                break;
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                in[i] = true;
                break;
            case 'L':
                existL = true;
            default:
                in[i] = false;
                break;
        }
    }
    blankSize = blank.bufferSize();
}

// 26 / 25 / 5
long long solve() {
    long long sum = 0;
    for (int i = 0; i < blankSize; i++) {
        if (existL) {
            canBeConsonants(i);
        }
        else {
        }
        // L
        // bowels
        // consonants (!L)
    }
}

int main() {
    getInput();

    return 0;
}
