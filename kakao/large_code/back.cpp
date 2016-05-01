/**
 *
 * author : Hyun Gyu Jang (seirion@mensakorea.org)
 *
 * 참고 : https://en.wikipedia.org/wiki/Hamming_distance
 */

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Code {
public:
    Code() : code(nullptr) {}
    explicit Code(const string &path): code(nullptr)  { 
        read(path);
    }
    ~Code() { delete [] code; }

    void read(const string &path) {
        std::ifstream file(path, ios::in | ios::binary);
        file.read(version, 16);
        file.read((char *)&num_code, 4);
        //num_code = ntohl(num_code);
        //printf(": %0X\n", num_code);
        code = new unsigned int [num_code];
        file.read((char *)code, sizeof(int) * num_code);
    }

    int num() const { return num_code; }
    unsigned int *get_code() const { return code; }
private:
    char version[16];
    int num_code;
    unsigned int *code;
};

class FileList {
public:
    FileList(int index_, const string &path_) : _index(index_), _path(path_) {}
    int index() const { return _index; }
    const string &path() {return _path; }
private:
    int _index;
    string _path;
};

vector<FileList> read(const string &path) {
    vector<FileList> result;

    ifstream file(path);
    string line;
    while (getline(file, line)) {
        string index_str;
        string file_path;
        stringstream stream(line);
        getline(stream, index_str, '\t');
        getline(stream, file_path);
        int index = atoi(index_str.c_str());
        //cout << index << "\t" << file_path << endl;
        result.push_back(FileList(index, file_path));
    }
    return result;
}

int m[256][256]; // hamming distance

void build_map() {
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++) {
            m[i][j] = __builtin_popcount(i^j);
        }
    }
}

int hamming_distance(char* str, char *pattern, int size) {
    int distance = 0;
    for (int i = 0; i < size; i++, str++, pattern++) {
        distance += m[*str][*pattern];
    }
    return distance;
}

void check(Code &db, Code &query, int db_id, const string &query_id) {

    int end = db.num() - query.num();
    int query_num = query.num();
    unsigned int *db_code = db.get_code();
    unsigned int *query_code = query.get_code();

    int limit = ((double)35 / 100 * 32 * query_num); // 35 %
    for (int i = 0; i <= end; i++) {
        cout << ": " << i;
        int distance = hamming_distance((char*)db_code, (char*)query_code, query_num * sizeof(int));
        cout << ":: " << endl;
        if (distance <= limit) {
            printf("%s는 document_id: %d 의 %d번째~%d번째 코드값과 유사합니다.\n",
                    query_id.c_str(), db_id, i+1, i+query_num);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        cout << "wrong argument\n";
        cout << "usage : \n";
        cout << "    " << argv[0] << " db_list test_list\n";
        return -1;
    }

    auto db_list = read(argv[1]);
    auto query_list = read(argv[2]);

    build_map();

    for (auto db : db_list) {
        Code db_code(db.path());
        for (auto query : query_list) {
            Code query_code(query.path());
            printf("x");
            check(db_code, query_code, db.index(), query.path());
        }
    }
    return 0;
}
