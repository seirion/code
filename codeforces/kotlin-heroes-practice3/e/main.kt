import java.util.*
 
fun main(args: Array<String>) {
    val quarrel = HashMap<Int, Int>() // # of quarrel whose skill is greater than me
    val k = TreeMap<Int, Int>()
    val (n, q) = getInts()
    val a = getInts()
    a.forEach {
        k[it] = (k[it] ?: 0) + 1
    }
    repeat(q) {
        val (x, y) = getInts()
        if (a[x - 1] < a[y - 1]) {
            quarrel[y - 1] = (quarrel[y - 1] ?: 0) + 1
        } else if (a[x - 1] > a[y - 1]) {
            quarrel[x - 1] = (quarrel[x - 1] ?: 0) + 1
        }
    }
 
    val acc = HashMap<Int, Int>()
    var accCount = 0
    k.toList().forEach {
        acc[it.first] = accCount
        accCount += it.second
    }
 
    println(
            a.mapIndexed { i, v -> acc[v]!! - (quarrel[i] ?: 0) }.joinToString(" ")
    )
}
 
fun getInt() = readLine()!!.toInt()
fun getInts() = readLine()!!.split(" ").map { it.toInt() }
