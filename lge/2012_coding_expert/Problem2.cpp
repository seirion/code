#include <iostream>
#include <fstream>

using namespace std;

//#define _TEST
//////////////////////////////////////////////////////////////////////
// constants
const char ALIVE = '*';
const char DEAD = '.';

//////////////////////////////////////////////////////////////////////
// global variables
char *_input = 0;  /**< input map */
char *_output = 0; /**< output map */

int _demension;
int *_space = 0;    /**< keep the size of each demension */
int *_accSpace = 0; /**< for calculating index */
int *_check = 0;    /**< for checking neighbors */

int _R1 = 0;        /* revival range from */
int _R2 = 0;        /* revival range to */
int _A1 = 0;        /* alive range from */
int _A2 = 0;        /* alive range to */

//////////////////////////////////////////////////////////////////////
// function prototypes
void parseInput(const char *path);
int solve();
void print();
int findIndex(int *value, int demension);
int getAliveNum(int index);
int getDeadNum(int index);
int isNeighbor(int me, int neighbor);
int findNum(int index, int status);
int getIndexOfDemensionAt(int physical, int D);


int main(int argc, char *argv[])
{
    if (argc != 2) {
        cout << "usage " << argv[0] << " \"input file\"" << endl;
        return -1;
    }

    // 0. input 
    parseInput(argv[1]);

    // 2. solve
    solve();

    // 3. print
    print();

    // 4. clear
    delete [] _input;
    delete [] _output;
    delete [] _space;
    delete [] _accSpace;
    delete [] _check;

    return 0;
}


void parseInput(const char *path)
{
    ifstream file(path);
    
    file >> _demension;

    _space = new int[_demension];
    _accSpace = new int[_demension + 1];
    _check = new int[_demension];

#ifdef _TEST
    cout << _demension << endl;
#endif


    int i;
    for (i = 0; i < _demension; i++) {
        file >> _space[i];
        if (i) _accSpace[i+1] = _accSpace[i] * _space[i];
        else {
            _accSpace[i] = 1;
            _accSpace[i+1] = _space[i];
        }
#ifdef _TEST
        cout << _space[i] << "(" << _accSpace[i] << ")" << "\t";
#endif
    }
#ifdef _TEST
    cout << endl << _accSpace[_demension] << endl;
#endif

    const int SIZE = _accSpace[_demension];
    _input = new char [SIZE];
    _output = new char [SIZE];

    file >> _R1 >> _R2 >> _A1 >> _A2;

#ifdef _TEST
    cout << _R1 << " " << _R2 << " " << _A1 << " " << _A2 << endl;
#endif

    int j;
    char in;
    for (i = 0; i < SIZE; i++) {
        file >> in;
        if (in == ALIVE || in == DEAD) {
            _input[i] = in;
        }
    }

#ifdef _TEST
    for (i = 0; i < SIZE; i++) {
        if (i % _space[0] == 0) cout << endl;
        cout << _input[i];
    }
    cout << endl;
#endif

}


/**
 */
int solve()
{
    const int SIZE = _accSpace[_demension];
    int i;
    for (i = 0; i < SIZE; i++) {
        int numAliveOfNeighbor = getAliveNum(i);
        if (_input[i] == ALIVE) {
            if (numAliveOfNeighbor >= _A1 && numAliveOfNeighbor <= _A2) _output[i] = ALIVE;
            else _output[i] = DEAD;
        }
        else { // DEAD
            if (numAliveOfNeighbor >= _R1 && numAliveOfNeighbor <= _R2) _output[i] = ALIVE;
            else _output[i] = DEAD;
        }
    }
}


/**
 * print results
 */
void print()
{
    const int SIZE = _accSpace[_demension];
    int i;
    for (i = 0; i < SIZE; i++) {
        if (i && i % _space[0] == 0) cout << endl;
        cout << _output[i];
    }
}


/**
 * return physical index of multi demension array value 
 */
int findIndex(int *value, int demension)
{
    int index = 0;
    int i, j;
    for (i = 0; i < demension; i++) {
        index += value[i] * _accSpace[i];
    }
    return index;
}


/**
 * return the number of alive neighbors of index
 */
int getAliveNum(int index)
{
    return findNum(index, ALIVE);
}

/**
 * return the number of dead neighbors of index
 */
int getDeadNum(int index)
{
    return findNum(index, DEAD);
}

/**
 * return the number of alive or dead neighbors of index
 * param index 
 * param status (alive or dead)
 */
int findNum(int index, int status)
{
    int num = 0;
    const int SIZE = _accSpace[_demension];
    int i;
    for (i = 0; i < SIZE; i++) {
        if (isNeighbor(index, i) && _input[i] == status) {
            num++;
        }
    }

    return num;
}

/**
 * return 1 if neighbor of true neighbor of me
 */
int isNeighbor(int me, int neighbor)
{
    if (me == neighbor) return 0;   // not self

    int i, myIndex, yourIndex;
    for (i = 0; i < _demension; i++) {
        myIndex = getIndexOfDemensionAt(me, i);
        yourIndex = getIndexOfDemensionAt(neighbor, i);

        if (myIndex == yourIndex || myIndex - yourIndex == 1 || yourIndex - myIndex == 1) continue;
        else return 0;
    }

    return 1;
}


/**
 * return logical index of D-demension of physical index
 */
int getIndexOfDemensionAt(int physical, int D)
{
    int i;
    for (i = _demension - 1; i > D; i--) {
        physical = physical % _accSpace[i];
    }

    return physical / _accSpace[D];
}
