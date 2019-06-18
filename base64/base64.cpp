#include <iostream>
#include <string>

using namespace std;

class base64 {
private:
    base64() {}
    static const string base64_chars;
public:
    static string encode(const string& in) {
        int i(0), remain;
        string out;
        for (const char& c: in) {
            switch (i % 3) {
            case 0:
                out.push_back(base64_chars[(c & 0xfc) >> 2]);
                remain = (c & 0x3) << 4;
                break;
            case 1:
                out.push_back(base64_chars[remain | ((c & 0xf0) >> 4)]);
                remain = (c & 0xf) << 2;
                break;
            case 2:
                out.push_back(base64_chars[remain | ((c & 0xc0) >> 6)]);
                out.push_back(base64_chars[c & 0x3f]);
                break;
            }
            i++;
        }

        if (i % 3 != 0) {
            out.push_back(base64_chars[remain]);
            while (i++ % 3 != 0) out.push_back('=');
        }
        return out;
    }

    static string decode(const string& in) {
        return "";
    }
};
const string base64::base64_chars = 
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

int main() {
    // test
    cout << base64::encode("a") << endl;
    cout << base64::encode("ab") << endl;
    cout << base64::encode("abc") << endl;
    return 0;
}
