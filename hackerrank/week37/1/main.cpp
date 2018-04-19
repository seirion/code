#include <bits/stdc++.h>

using namespace std;

// Complete the averageOfTopEmployees function below.
void averageOfTopEmployees(vector<int> rating) {
    int n(0), sum(0);
    for (auto x : rating) {
        if (90 <= x) {
            n++;
            sum += x;
        }
    }

    sum *= 10000;
    sum /= n;
    sum += 50;

    printf("%d.%02d\n", sum / 10000, (sum % 10000) / 100);
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> rating(n);

    for (int rating_itr = 0; rating_itr < n; rating_itr++) {
        int rating_item;
        cin >> rating_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        rating[rating_itr] = rating_item;
    }

    averageOfTopEmployees(rating);

    return 0;
}
