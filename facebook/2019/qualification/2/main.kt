fun main(args: Array<String>) {
    val n = readLine()!!.toInt()
    repeat(n) {
        print("Case #${it + 1}: ")
        solve(readLine()!!)
    }
}

fun solve(s: String) {
    val empty = s.filter { it == '.' }.count()
    val b = s.filter { it == 'B' }.count()
    if (empty in 1 until b * 2) println("Y")
    else println("N")
}
