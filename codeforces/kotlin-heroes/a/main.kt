fun main(args: Array<String>) {
    val q = readLine()!!.toInt()
    repeat(q) { solve() }
}

fun solve() {
    val (a, b) = readLine()!!.split(" ").map { it.toInt() }.sorted()
    println("1 ${a - 1} ${b - a + 1}")
}
