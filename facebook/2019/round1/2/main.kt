import java.util.*

fun main(args: Array<String>) {
    powOf2.add(1)
    repeat(1000000) { powOf2.add(powOf2.last() * 2 % MOD) }

    val t = readLine()!!.toInt()
    repeat(t) {
        print("Case #${it + 1}: ")
        solve()
    }
}

const val MOD = 1000000007
val powOf2 = ArrayList<Int>()

fun solve() {
    val(n, k) = readLine()!!.split(" ").map { it.toInt() }
    var b = 0
    var out = 0L
    readLine()?.reversed()
            ?.mapIndexed { i, c -> Pair(n - i, c) }
            ?.forEach {
                if (it.second == 'B') {
                    if (b < k) {
                        b++
                        return@forEach
                    }
                    out = (out + powOf2[it.first]) % MOD
                }
                b = Math.max(b - 1, 0)
            }
    println(out)
}

