import java.util.*

fun main(args: Array<String>) {
    repeat(readLine()!!.toInt()) {
        print("Case #${it + 1}: ")
        solve()
    }
}

val impossible = arrayListOf(Pair(2, 2), Pair(2, 3), Pair(2, 4), Pair(3, 2), Pair(3, 3), Pair(4, 2))

const val RIGHT = 2
const val DOWN = 1

fun solve() {
    var (row, col) = readLine()!!.split("\\s".toRegex()).map { it.toInt() }

    if (impossible.contains(Pair(row, col))) {
        println("IMPOSSIBLE")
        return
    }

    val swap = row > col
    if (swap) {
        row = row xor col
        col = row xor col
        row = row xor col
    }

    val output = ArrayList<Pair<Int, Int>>()
    val m = HashSet<Pair<Int, Int>>()
    var r = 0
    var c = 0
    repeat(row * col) {
        while (m.contains(Pair(r, c)) || (output.isNotEmpty() && !check(output.last(), Pair(r, c)))) {
            c++
            if (c == col) {
                r = (r + 1) % row
                c = 0
            }
        }
        m.add(Pair(r, c))
        output.add(Pair(r, c))
        r = (r + DOWN) % row
        c = (c + RIGHT) % col
    }

    println("POSSIBLE")
    if (swap) {
        output.map { it.second to it.first }.forEach { println("${it.first + 1} ${it.second + 1}") }
    } else {
        output.forEach { println("${it.first + 1} ${it.second + 1}") }
    }
}

fun check(a: Pair<Int, Int>, b: Pair<Int, Int>) =
        (a.first != b.first) &&
                (a.second != b.second) &&
                (a.first + a.second != b.first + b.second) &&
                (a.first - a.second != b.first - b.second)

