// make prime number list

const int LIMIT = 31623; //sqrt(1e9) == 31622.8

vector<int> prime;

bool is_prime(int p) {
    for (int x : prime) {
        if (p < x * x) break;
        if (p % x == 0) return false;
    }
    return true;
}

void make() {
    prime.push_back(2);
    for (int i = 3; i < LIMIT; i+=3) {
        if (is_prime(i)) prime.push_back(i);
    }
}

