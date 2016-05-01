/**
 * playlist
 *
 * rules :
 *     1. 3 번 이상 반복되는 노래가 있는 경우 첫 번째 곡이 원래 곡
 *     2. 반복 중간에 2곡 이하 다른 노래가 끼어 들 수 있는데 이 경우는 무시
 *     3. 곡명, 아티스트, 앨범 중 2 개 이상 같으면 같은 것으로
 *     4. 대소문자 구분 안 함, 공백 특수문자 무시
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Album {
public:
    Album() {}
    Album(string &&num_, string &&title_, string &&artist_, string &&name_) {
        _num = num_;
        _title = title_;
        _artist = artist_;
        _name = name_;
    }
    Album(Album &&) = default;
    ~Album() {}

    int similarity(const Album &a) const {
        int sum = 0;
        sum += similarity(_title, a.title());
        sum += similarity(_artist, a.artist());
        sum += similarity(_name, a.name());
        return sum;
    }

    const string &num() const { return _num; }
    const string &title() const { return _title; }
    const string &artist() const { return _artist; }
    const string &name() const { return _name; }

private:
    int similarity(const string &a, const string &b) const {
        enum { NOT_SAME = 0, SIMILAR, SAME };
        if (a.size() == b.size()) {
            return a == b ? SAME : NOT_SAME;
        }
        else {
            if (a.size() > b.size()) return contains(a, b) ? SIMILAR : NOT_SAME;
            else return contains(b, a) ? SIMILAR : NOT_SAME;
        }
    }
    bool contains(const string &a, const string &b) const {
        auto result = a.find(b);
        return result == string::npos ? false : true;
    }
private:
    string _num, _title, _artist, _name;
};

string normalize(const string &str) {
    string r;
    int size = str.size();
    for (int i = 0; i < size; i++) {
        const char &c = str[i];

        if (32 <= c && c < 'A') continue; // other char
        else if ('Z' < c && c < 'a') continue; // other char
        else if ('z' < c) continue; // other char
        else if ('A' <= c && c <= 'Z') r.push_back(c + 32); // to lower
        else r.push_back(c);
    }
    return r;
}

vector<Album> input(const char *path) {
    vector<Album> result;
    ifstream file(path);

    string line;
    while (getline(file, line)) {
        string num, time, title, artist, name;
        stringstream stream(line);

        getline(stream, num, '\t');
        getline(stream, time, '\t');
        getline(stream, title, '\t');
        title = normalize(title);
        getline(stream, artist, '\t');
        artist = normalize(artist);
        getline(stream, name, '\t');
        name = normalize(name);

        result.push_back(move(Album(move(num), move(title), move(artist), move(name))));
    }
    return result;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "wrong argument\n";
        cout << "usage : \n";
        cout << "    " << argv[0] << " input_file"<< endl;
        return -1;
    }

    vector<Album> list = input(argv[1]);
    int run_length = 0;
    string org_num;

    int size = list.size() - 3;
    for (int i = 0; i < size; i++) {
#if 0
        cout << list[i].num() << "    " << " :: ";
        cout << list[i].similarity(list[i+1]) << " | ";
        cout << list[i].similarity(list[i+1]) << "    " << org_num << endl;
#endif
        if (list[i].similarity(list[i+1]) >= 2) {
            if (org_num.empty()) org_num = list[i].num();
            run_length++;
        }
        else if (list[i].similarity(list[i+2]) >= 2) {
            if (org_num.empty()) org_num = list[i].num();
            run_length++;
            i++;
        }
        else if (list[i].similarity(list[i+3]) >= 2) {
            if (org_num.empty()) org_num = list[i].num();
            run_length++;
            i+=2;
        }
        else if (i+4<size && list[i].similarity(list[i+4]) >= 2) {
            if (org_num.empty()) org_num = list[i].num();
            //if (org_num.empty()) continue;
            run_length++;
            i+=3;
        }
        else {
            if (!org_num.empty() && run_length >= 3) cout << org_num << endl;
            org_num.clear();
            run_length = 0;
        }
    }

    return 0;
}
