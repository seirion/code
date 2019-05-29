import java.util.*

fun main(args: Array<String>) {
    val c = readLine()
    val q = PriorityQueue<Int>()
    var r = 0
    readLine()!!.split(" ").map { it.toInt() }.forEach {
        if (q.size >= 2 && q.peek() > it) r++
        q.add(it)
        if (q.size > 2) q.poll()
    }
    println(r)
}
