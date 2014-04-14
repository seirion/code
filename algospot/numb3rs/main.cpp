// http://algospot.com/judge/problem/read/NUMB3RS
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <set>

using namespace std;

int n, day, prison;
int t;
int in[50][50];
vector<int> vec[50];
int q[50];
double prob[101][50]; // probablity


void getInput() {
	int i;
    cin >> n >> day >> prison;
    for (i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
			cin >> in[i][j];
			if (in[i][j]) vec[i].push_back(j);
		}
	}
    cin >> t;
    for (i = 0; i < t; i++) {
		cin >> q[i];
	}
}

void solve() {
	memset(prob, 0, sizeof(double) * 101 * 50);
	set<int> a0, a1;
	a0.insert(prison);
    prob[0][prison] = 1.0;
	int i;
	for (i = 1; i <= day; i++) {
		set<int>::const_iterator it = a0.begin();
		for (; it != a0.end(); it++) {
			size_t s = vec[*it].size();
			for (int j = 0; j < s; j++) {
				int value = vec[*it][j];
				a1.insert(value);
                prob[i][value] += prob[i-1][*it] / s;
			}
		}
		a0.swap(a1);
		a1.clear();
	}

	printf("%0.8f", prob[day][q[0]]);
    for (i = 1; i < t; i++) {
		printf(" %0.8f", prob[day][q[i]]);
	}
	printf("\n");
}

void clear() {
	for (int i = 0; i < n; i++) {
		vec[i].clear();
	}
}

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {getInput(); solve();clear();}
    return 0;
}
