
int gcd(int a, int b) {
    return (a % b == 0) ? b : gcd(b, a % b);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

