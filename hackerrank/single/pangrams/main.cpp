// https://www.hackerrank.com/challenges/pangrams
// Pangrams
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

char in[1024];
int main() {
    fgets(in, 1024, stdin);
    int size = strlen(in);
    set<char> s;
    for (int i = 0; i < size; i++) {
        char &c = in[i];
        if ('a' <= c && c <= 'z') s.insert(c);
        else if ('A' <= c && c <= 'Z') s.insert(c-'A'+'a');
    }
    
    if (s.size() == 26) cout << "pangram\n";
    else cout << "not pangram";
    return 0;
}

