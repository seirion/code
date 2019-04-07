import java.math.BigInteger
import java.util.*

var n = 0
var v = emptyList<BigInteger>() // input

fun main(args: Array<String>) {
    val t = readLine()!!.toInt()
    (1..t).forEach {
        print("Case #$it: ")
        input()
        solve()
    }
}

fun input() {
    val temp = readLine()!!.split(" ").map { s -> s.toInt() }
    n = temp[1]
    v = readLine()!!.split("\\s".toRegex()).map(::BigInteger)
}

fun solve() {
    val out = ArrayList<BigInteger>()
    val ZERO = BigInteger("0")
    var prev = BigInteger("0")
    var next = BigInteger("0")

    v.forEach { now ->
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

    val s = TreeSet<BigInteger>()
    out.forEach { s.add(it) }
    val m = TreeMap<BigInteger, Char>()
    s.forEachIndexed { i, v -> m[v] = 'A' + i }
    out.forEach { print(m[it]) }
    println("")
}

fun clear(out: ArrayList<BigInteger>) {
    var current = out[out.size - 1]
    var i = out.size - 2
    while (i >= 0) {
        out[i] = out[i].divide(current)
        current = out[i]
        i--
    }
}

fun gcd(a: BigInteger, b: BigInteger): BigInteger {
    val c = a.mod(b)
    return if (c == BigInteger("0")) b else gcd(b, c)
}

