// part 1
fun main() {
    val a = mutableListOf(
        mutableListOf('N', 'R', 'J', 'T', 'Z', 'B', 'D', 'F'),
        mutableListOf('H', 'J', 'N', 'S', 'R'),
        mutableListOf('Q', 'F', 'Z', 'G', 'J', 'N', 'R', 'C'),
        mutableListOf('Q', 'T', 'R', 'G', 'N', 'V', 'F'),
        mutableListOf('F', 'Q', 'T', 'L'),
        mutableListOf('N', 'G', 'R', 'B', 'Z', 'W', 'C', 'Q'),
        mutableListOf('M', 'H', 'N', 'S', 'L', 'C', 'F'),
        mutableListOf('J', 'T', 'M', 'Q', 'N', 'D'),
        mutableListOf('S', 'G', 'P'),
    )

    while (true) {
        val input  = readLine() ?: break
        val (n, from, to) = input.split(" ").filter { it.first() in '0'..'9' }.map { it.toInt() -1 }

        a[to] = (a[from].take(n + 1).reversed() + a[to]).toMutableList()
        a[from] = a[from].drop(n + 1).toMutableList()
    }
    println(a.map { it.firstOrNull() ?: " " }.joinToString(""))
}

// part 2
fun main() {
    val a = mutableListOf(
        mutableListOf('N', 'R', 'J', 'T', 'Z', 'B', 'D', 'F'),
        mutableListOf('H', 'J', 'N', 'S', 'R'),
        mutableListOf('Q', 'F', 'Z', 'G', 'J', 'N', 'R', 'C'),
        mutableListOf('Q', 'T', 'R', 'G', 'N', 'V', 'F'),
        mutableListOf('F', 'Q', 'T', 'L'),
        mutableListOf('N', 'G', 'R', 'B', 'Z', 'W', 'C', 'Q'),
        mutableListOf('M', 'H', 'N', 'S', 'L', 'C', 'F'),
        mutableListOf('J', 'T', 'M', 'Q', 'N', 'D'),
        mutableListOf('S', 'G', 'P'),
    )

    while (true) {
        val input  = readLine() ?: break
        val (n, from, to) = input.split(" ").filter { it.first() in '0'..'9' }.map { it.toInt() -1 }

        a[to] = (a[from].take(n + 1) + a[to]).toMutableList()
        a[from] = a[from].drop(n + 1).toMutableList()
    }
    println(a.map { it.firstOrNull() ?: " " }.joinToString(""))
}
