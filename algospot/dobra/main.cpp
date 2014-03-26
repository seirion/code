// http://algospot.com/judge/problem/read/DOBRA
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

char buffer[101];
int in[101] = {0,};
bool existL = false;
size_t bufferSize;
size_t blankSize;
vector<int> blank;

enum {NONE = 0, BOWEL, CONSONANT};

void getInput() {
    gets(buffer);
    bufferSize = strlen(buffer);

    for (int i = 0; i < bufferSize; i++) {
        switch (buffer[i]) {
            case '_':
                blank.push_back(i);
                break;
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                in[i] = BOWEL;
                break;
            case 'L':
                existL = true;
            default:
                in[i] = CONSONANT;
                break;
        }
    }
    blankSize = blank.size();
}

long long solve(int index, bool needL) {
    if (index == blankSize) {
        return needL ? 0LL : 1LL;
    }

    int i = blank[index];
    int test[5];
    test[0] = i >= 2 ? in[i-2] : NONE;
    test[1] = i >= 1 ? in[i-1] : NONE;
    test[3] = i + 1 < bufferSize ? in[i+1] : NONE;
    test[4] = i + 2 < bufferSize ? in[i+2] : NONE;

    long long sum = 0;
    if ((test[0] != BOWEL || test[1] != BOWEL) && 
        (test[3] != BOWEL || test[4] != BOWEL) &&
        (test[1] != BOWEL || test[3] != BOWEL)) {
        
        in[i] = BOWEL;
        sum += 5LL * solve(index + 1, needL);
    }

    if ((test[0] != CONSONANT || test[1] != CONSONANT) && 
        (test[3] != CONSONANT || test[4] != CONSONANT) &&
        (test[1] != CONSONANT || test[3] != CONSONANT)) {

        in[i] = CONSONANT;
        if (needL) {
            sum += solve(index + 1, false);
            sum += 20LL * solve(index + 1, true);
        }
        else {
            sum += 21LL * solve(index + 1, false);
        }
    }

    in[i] = NONE;
    return sum;
}

int main() {
    getInput();
    cout << solve(0, !existL) << endl;

    return 0;
}
