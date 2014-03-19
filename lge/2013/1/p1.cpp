// 1. Calculate CPU Utilization and Sort it
// author : aaa

#if defined _EXTERNAL_DEBUGGER && defined _DEBUG
    #include <code/debug.h>
#else
    #define trace printf
#endif

#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

///////////////////////////////////////////////////////////////////////
// function prototypes
void solve(const char *input_file_path);
void get_input(ifstream &in);
void calculate_each_ratio(const char *name, int start, int end, int usage);
void sort_by_usage_and_name();
void print_result();

class Program {
public:
    Program(const char *name, int usage) :
        _name(name), _usage(usage) {}
    ~Program() {}
private:
    string _name;
    int _usage;
public:
    const string &getName() const {return _name;}
    int getUsage() const {return _usage;}
    bool operator>(const Program &p) {
        return true;
    }
};

/**
 * compare for sorting a list of Programs
 */
bool compare(const Program &f, const Program &l)
{
    int res = f.getUsage() - l.getUsage();

    if (res == 0) {
        int name_res = strcmp(f.getName().c_str(), l.getName().c_str());
        return name_res < 0;
    }
    else return (res > 0);
}

///////////////////////////////////////////////////////////////////////
// global variables
vector<int> _time_point;    // 구해야 하는 시각
typedef vector<Program> Info;
vector<Info> _all;



#if defined _EXTERNAL_DEBUGGER && defined _DEBUG
int test_main(int argc, char *argv[])
#else
int main(int argc, char *argv[])
#endif
{
#if defined _EXTERNAL_DEBUGGER && defined _DEBUG
    const char *INPUT = "in.txt";
#else
    const char *INPUT = argv[1];
#endif
    solve(INPUT);
    return 0;
}


void solve(const char *input_file_path)
{
    ifstream in(input_file_path);
    if (!in.is_open()) return;

    get_input(in);
    sort_by_usage_and_name();
    print_result();
}

void get_input(ifstream &in)
{
    char temp[128];
    in.getline(temp, 128);

    const char *DELIMITER = " \t\n";    // white space
    char *token = strtok(temp, DELIMITER);

    int i;
    while(token!= 0) {
        i = atoi(token);
        _time_point.push_back(i);
        token = strtok(0, DELIMITER);
    }

    _all.resize(_time_point.size());

    while (!in.eof()) {
        in.getline(temp, 128);
        char *name = strtok(temp, DELIMITER);
        if (!name) break;
        int start = atoi(strtok(0, DELIMITER));
        int end = atoi(strtok(0, DELIMITER));
        int usage = atoi(strtok(0, DELIMITER));
        //trace("%s %d %d %d\n", name, start, end, usage);
        calculate_each_ratio(name, start, end, usage);
    }
}

void calculate_each_ratio(const char *name, int start, int end, int usage)
{
    const int SIZE = _time_point.size();
    for (int i = 0; i < SIZE; i++) {
        int time = _time_point[i];
        if (time >= start && time < end) {
            Program p(name, usage*100/(end-start));
            _all[i].push_back(p);
        }
    }
}

void sort_by_usage_and_name()
{
    const int SIZE = _time_point.size();
    for (int i = 0; i < SIZE; i++) {
        sort(_all[i].begin(), _all[i].end(), compare);
    }
}

void print_result()
{
    const int SIZE = _time_point.size();
    for (int i = 0; i < SIZE; i++) {
        trace("%d\n", _time_point[i]);  // time point
        const int SIZE2 = _all[i].size();
        int sum = 0;
        for (int j = 0; j < SIZE2; j++) {
            sum += _all[i][j].getUsage();
        }
        for (int j = 0; j < SIZE2; j++) {
            int usage = (_all[i][j].getUsage() * 10000 / sum) + 5;
            if ((usage%100)/10 == 0) {
                trace("%s %d%%\n", _all[i][j].getName().c_str() ,usage/100);
            }
            else {
                trace("%s %d.%d%%\n", _all[i][j].getName().c_str() ,usage/100 ,(usage%100)/10);
            }
        }
    }
}
