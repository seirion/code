fun main(args: Array<String>) {
    repeat(readLine()!!.toInt()) {
        print("Case #${it + 1}: ")
        solve()
    }
}

fun solve() {
    val a = StringBuilder()
    val b = StringBuffer()
    readLine()!!
            .map {
                if (it == '4') Pair('2', '2')
                else Pair(it, '0')
            }
            .forEach {
                a.append(it.first)
                b.append(it.second)
            }
    println("$a ${b.dropWhile { it == '0' }}")
}

