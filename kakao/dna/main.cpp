/**
 * Kakao DNA
 *
 * algorithm :
 *     1. DNA 별로 adaptation 정보를 BST 에 저장 - O(N log N)
 *     2. query 하기 쉽게 adaption 정보를 개선 - O(N)
 *     3. query : 1 에서 저장한 BST 내의 모든 DNA 를 순회 하면서, - O(N)
 *                Q 이상의 adaption 정보를 min heap 에 저장
 *                min heap 에는 최대 K 개의 DNA 정보만 유지
 *
 */
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <functional>
#include <queue>

//#define PROFILE true

using namespace std;

class BitCode {
public:
    BitCode(const string &str) {
        toCode(str);
    }
    ~BitCode() {}

    string toString() const {
        string str;
        for (unsigned int bit : _code) {
            for (int i = 0; i < 16; i++, bit <<= 2) {
                str.push_back(fromBit((bit&0xC0000000)>>30)); // most significant two bits
            }
        }
        return str;
    }

    bool operator >(const BitCode &bc) const { return _code < bc._code; }
    bool operator <(const BitCode &bc) const { return _code > bc._code; }

public:
    static const int DNA_LEN = 128;
private:
    static const int BITS_PER_INT = 32;
    static const int CODE_SIZE = DNA_LEN * 2 / BITS_PER_INT;

    void toCode(const string &str) {
        // assert(str.size() == 128);
        _code.clear();
        _code.resize(CODE_SIZE, 0);
        for (int i = 0; i < str.size(); i++) {
            set(i, str[i]);
        }
    }

    void set(int index, char c) {
        index <<= 1;
        unsigned int &code = _code[index / BITS_PER_INT];
        index %= BITS_PER_INT;
        code |= bit1(c) << (BITS_PER_INT - index - 1);
        code |= bit0(c) << (BITS_PER_INT - index - 2);
    }

    int bit0(char c) const { // least significant bit
        switch (c) {
            case 'C' /* 00 */: // go through
            case 'A' /* 10 */:
                return 0;
            case 'G' /* 01 */: // go through
            case 'T' /* 11 */:
                return 1;
        }
        return 0; // something wrong
    }

    int bit1(char c) const { // most significant bit
        switch (c) {
            case 'C' /* 00 */: // go through
            case 'G' /* 01 */:
                return 0;
            case 'A' /* 10 */: // go through
            case 'T' /* 11 */:
                return 1;
        }
        return 0; // something wrong
    }

    char fromBit(int bitCode) const {
        static const char charSet[4] = { 'C', 'G', 'A', 'T' };
        return charSet[bitCode & 0x3];
    }
private:
    vector<unsigned int> _code;
};

// data container
map<BitCode, map<int, int>> m; // map : key=adaptation, value=num_of_dna

#ifdef PROFILE
clock_t timeTaken = 0;
#endif

void input() {
    int n;
    scanf("%d\n", &n);
    char buffer[256];
    while (n--) {
        int adaptation;
        fgets(buffer, BitCode::DNA_LEN+1, stdin);
        scanf("%d\n", &adaptation);
#ifdef PROFILE
        clock_t begin = clock();
#endif
        BitCode bc(buffer);
        m[bc][adaptation]++;
#ifdef PROFILE
        clock_t end = clock();
        timeTaken += (end - begin);
#endif
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
        map<int, int> &x = data.second;

        auto it = x.lower_bound(Q); // binary search
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

    printf("%d\n", result.size());
    for (auto rit = result.rbegin(); rit != result.rend(); rit++) {
        printf("%d %s\n", rit->first, rit->second.toString().c_str());
    }
}

void handleQuery() {
    int queryNum;
    scanf("%d", &queryNum);
    while (queryNum--) {
        int Q, K;
        scanf("%d %d",&Q, &K);
        query(Q, K);
    }
}

int main() {
    input();
#ifdef PROFILE
    clock_t begin = clock();
#endif
    refine();
    handleQuery();
#ifdef PROFILE
    clock_t end = clock();
    timeTaken += end - begin;
    printf("Time taken : %d second(s)\n", (double)timeTaken / CLOCKS_PER_SEC);
#endif
    //printf("%d\n", m.size()); // test

    return 0;
}
