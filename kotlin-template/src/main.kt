fun main() {
    println(": ${toInts()}")
}

fun toInt() = readLine()!!.toInt()
fun toInts() = readLine()!!.split(" ").map { it.toInt() }
fun toLong() = readLine()!!.toLong()
fun toLongs() = readLine()!!.split(" ").map { it.toLong() }
