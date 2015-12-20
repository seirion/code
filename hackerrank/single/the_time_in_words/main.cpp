// https://www.hackerrank.com/challenges/the-time-in-words
#include <iostream>
#include <string>

using namespace std;

const string TO_STRING[] = { "",
    "one", "two", "three", "four", "five",
    "six", "seven", "eight", "nine", "ten",
    "eleven", "twelve", "thirteen", "fourteen", "fivteen",
    "sixteen", "seventee", "eighteen", "nineteen", "twenty"
};

string min(int m) {
    if (m == 1) {
        return "one minute";
    }
    else if (m == 15) {
        return "quarter";
    }
    else if (m < 20) {
        return TO_STRING[m] + " minutes";
    }
    else if (m < 30) {
        return TO_STRING[20] + " " + TO_STRING[m-20] + " minutes";
    }
    else if (m == 30) {
        return "half";
    }
    return "";
}

int main(){
    int h, m;
    cin >> h >> m;

    if (m == 0) {
        cout << TO_STRING[h] << " o' clock\n";
    }
    else if (m <= 30) {
        cout << min(m) << " past " << TO_STRING[h] << endl;
    }
    else {
        h++;
        if (h == 13) h = 1;
        m = 60 - m;
        cout << min(m) << " to " << TO_STRING[h] << endl;
    }
    return 0;
}

