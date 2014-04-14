// http://algospot.com/judge/problem/read/NUMB3RS
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

int n, day, prison;
int t;
int in[50][50];
vector<int> vec[50];
int q[50];
int count[50]; // probablity


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
	memset(count, 0, sizeof(int) * 50);
	vector<int> a0, a1;
	a0.push_back(prison);
	int i;
	for (i = 0; i < day - 1; i++) {
		vector<int>::const_iterator it = a0.begin();
		//a1.push_back(*it);
		for (; it != a0.end(); it++) {
			size_t s = vec[*it].size();
			for (int j = 0; j < s; j++) {
				int value = vec[*it][j];
				//count[value]++;
				a1.push_back(value);
			}
		}
		a0.swap(a1);
		a1.clear();
	}

	vector<int>::const_iterator it = a0.begin();
	//count[*it]++;
	for (; it != a0.end(); it++) {
		size_t s = vec[*it].size();
		for (int j = 0; j < s; j++) {
			int value = vec[*it][j];
			count[value]++;
			//a1.push_back(value);
		}
	}

	int sum = 0;
    for (i = 0; i < n; i++) {
		cout << count[i] << " ";
		sum += count[i];
	}
	cout << "    " << sum << endl;


	printf("%0.8f", (double)count[q[0]] / sum);
    for (i = 1; i < t; i++) {
		printf(" %0.8f", (double)count[q[i]] / sum);
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
