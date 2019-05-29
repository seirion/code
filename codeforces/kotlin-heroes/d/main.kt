import java.util.*

fun main() {
    readLine()
    val list = readLine()!!.split(" ").map { it.toInt() }
    val size = list.filter { it == -1 }.size

    val r = ArrayList<MutableList<Int>>()
    repeat(size) { r.add(ArrayList()) }
    val q: Deque<Int> = LinkedList() // using as a queue
    (0 until size).forEach { q.add(it) }

    list.forEach {
        val index = q.pollFirst()
        r[index].add(it)
        if (it != -1) q.addLast(index)
    }

    r.forEach { it.removeAt(it.size - 1) }
    println(size)
    r.forEach { println("${it.size} ${it.joinToString(" ")}") }
}
