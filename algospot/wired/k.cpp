
// int w[] = {...}; // input set
// int x[] = {0,};
// sumOfSubsets(0, W, sum(w));

/**
 *
 */
void sumOfSubsets(int i,int weight, int total) {
    if (!promising(i)) return;
    if (weight == W) {
        //cout << x[1..n];
    }
    else {
        x[i+1] = 1;
        sumOfSubsets(i+1, weight+w[i+1], total-w[i+1]);
        x[i+1] = 0;
        sumOfSubsets(i+1, weight, total-w[i+1]);
    }
}

bool promising(int i) {
    return (weight + total >= W) && (weight == W || weight + w[i+1] <= W);
}
