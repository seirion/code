import java.util.*

var n = 0
var limit = 0
val prime = arrayListOf(2)
var v = emptyList<Int>() // input

fun main(args: Array<String>) {
    for (i in 3 until 10000 step 2) {
        if (isPrime(i)) prime.add(i)
    }
    val t = readLine()!!.toInt()
    (1..t).forEach {
        print("Case #$it: ")
        input()
        solve()
    }
}

fun isPrime(i: Int) = prime.none { i % it == 0 }

fun input() {
    val temp = readLine()!!.split(" ").map { s -> s.toInt() }
    limit = temp[0]
    n = temp[1]
    v = readLine()!!.split("\\s".toRegex()).map { s -> s.toInt() }
}

fun solve() {
    val out = ArrayList<ArrayList<Int>>()
    var prev = -1
    var next = -1
    v.forEach { i ->
        val p1 = prime.first { i % it == 0 }
        val p2 = i / p1

        when (next) {
            -1 -> { // not determined the result so far
                if (prev == -1 || prev == i) {
                    if (p1 == p2) { // AA
                        out.add(arrayListOf(p1))
                        next = p1
                    } else {
                        out.add(arrayListOf(p1, p2))
                    }
                } else { // finally it determined
                    val c1 = out[out.size-1][0]
                    val c2 = out[out.size-1][1]

                    if (p1 == c1 || p1 == c2) {
                        out.add(arrayListOf(p1))
                        next = p2
                    } else {
                        out.add(arrayListOf(p2))
                        next = p1
                    }
                    clear(out)
                }
            }
            else -> {
                if (p1 == next) {
                    out.add(arrayListOf(p1))
                    next = p2
                } else {
                    out.add(arrayListOf(p2))
                    next = p1
                }
            }
        }

        // forward
        prev = i
    }
    out.add(arrayListOf(next))

    val s = TreeSet<Int>()
    out.map { it[0] }.forEach { s.add(it) }
    val m = TreeMap<Int, Char>()
    s.forEachIndexed { i, v -> m[v] = 'A' + i }

    out.map { it[0] }.forEach { print(m[it]) }
    println("")
}

fun clear(out: ArrayList<ArrayList<Int>>) {
    var current = out[out.size-1][0]

    var i = out.size - 2
    while (i >= 0) {
        val p1 = out[i][0]
        val p2 = out[i][1]

        if (p1 == current) {
            out[i] = arrayListOf(p2)
            current = p2
        } else {
            out[i] = arrayListOf(p1)
            current = p1
        }
        i--
    }
}

