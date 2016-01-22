// check each bit

int print_each_bit(int flag) {
    while (flag) {
        int index = __builtin_ctz(flag);
        //printf("%d\n", index);
        flag &= flag - 1;
    }
}

// lexicographically next bit permutation
unsigned int next(unsigned int) {
    unsigned int t = v | (v - 1); // t gets v's least significant 0 bits set to 1
    // Next set to 1 the most significant bit to change,
    // set to 0 the least significant ones, and add the necessary 1 bits.
    w = (t + 1) | (((~t & -~t) - 1) >> (__builtin_ctz(v) + 1));
    return w;
}

// lexicographically next bit permutation
unsigned int next(unsigned int) {
    unsigned int t = (v | (v - 1)) + 1;
    w = t | ((((t & -t) / (v & -v)) >> 1) - 1);
    return w;
}
