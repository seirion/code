#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

//#define _TEST

//////////////////////////////////////////////////////////////////////
// constants
enum {SET_SIZE = 5,};       /**< the size of input */
enum {UNIT_PRICE = 8,};     /**< price of a book */
enum {DEVIDER = 100,};      /**< fixed point position in decimal */

/**< ratio of price discounted */
const int _DISCOUNTED [] = {
    0,
    100,    // no discount
    95 * 2, // 5 %
    90 * 3, // 10 %
    80 * 4, // 20 %
    75 * 5  // 25 %
};

//////////////////////////////////////////////////////////////////////
// global variables
int _set[SET_SIZE] = {0,};
int _out[SET_SIZE+1] = {0,};

//////////////////////////////////////////////////////////////////////
// function prototypes
void parseInput(const char *path);
int solve();
void print(int sum);

int main(int argc, char *argv[])
{
    if (argc != 2) {
        cout << "usage " << argv[0] << " \"input file\"" << endl;
        return -1;
    }

    // 0. input 
    parseInput(argv[1]);

    // 2. solve
    int sum = solve();

    // 3. print
    print(sum * UNIT_PRICE);
}


void parseInput(const char *path)
{
    ifstream file(path);

    char in;

    while (!file.eof()) {
        file >> in;
        if (in >= '0' && in <= '0' + SET_SIZE - 1) {
            _set[in - '0']++;
        }
        if (in == ']') break;
    }

    // selection sort
    int i, j;
    for (i = 0; i < SET_SIZE; i++) {
        int max = i;
        for (j = i+1; j < SET_SIZE; j++) { 
            if (_set[max] < _set[j]) max = j;
        }
        if (max != i) {
            int temp = _set[max];
            _set[max] = _set[i];
            _set[i] = temp;

        }
    }

#ifdef _TEST
    for (i = 0; i < SET_SIZE; i++) {
        cout << _set[i] << "\t";
    }
    cout << endl;
#endif
}


/**
 * a greedy method to solve problems;
 *   makes as larger packages as possible, and change '5 & 3' into two '4's
 */
int solve()
{
    int i, j;

    for (i = SET_SIZE - 1; i >= 0; i--) {
        _out[i+1] = _set[i];
        for (j = 0; j <= i; j++) {
            _set[j] -= _set[i];
        }
    }

#ifdef _TEST
    for (i = 0; i < SET_SIZE; i++) {
        cout << _out[i+1] << "\t";
    }
    cout << endl;
#endif

    // refine ; change '5 & 3' into two '4's
    int num = min(_out[3], _out[5]);
    if (num > 0) {
        _out[3] -= num;
        _out[5] -= num;
        _out[4] += num * 2;
    }

#ifdef _TEST
    for (i = 0; i < SET_SIZE; i++) {
        cout << _out[i+1] << "\t";
    }
    cout << endl;
#endif

    int sum = 0;
    for (i = 0; i < SET_SIZE; i++) {
        sum += _DISCOUNTED[i+1] * _out[i+1];
    }
    return sum;
}


void print(int sum)
{
    int i;
    int first = 1;
    for (i = SET_SIZE-1; i >= 0; i--) {
        if (_out[i+1] > 0) {
            if (!first) cout << "+";
            cout << _out[i+1];
            if (i+1 == 1) {
                cout << "*" << UNIT_PRICE;
            }
            else {
                cout << "*(" << UNIT_PRICE << "*" << i+1 
                    << "*" << _DISCOUNTED[i+1]/(i+1) << "/100)";
            }
            first = 0;
        }
    }
    cout << endl;

    int intPart = sum / DEVIDER;
    int fractionPart = sum % DEVIDER;
    int devider = DEVIDER / 10;

    cout << intPart;
    if (fractionPart > 0) {
        cout << ".";
        while (fractionPart < devider) {
            cout << "0";
            devider = devider / 10;
        }
        cout << fractionPart;
    }
    cout << endl;
}
