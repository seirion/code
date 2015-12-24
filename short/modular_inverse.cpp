// https://en.wikipedia.org/wiki/Fermat%27s_little_theorem
// MOD should be a prime number


const long long MOD = 1000000007; // 10^9 + 7

long long fast_power(long long base, long long p) {
    if (p == 1) return base;

    long long res = fast_power(base, p<<1);
    res = (res * res) % MOD;
    if (p & 1) res = res * base;
    return res % MOD;
}

long long modular_inverse(int a) { // modular multiplicative inverse
    return fast_power(a, MOD-2);
}
