/** DNA
 *
 * algorithm :
 *     1. DNA 별로 adaptation 정보를 BST 에 저장 - O(N log N)
 *     2. query 하기 쉽게 adaption 정보를 개선 - O(N)
 *     3. query : 1 에서 저장한 BST 내의 모든 DNA 를 순회 하면서, - O(N)
 *                Q 이상의 adaption 정보를 min heap 에 저장
 *                min heap 에는 최대 K 개의 DNA 정보만 유지
 *
 * time complexity : 2^23 = 8,388,608
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <functional>
#include <queue>

#define PROFILE 0

using namespace std;

class BitCode {
public:
    BitCode(const string &str);
    ~BitCode();

    string toString() const;
    bool operator >(const BitCode &bc) const { return _code < bc._code; }
    bool operator <(const BitCode &bc) const { return _code > bc._code; }

private:
    void toCode(const string &str);
    char fromBit(int bitCode) const;

private:
    vector<unsigned int> _code;
};

// data container
map<BitCode, map<int, int>> m; // map : key=adaptation, value=num_of_dna

void input() {
    int n;
    cin >> n;
    while (n--) {
        string dnaStr;
        int adaptation;
        cin >> dnaStr >> adaptation;
        BitCode bc(dnaStr);
        m[bc][adaptation]++;
    }
}

void refine() {
    for (auto &data : m) { // for each DNA
        map<int, int> &x = data.second;

        int accumulation = 0;
        for (auto rit = x.rbegin(); rit != x.rend(); rit++) { // for each adaptation
            rit->second += accumulation;
            accumulation = rit->second;
        }
    }
}

void query(int Q, int K) {
    typedef pair<int, BitCode> DNA_DATA; // first:num_of_dna, second:BitCode
    priority_queue<DNA_DATA, vector<DNA_DATA>, greater<DNA_DATA>> PQ; // keeps 'K' DNA (min heap)

    for (auto &data : m) {
        const BitCode &bc = data.first;
        map<int, int> x = data.second;

        auto it = x.lower_bound(Q); // find DNA which is geater or equal than Q
        if (it != x.end()) {
            PQ.push(make_pair(it->second, bc));
            if (PQ.size() > K) PQ.pop();
        }
    }

    vector<DNA_DATA> result;
    while (!PQ.empty()) {
        result.push_back(PQ.top());
        PQ.pop();
    }

    cout << result.size() << "\n";
    for (auto rit = result.rbegin(); rit != result.rend(); rit++) {
        cout << rit->first << " " << rit->second.toString() << "\n";
    }
}

void handleQuery() {
    int queryNum;
    cin >> queryNum;
    while (queryNum--) {
        int Q, K;
        cin >> Q >> K;
        query(Q, K);
    }
}

int main() {
    input();
    refine();
#ifdef PROFILE
    clock_t begin = clock();
#endif
    handleQuery();
#ifdef PROFILE
    clock_t end = clock();
    double timeTaken = double(end - begin) / CLOCKS_PER_SEC;
    cout << "Time taken : " << timeTaken << " second(s)" << endl;
#endif

    return 0;
}
