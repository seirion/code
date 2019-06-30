import java.util.*

fun main(args: Array<String>) {
    val t = readLine()!!.toInt()
    repeat(t) {
        print("Case #${it + 1}: ")
        solve()
    }
}

data class T(val a: Int, val b: Int, val c: Int)

var parent = IntArray(1001) // membership
var connect = ArrayList<HashMap<Int, Int>>()

fun clear() {
    connect.clear()
    repeat(1001) {
        parent[it] = 0
        connect.add(HashMap())
    }
}

fun solve() {
    clear()
    val (n, m) = readLine()!!.split(" ").map { it.toInt() }
    val input = ArrayList<T>()
    repeat(m) {
        val (a, b, c) = readLine()!!.split(" ").map { it.toInt() }
        input.add(T(Math.min(a, b), Math.max(a, b), c))
    }
    input.sortWith(Comparator { x, y -> x.c.compareTo(y.c) })

    input.forEach {
        val groupA = group(it.a)
        val groupB = group(it.b)
        if (groupA != groupB) {
            parent[groupA] = groupB // merge
        }
        connect[it.a][it.b] = it.c
        connect[it.b][it.a] = it.c
    }

    input.forEach {
        val d = distance(it.a, it.b)
        if (it.c != d) {
            println("Impossible")
            return
        }
    }

    val out = ArrayList<T>()
    connect.forEachIndexed { a, hashMap ->
        hashMap.forEach { b, c -> out.add(T(a, b, c)) }
    }

    out.sortWith(Comparator { x, y ->
        if (x.a == y.a) x.b.compareTo(y.b)
        x.a.compareTo(y.a)
    })

    println(out.size / 2)
    out.filterIndexed { i, _ -> i % 2 == 0 }
            .forEach { println("${it.a} ${it.b} ${it.c}") }
}

fun group(a: Int): Int {
    if (parent[a] == 0) return a
    parent[a] = group(parent[a])
    return parent[a]
}

fun distance(a: Int, b: Int): Int {
    val q = PriorityQueue<Pair<Int, Int>> { a, b -> a.first.compareTo(b.first) }
    val visit = BooleanArray(1001) { false }
    q.add(Pair(0, a))

    while (q.isNotEmpty()) {
        val now = q.poll()
        if (now.second == b) return now.first
        visit[now.second] = true

        connect[now.second].forEach { where, dist ->
            if (!visit[where]) {
                q.add(Pair(dist + now.first, where))
            }
        }
    }
    return -1
}
