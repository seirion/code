#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the maximumProgramValue function below.
 */
long long maximumProgramValue(int n) {
    long long r = 0; // current max
    while (n--) {
        string s; long long in;
        cin >> s >> in;
        
        if (s.front() == 'a') { // add
            if (0 < in) r += in;
        } else { // set
            if (r < in)  r = in;
        }
    }
    return r;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long long result = maximumProgramValue(n);

    fout << result << "\n";

    fout.close();

    return 0;
}
