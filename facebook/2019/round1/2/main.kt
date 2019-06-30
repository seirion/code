fun main(args: Array<String>) {
    val t = readLine()!!.toInt()
    repeat(t) {
        print("Case #${it + 1}: ")
        solve()
    }
}

const val MOD = 1000000007

fun solve() {
    val(n, k) = readLine()!!.split(" ").map { it.toInt() }
    val str = readLine()!!.reversed()

    var a = 0
    var b = 0
    var out = 0L
    str.forEachIndexed { i, c ->
        if (c == 'A') a++
        else b++

        if (b - a > k) {
            out = (out + powOf2(n - i)) % MOD
            a++
            b--
        } else if (a > b) {
            a = b
        }
    }

    println(out)
}

fun powOf2(n: Int): Long {
    if (n == 0) return 1L
    if (n == 1) return 2L
    val half = powOf2(n / 2)
    var out = half * half % MOD
    if (n % 2 == 1) {
        out = out * 2 % MOD
    }
    return out
}
