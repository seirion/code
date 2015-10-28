/**
 * Vaccination Clinics
 */
#include <iostream>
#include <algorithm>

using namespace std;
const int MAX_CITY_NUM = 500 * 1000; // 1 <= N <= 500,000

int city_num, clinic_num;
int population[MAX_CITY_NUM];

void input() {
    cin >> city_num >> clinic_num;
    for (int i = 0; i < city_num; i++) {
        cin >> population[i];
    }
}

/**
 * return true if coverage 'x' is enough to cover all cities,
 * false otherwise.
 *
 * time complexity : O(n)
 *     n is the number of cities (city_num)
 */
bool enough_with_coverage_of(int x) {
    int remain = clinic_num;
    for (int i = 0; i < city_num; i++) {
        remain -= (population[i] + x - 1) / x;
        if (remain < 0) return false; // not enough
    }
    return true;
}

/**
 * this solution employs binary search,
 *     the range is between 1 to maximum popluation of all cities
 *     (because N <= B)
 *
 * time complexity : O(n log x)
 *     n is the number of cities (city_num)
 *     x is maximum population
 */
void solve() {
    int begin = 1;
    int end = *max_element(population, population + city_num);
    //cout << end << endl;

    while (begin < end) { // binary search
        int mid = (begin + end) / 2;
        if (enough_with_coverage_of(mid)) end = mid;
        else begin = mid + 1;
    }
    cout << begin << endl;
}

int main() {
    input();
    solve();
    return 0;
}
