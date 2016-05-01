/** DNA
 *
 * brute-force
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <functional>

#define PROFILE 1

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
            for (int i = 0; i < 16; i++) {
                str.push_back(fromBit((bit&0xC0000000)>>30)); // most significant two bits
                bit <<= 2;
            }
        }
        return str;
    }

    bool operator >(const BitCode &bc) const { return _code < bc._code; }
    bool operator <(const BitCode &bc) const { return _code > bc._code; }

private:
    static const int DNA_LEN = 128;
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

    int bit0(char c) { // least significant bit
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

    int bit1(char c) { // most significant bit
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
        static char charSet[4] = { 'C', 'G', 'A', 'T' };
        return charSet[bitCode & 0x3];
    }
private:
    vector<unsigned int> _code;
};

void query(const vector<pair<int, BitCode>> &v, int Q, int K) {
    map<BitCode, int> s;
    for (auto &x: v) {
        if(x.first >= Q) {
            s[x.second]++;
        }
    }
    vector<pair<int, BitCode>> vv;
    for (auto &x : s) {
        vv.push_back(make_pair(x.second, x.first));
    }
    sort(vv.begin(), vv.end(), greater<pair<int, BitCode>>());

    int limit = min(K, (int)vv.size());
    cout << limit << endl;
    for (int i = 0; i < limit; i++) {
        cout << vv[i].first << " " << vv[i].second.toString() << endl;
    }
}

int main() {
    vector<pair<int, BitCode>> v;
    int n;
    scanf("%d\n", &n);
    char buffer[256];
    while (n--) {
        //string dnaStr;
        int adaptation;
        //cin >> dnaStr >> adaptation;
        fgets(buffer, 129, stdin);
        scanf("%d\n", &adaptation);
        //BitCode bc(dnaStr);
        //cout << buffer << " " << adaptation << endl;
        BitCode bc(buffer);
        v.push_back(make_pair(adaptation, bc));
    }

#ifdef PROFILE
    clock_t begin = clock();
#endif
    int queryNum;
    cin >> queryNum;
    while (queryNum--) {
        int Q, K;
        cin >> Q >> K;
        query(v, Q, K);
    }

#ifdef PROFILE
    clock_t end = clock();
    double timeTaken = double(end - begin) / CLOCKS_PER_SEC;
    cout << "Time taken : " << timeTaken << " second(s)" << endl;
#endif
    return 0;
}
