// http://algospot.com/judge/problem/read/ORDERING
#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <list>

using namespace std;

int n, depnum;
char dep[101][3];
vector<char> unchecked;
map<char, set<char> >dict;


void getInput() {

    cin >> n >> depnum;
    cin.get();

    bool check [26] = {false,};
    int i;
    for (i = 0; i < depnum; i++) {
        gets(dep[i]);
        check[dep[i][0]-'A'] = check[dep[i][1]-'A'] = true;
    }
    unchecked.clear();
    for (i = n-1; i >= 0; i--) { // reverse order
        if (check[i]) dict[i + 'A'].clear();
        else unchecked.push_back(i + 'A');
    }
    for (i = 0; i < depnum; i++) {
        dict[dep[i][0]].insert(dep[i][1]);
    }
}

void print(list<char> &solution) {
    list<char>::reverse_iterator it = solution.rbegin();
    for (; it != solution.rend(); it++) {
        printf("%c", *it);
    }
    printf("\n");
}

void remove_checked(set<char> &out, list<char> &solution) {
    set<char>::reverse_iterator rt;
    for (rt = out.rbegin(); rt != out.rend(); rt++) {
        dict.erase(*rt);
        solution.push_back(*rt);
    }

    set<char>::const_iterator it;
    for (it = out.begin(); it != out.end(); it++) {
        map<char, set<char> >::iterator m = dict.begin();
        for (; m != dict.end(); m++) {
            m->second.erase(*it);
        }
    }
}

void push_unchecked(list<char> &solution) {
    list<char>::iterator i = solution.begin();
    vector<char>::iterator j = unchecked.begin();
    while (i != solution.end() && j != unchecked.end()) {
        if (*i < *j) {
            solution.insert(i, *j);
            j++;
        }
        else {
            i++;
        }
    }

    while (i == solution.end() && j != unchecked.end()) {
        solution.push_back(*j);
        j++;
    }
}

void solve() {
    list<char> solution;

    while (!dict.empty()) {
        set<char> out;
        map<char, set<char> >::iterator i = dict.begin();
        for (; i != dict.end(); i++) {
            char key = i->first;
            set<char> &value = i->second;
            if (value.empty()) {
                out.insert(key);
            }
        }
        remove_checked(out, solution);
    }

    push_unchecked(solution);
    print(solution);
}

int main(int, char *[]) {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {getInput(); solve();}
    return 0;
}
