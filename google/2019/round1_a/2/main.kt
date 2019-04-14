import java.util.*

fun main(args: Array<String>) {
    val (T, N, M) = readLine()!!.split("\\s".toRegex()).map { s -> s.toInt() }
    repeat(T) { solve(N, M) }
}

val prime = arrayListOf(5, 7, 9, 11, 13, 16, 17)

fun solve(night: Int, max: Int) {
    val response = ArrayList<Int>()
    repeat(prime.size) { index ->
        println(IntArray(18) { prime[index] }.joinToString(" "))
        val v = readLine()!!.split("\\s".toRegex()).map { s -> s.toInt() }.sum() % prime[index]
        response.add(v)
    }
    println(calculate(response, max))
    readLine()
}

fun calculate(response: List<Int>, max: Int): Int {
    for (v in 1..max) {
        if ((0 until prime.size).all { v % prime[it] == response[it] }) return v
    }
    return 0
}

