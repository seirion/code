import java.util.*

fun main(args: Array<String>) {
    val t = readLine()!!.toInt()
    repeat(t) {
        print("Case #${it + 1}: ")
        solve()
    }
}

val WINNING_CASES = hashSetOf("RS", "SP", "PR")

fun solve() {
    val A = readLine()!!.toInt()
    val input = ArrayList<String>()
    repeat(A) {
        val list = readLine()!!
        input.add(list)
    }

    val out = StringBuilder()
    val won = BooleanArray(A) { false }
    (0 until 10000).forEach {i ->
        val s = HashSet<Char>()
        (0 until input.size)
                .filter { !won[it] }
                .map { input[it] }
                .map { it[i % it.length] }
                .forEach { s.add(it) }

        if (s.size == 3) {
            println("IMPOSSIBLE")
            return
        }

        if (s.size == 1) {
            when (getWinning(s)) {
                'S' -> out.append('R')
                'P' -> out.append('S')
                else -> out.append('P')
            }
            println(out.toString())
            return
        }

        val c = getNotLosing(s)
        out.append(c)
        (0 until input.size)
                .filter { !won[it] }
                .filter { WINNING_CASES.contains("$c${input[it][i % input[it].length]}") }
                .forEach { won[it] = true }

    }
    println("IMPOSSIBLE")
}

fun getWinning(s: Set<Char>): Char {
    if (s.contains('S')) return 'S'
    if (s.contains('P')) return 'P'
    return 'R'
}

fun getNotLosing(s: Set<Char>): Char {
    if (!s.contains('S')) return 'P'
    if (!s.contains('P')) return 'R'
    return 'S'
}
