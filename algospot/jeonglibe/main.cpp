// http://algospot.com/judge/problem/read/
#include <cstdio>
#include <cstring>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

void tokenize(char *in, set<pair<string, string> > &ss) {
    char *title, *artist;
    int length = strlen(in);

    length -= 4; // remove .mp3
    in[length] = 0;

    title = &in[length - 1];

    while (*title != '-' && *title != '_') {
        title--;
    }
    artist = title - 1;
    title++;
    if (*title == ' ') title++;

    if (*artist == ' ') {
        *artist = 0;
    }
    else {
        artist[1] = 0;
    }
    artist--;

    while (*artist != '_' && *artist != '.' && *artist != '/' && artist != in) {
        artist--;
    }
    
    if (*artist == '_' || *artist == '/') artist++;
    else if (*artist == '.') artist += 2;

    string a(artist);
    string t(title);
    transform(a.begin(), a.end(), a.begin(), ::tolower);
    transform(t.begin(), t.end(), t.begin(), ::tolower);

    ss.insert(make_pair(a, t));
}

int main() {
    int n;
    char in[502];
    set<pair<string, string> > ss;

    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        gets(in);
        tokenize(in, ss);
    }


    printf("%d\n", ss.size());
    return 0;
}
