// DebugTemplate.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdio>
int main();
int _tmain(int argc, _TCHAR* argv[])
{
	main();
    getchar();
	return 0;
}

#include <algorithm>
#include <intrin.h>

//////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <cstdlib> // abs
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int> > note; // day, height
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        note.push_back(make_pair(a, b));
    }

    int size = note.size();
    int max_height = 0;
    for (int i = 1; i < size; i++) {
        if (note[i].first - note[i - 1].first < abs(note[i].second - note[i - 1].second)) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
        max_height = max(max_height, note[i].second);
        max_height = max(max_height, note[i - 1].second);
        max_height = max(max_height, max(note[i].second, note[i - 1].second) +
            (note[i].first - note[i - 1].first + abs(note[i].second - note[i - 1].second)) / 2);
    }
    max_height = max(max_height, note.front().second + (note.front().first - 1));
    max_height = max(max_height, note.back().second + (n - note.back().first));
    cout << max_height << endl;
    return 0;
}
