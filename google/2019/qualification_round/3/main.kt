import java.math.BigInteger
import java.util.*

fun main(args: Array<String>) {
    val t = readLine()!!.toInt()
    (1..t).forEach {
        print("Case #$it: ")
        solve()
    }
}

fun solve() {
    val out = ArrayList<BigInteger>()
    val ZERO = BigInteger("0")
    var prev = BigInteger("0")
    var next = BigInteger("0")

    readLine()
    readLine()!!.split("\\s".toRegex()).map(::BigInteger).forEach { now ->
        if (prev == ZERO) { // 0
            out.add(now)
        } else if (next == ZERO) { // not determined
            if (prev == now) {
                out.add(now)
            } else {
                val p = gcd(prev, now)
                out.add(p)
                clear(out)
                next = now.divide(p)
            }
        } else {
            out.add(next)
            next = now.divide(next)
        }
        prev = now
    }
    out.add(next)

    val m = TreeMap<BigInteger, Char>()
    TreeSet<BigInteger>(out).forEachIndexed { i, v -> m[v] = 'A' + i }
    out.forEach { print(m[it]) }
    println("")
}

fun clear(out: ArrayList<BigInteger>) {
    for (i in out.size - 2 downTo 0) {
        out[i] = out[i].divide(out[i + 1])
    }
}

fun gcd(a: BigInteger, b: BigInteger): BigInteger {
    val c = a.mod(b)
    return if (c == BigInteger("0")) b else gcd(b, c)
}

