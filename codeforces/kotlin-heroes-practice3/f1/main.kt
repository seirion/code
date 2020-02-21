import java.util.*

fun main(args: Array<String>) {
    val (n, m) = getInts()
    val a = getInts()

    val me = a.indexOfFirst { it == m }
    val left = HashMap<Int, Long>()
    val right = HashMap<Int, Long>()

    var cur = 0
    for (i in me downTo 0) {
        if (m > a[i]) cur++
        else if (m < a[i]) cur--
        left[cur] = (left[cur] ?: 0) + 1
    }
    cur = 0
    for (i in me until n) {
        if (m < a[i]) cur++
        else if (m > a[i]) cur--
        right[cur] = (right[cur] ?: 0) + 1
    }
    var out = 0L
    left.forEach {
        val k = it.key
        val v = it.value
        right[k]?.let { r -> out += v * r }
        right[k + 1]?.let { r -> out += v * r }
    }
    println(out)
}

fun getInt() = readLine()!!.toInt()
fun getInts() = readLine()!!.split(" ").map { it.toInt() }
fun getLong() = readLine()!!.toLong()
fun getLongs() = readLine()!!.split(" ").map { it.toLong() }
