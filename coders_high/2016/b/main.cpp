// https://www.acmicpc.net/problem/12791
// Starman
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int YEAR [] = {
    1967, 1969, 1970, 1971, 1972,
    1973, 1973, 1974, 1975, 1976,
    1977, 1977, 1979, 1980, 1983,
    1984, 1987, 1993, 1995, 1997,
    1999, 2002, 2003, 2013, 2016
};

const string TITLE [] = {
    "DavidBowie", "SpaceOddity", "TheManWhoSoldTheWorld", "HunkyDory", "TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars",
    "AladdinSane", "PinUps", "DiamondDogs", "YoungAmericans", "StationToStation",
    "Low", "Heroes", "Lodger", "ScaryMonstersAndSuperCreeps", "LetsDance",
    "Tonight", "NeverLetMeDown", "BlackTieWhiteNoise", "1.Outside", "Earthling",
    "Hours", "Heathen", "Reality", "TheNextDay", "BlackStar"
};

void solve() {
    int a, b; cin >> a >> b;
    const int size = 25;
    vector<pair<int, string> >v;
    for (int i = 0; i < 25; i++) {
        if (a <= YEAR[i] && YEAR[i] <= b) {
            v.push_back(make_pair(YEAR[i], TITLE[i]));
        }
    }

    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i].first << " " << v[i].second << endl;
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
