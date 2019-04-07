import java.util.*

fun main(args: Array<String>) {
    val t = readLine()!!.toInt()
    (1..t).forEach {
        solve()
    }
}

fun solve() {
    val (N, B, F) = readLine()!!.split("\\s".toRegex()).map { it.toInt() }

    val response = ArrayList<String>()
    (0 until F).forEach {
        println(bitFlag(N, 1 shl it))
        readLine()!!.let { s -> response.add(s) }
    }

    val s = ArrayList<Int>(N - B).apply {
        repeat(N - B) { add(0) }
    }
    response.forEachIndexed { row, value ->
        value.forEachIndexed { col, v -> if (v == '1') s[col] += (1 shl row) }
    }

    println((0 until N).toSet().minus(s).joinToString(" "))
    readLine()
}

fun bitFlag(size: Int, gap: Int) =
        ("0".repeat(gap) + "1".repeat(gap))
                .repeat(size / gap + gap)
                .take(size)

