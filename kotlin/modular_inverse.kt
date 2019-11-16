const val MOD = 1000000007L

fun inverse(n: Long): Long {
    return pow(n, MOD - 2)
}

fun pow(n: Long, k: Long): Long = when {
    k == 0L -> 1L
    k % 2 == 0L -> pow(n, k / 2).let { it * it % MOD }
    else -> n * pow(n, k - 1) % MOD
}

