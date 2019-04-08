import java.util.*

fun main(args: Array<String>) {
    repeat(readLine()!!.toInt()) { solve() }
}

fun solve() {
    val (N, B, F) = readLine()!!.split("\\s".toRegex()).map { it.toInt() }

    val response = ArrayList<String>()
    repeat(F) {
        println(bitFlag(N, 1 shl it))
        readLine()!!.let { s -> response.add(s) }
    }

    val s = ArrayList<Int>(N - B).apply {
        repeat(N - B) { add(0) }
    }
    response.forEachIndexed { row, value ->
        value.forEachIndexed { col, v -> if (v == '1') s[col] += (1 shl row) }
    }

    println(missing(s, N).joinToString(" "))
    readLine()
}

fun missing(s: ArrayList<Int>, N: Int): Set<Int> {
    val result = (0 until N).toMutableSet()
    var segment = 0
    var prev = -1
    s.forEach { i ->
        if (i < prev) segment++
        result.remove(segment * 32 + i)
        prev = i
    }
    return result
}

fun bitFlag(size: Int, gap: Int) =
        ("0".repeat(gap) + "1".repeat(gap))
                .repeat(size / gap + gap)
                .take(size)

