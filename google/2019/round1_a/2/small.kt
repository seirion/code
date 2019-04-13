import java.util.*

fun main(args: Array<String>) {
    val (T, N, M) = readLine()!!.split("\\s".toRegex()).map { s -> s.toInt() }
    repeat(T) { solve(N, M) }
}

fun solve(night: Int, max: Int) {
    val out = ArrayList<Int>().apply { repeat(18) { add(18) } }
    var currentSum = 0
    repeat(night) {
        println(out.joinToString(" "))
        val input = readLine()!!.split("\\s".toRegex()).map { s -> s.toInt() }.sum()
        currentSum = Math.max(currentSum, input)
    }

    println(currentSum)
    readLine()
}

