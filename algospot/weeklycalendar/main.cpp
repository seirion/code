#include <iostream>
#include <cstring>

using namespace std;


const char *DAYS[] = {
    "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
};

int getDayOfWeekFrom(const char* str) {
    for (int i = 0; i < 7; i++) {
        if (strcmp(str, DAYS[i]) == 0) return i;
    }
    return -1;
}

int daysOfMonth [] = { // zero-based
    31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

void solve() {
    int m, d;
    char dayOfWeek[32];
    cin >> m >> d >> dayOfWeek;

    int index = getDayOfWeekFrom(dayOfWeek);
    int dayOfMonthBefore = daysOfMonth[(m-1+11)%12];
    int dayOfMonthThis = daysOfMonth[(m-1)%12];

    //cout << dayOfMonthBefore << " " << dayOfMonthThis << endl;
    for (int i = 0; i < 7; i++) {
        int day = d + (i - index);
        if (day == 0) {
            day = dayOfMonthBefore;
        }
        else if (day < 0) {
            day = (day + dayOfMonthBefore) % dayOfMonthBefore;
        }
        else if (day > dayOfMonthThis) {
            day = day % dayOfMonthThis;
        }

        if (i != 0) cout << " ";
        cout << day;
    }
    cout << endl;
}

int main() {
    int num;
    cin >> num;

    for (int i = 0; i < num; i++) {
        solve();
    }

    return 0;
}
