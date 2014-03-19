#include <iostream>
#include <fstream>


using namespace std;


//////////////////////////////////////////////////////////////////////
// function prototypes
void parseInput(const char *path);
void solveEach(ifstream &file);


const int RIGHT = 0x0001;
const int DOWN  = 0x0002;


int main(int argc, char *argv[])
{
    if (argc != 2) {
        cout << "usage " << argv[0] << " \"input file\"" << endl;
        return -1;
    }

    parseInput(argv[1]);
    return 0;
}


/**
 * parse number data from a file
 */
void parseInput(const char *path)
{
    ifstream file(path);
    
    int num;
    file >> num;

    int i;
    for (i = 0; i < num; i++) {
        solveEach(file);
    }
}


void solveEach(ifstream &file) {
    int startW, startH, width, height;
    file >> startW >> startH >> width >> height;


    width = width - startW + 1;    // zero-based
    height = height - startH + 1;   // zero-based

    int **score = new int*[width];
    int **map = new int*[width];
    int i, x, y;
    // 0. memory alloc.
    for (i = 0; i < width; i++) {
        score[i] = new int[height];
        map[i] = new int[height];
    }


    // 1. init.
    for (x = 0; x < width; x++) {
        for (y = 0; y < height; y++) {
            score[x][y] = 0;
            map[x][y] = 0;
        }
    }


    // 2. input
    int num, sx, sy, ex, ey;
    file >> num;
    for (i = 0; i < num; i++) {
        file >> sx >> sy >> ex >> ey;

        sx -= startW;
        ex -= startW;
        sy -= startH;
        ey -= startH;

        if (sx < 0) sx = 0;
        if (sy < 0) sy = 0;
        if (ex > width) ex = width - 1;
        if (ey > height) ey = height - 1;


        for (x = sx; x <= ex; x++) {
            for (y = sy; y <= ey; y++) {
                if (x != sx) map[x][y] |= RIGHT;
                if (y != sy) map[x][y] |= DOWN;
            }
        }
    }


    // 3. solve
    score[0][0] = 1;
    for (x = 0; x < width ; x++) {
        for (y = 0; y < height; y++) {
            if (x != 0 && (map[x][y] & RIGHT)) score[x][y] += score[x-1][y];
            if (y != 0 && (map[x][y] & DOWN)) score[x][y] += score[x][y-1];
        }
    }


    // 4. print
    cout << score[width-1][height-1] << endl;
#if 0
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            cout << map[x][y] << " ";
        }
        cout << endl;
    }
    cout << endl << endl ;
#endif
#if 0
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            cout << score[x][y] << " ";
        }
        cout << endl;
    }
    cout << endl << endl << endl;
#endif

    // deallocates memory
    for (i = 0; i < width; i++) {
        delete [] score[i];
        delete [] map[i];
    }

    delete [] score;
    delete [] map;
}

