/**
 * music random shuffler (ver. 2)
 *    Suffler 는 같은 아티스트의 노래가 인접하기 않게 섞는 클래스입니다.
 *    알고리즘은 다음과 같습니다.
 *    1. artist 별로 곡을 분류하고
 *    2. 같은 artist 곡들을 랜덤 shuffle
 *    3. artist 별로 노래들을 일정한 간격으로 배열하게 값을 부여(value)
 *    4. 전체 노래를 하나의 리스트에 넣고 value 로 소팅
 *
 * algorithm reference :
 *     https://labs.spotify.com/2014/02/28/how-to-shuffle-songs
 *
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <random>
#include <chrono>       // std::chrono::system_clock

using namespace std;
const string FILE_PATH_PLAYLIST = "playlist";
const string FILE_PATH_ARTIST = "artist";

class Suffler {
public:
    explicit Suffler(int variation_ = 5) : variation(variation_) {
        srand (time(nullptr));
        variation -= 1;
        variation %= 10;
        if (variation < 0) variation += 10;
        variation += 1;
    }
    ~Suffler() {}

public:
    vector<string> random_shuffle(const vector<string> &playlist, const vector<string> &artist) {
        map<string, vector<int> > m; // <artist, list of songs>
        int size = playlist.size();
        for (int i = 0; i < size; i++) {
            m[artist[i]].push_back(i);
        }

        shuffle_artist_songs(m);
        return shuffle_with_artist(m, playlist);
    }

private:
    void shuffle_artist_songs(map<string, vector<int> > &m) {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        for (auto &artist : m) {
            auto &songs = artist.second;
            shuffle(songs.begin(), songs.end(), default_random_engine(seed));
        }
    }

    // shuffle all songs so that songs of same artist are not adjacent
    vector<string> shuffle_with_artist(map<string, vector<int> > &m, const vector<string> &playlist) {
        int song_num = playlist.size();
        vector<Song> all_songs(song_num);

        int i = 0;
        for (auto &artist : m) {
            auto &songs = artist.second;
            int start = rand() % MOD;
            int distance = MOD / songs.size();
            for (auto song : songs) {
                all_songs[i].value = (start + adjust(distance, variation)) % MOD;
                all_songs[i].song = song;
                start = (start + distance) % MOD;
                i++;
            }
        }
        sort(all_songs.begin(), all_songs.end());

        i = 0;
        vector<string> result(song_num);
        for (auto &song : all_songs) {
            result[i++] = playlist[song.song];
        }
        return result;
    }

    // return adjustment value within 'distance * rate'
    int adjust(int distance, int rate) {
        if (rate == 0) return 0;
        return rand() % (distance * rate / 100);
    }

private:
    struct Song {
        int value;
        int song; // index of songs
        bool operator <(const Song& s) const { return value < s.value; }
    };

private:
    static const int MOD = 0x0FFFFFFF; // max number of songs == 2^28

private:
    int variation; // percentage whose range is (0, 10]
};

class InputReader {
public:
    explicit InputReader(const string &path) {
        file.open(path);
    }
    ~InputReader() {
        file.close();
    }
public:
    vector<string> read() {
        vector<string> result;

        string line;
        if (getline(file, line)) {
            string data;
            stringstream stream(line);
            while (getline(stream, data, '\t')) {
                result.push_back(move(data));
            }
        }
        return result;
    }
private:
    std::ifstream file;

};

int main() {
    InputReader playlist_in(FILE_PATH_PLAYLIST);
    InputReader artist_in(FILE_PATH_ARTIST);

    while (true) {
        vector<string> playlist = playlist_in.read();
        vector<string> artist = artist_in.read();

        if (playlist.size() != artist.size()) {
            cout << "wrong input\n";
            continue;
        }
        if (playlist.empty()) break;

        Suffler s;
        auto result = s.random_shuffle(playlist, artist);
        for (auto s : result) {
            cout << s << "\t";
        }
        cout << endl;
    }
    return 0;
}
