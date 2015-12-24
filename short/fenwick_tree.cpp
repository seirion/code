// http://blog.secmem.org/486

int tree[2000 + 1]; // binary indexed tree

void update(int x) { // +1
    while (x <= max_value+1) {
        tree[x]++;
        x += -x&x;
    }   
}

int query(int x) { // sum of [1, x]
    int s(0);
    while (x) {
        s += tree[x];
        x &= x - 1;
    }   
    return s;
}

