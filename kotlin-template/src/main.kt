fun main() {
    println(": ${getInts()}")
}

fun getInt() = readLine()!!.toInt()
fun getInts() = readLine()!!.split(" ").map { it.toInt() }
fun getLong() = readLine()!!.toLong()
fun getLongs() = readLine()!!.split(" ").map { it.toLong() }
