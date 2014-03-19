#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

#define _TEST

#ifndef size_t
#define size_t int
#endif
#define MATCHING 0

//////////////////////////////////////////////////////////////////////
// function prototypes
void parseInput(const char *file);
void refine(string& str);
void solve();
void convert(string& str);

//////////////////////////////////////////////////////////////////////
// global variables
vector<std::string> _input;
vector<std::string> _output;


int main(int argc, char *argv[])
{
    if (argc != 2) {
        cout << "usage " << argv[0] << " \"input file\"" << endl;
        return -1;
    }

    parseInput(argv[1]);
    solve();

#if 1
    const size_t SIZE = _output.size();
    for (int i = 0; i < SIZE; i++) {
        cout << _output[i] << endl;
    }
#endif

    return 0;
}


/**
 * parse number data from a file
 */
void parseInput(const char *path)
{
    ifstream file(path);
    const size_t BUFFER_SIZE = 32;
    char buffer[BUFFER_SIZE];

    while(!file.eof()){
        file.getline(buffer, BUFFER_SIZE);
        string s = buffer;

        refine(s);

        if (!s.empty()) {
            _input.push_back(s);
        }
    }
}

void refine(string &str) {
    string::iterator it;

    for (it = str.begin(); it != str.end(); it++) {
        if (*it == ' ' || *it == '-') {
            str.erase(it);
        }
    }
}

/**
 * convert all input numbers into phone number format
 */
void solve()
{
    const size_t SIZE = _input.size();
    for (int i = 0; i < SIZE; i++) {
        convert(_input[i]);
    }
}


void convert(string &str)
{
    const char SEPERATOR = '-';
    /** define pasing states */
    enum {
        INIT = 0,
        HEADER,
        BODY,
        TAIL,
        FINISH,
    };
        
    int state = INIT;
    const int SIZE = str.size();
    int current = 0;


    if (SIZE <= 4) {
        _output.push_back(str);
        return;
    }

    string out;

    int i;
    for (i = 0; i < SIZE; i++) {
        if (str[i] < '0' || str[i] > '9') continue;

        switch (state) {
        case INIT:
            if (strncmp(str.c_str(), "00700", 5) == MATCHING || 
                strncmp(str.c_str(), "00300", 5) == MATCHING) {
                out += str[i++];
                out += str[i++];
                out += str[i++];
                out += str[i++];
                out += str[i];
                out += SEPERATOR;
                state = BODY;
                current = 0;
            }
            else  if (str[i] != '0') {
                if (SIZE == 7 || SIZE == 8) {
                    str.insert(SIZE - 4, 1, SEPERATOR);
                }
                _output.push_back(str);
                return;
            }
            else {
                out += str[i];
                state = HEADER;
                current++;
            }
            break;
        case HEADER:
            if (str[i] == '2') {   // seoul
                out += str[i];
                out += SEPERATOR;
                state = BODY;
                current = 0;
            }
            else {
                out += str[i++];
                out += str[i];
                out += SEPERATOR;
                state = BODY;
                current = 0;
            }
            break;
        case BODY:
            if (SIZE - i <= 7) {
                out += str[i++];
                out += str[i++];
                out += str[i];
                out += SEPERATOR;
            }
            else {
                out += str[i++];
                out += str[i++];
                out += str[i++];
                out += str[i];
                out += SEPERATOR;
            }
            state = TAIL;
            current = 0;
            break;
        case TAIL:
            out += str[i];
            break;
        default: break;
        }
    }

    if (!out.empty()) {
        _output.push_back(out);
    }
}

