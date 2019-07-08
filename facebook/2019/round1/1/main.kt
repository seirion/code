import java.util.*

fun main(args: Array<String>) {
    val t = readLine()!!.toInt()
    repeat(t) {
        print("Case #${it + 1}: ")
        solve()
    }
}

data class T(val a: Int, val b: Int, val c: Int)

fun solve() {
    val (n, m) = readLine()!!.split(" ").map { it.toInt() }
    val input = ArrayList<T>()
    val dist = ArrayList<IntArray>()

    repeat(n + 1) {
        dist.add(IntArray(n + 1) { 1000000000 } )
    }
    repeat(m) {
        val (a, b, c) = readLine()!!.split(" ").map { it.toInt() }
        input.add(T(a, b, c))
        dist[a][b] = c
        dist[b][a] = c
    }

    (1..n).forEach { i ->
        (1..n).forEach { j ->
            (1..n).forEach { k ->
                dist[j][k] = Math.min(dist[j][k], dist[j][i] + dist[i][k])
            }
        }
    }

    input.forEach {
        if (dist[it.a][it.b] != it.c) {
            println("Impossible")
            return
        }
    }
    println(m)
    input.forEach {
        println("${it.a} ${it.b} ${it.c}")
    }
}

