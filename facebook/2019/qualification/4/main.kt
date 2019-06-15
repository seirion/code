import java.util.*

fun main(args: Array<String>) {
    val n = readLine()!!.toInt()
    repeat(n) {
        print("Case #${it + 1}: ")
        solve()
    }
}

data class T(val x: Int, val y:Int, val p: Int)

fun solve() {
    fail = false
    val (n, M) = readLine()!!.split(" ").map { it.toInt() }
    val a = IntArray(n + 1) { 0 }
    val t = ArrayList<T>()
    val h = HashMap<Int, Int>()

    repeat(M) {
        val (x, y, p) = readLine()!!.split(" ").map { it.toInt() }
        t.add(T(x, y, p))
        h[p] = h.getOrElse(p, { 0 }) + 1
    }

    val v = h.toList().sortedBy { it.second }.map { it.first }

    v.forEach {
        while (true) {
            val index = find(it, t)
            if (index == -1) break
            put(t[index].x, t[index].p, a)
            put(t[index].y, t[index].p, a)
            t.removeAt(index)
        }
    }
    if (!fail && isValidTree(a)) {
        println(a.drop(1).joinToString(" "))
    } else println("Impossible")
}

var fail = false // FIXME : bad codes
fun find(i: Int, a: ArrayList<T>) = a.indexOfFirst { it.p == i }

fun put(cc: Int, p: Int, a: IntArray) {
    var c = cc
    if (c == p) {
        // nothing to do
    } else if (a[c] == 0) {
        a[c] = p
    } else {
        var temp = 0
        while (true) {
            temp++
            if (temp > 100) {
                fail = true
                return
            }
            if (c == p) return
            if (a[c] == 0) break
            c = a[c]
        }
        a[c] = p
    }
}

fun isValidTree(a: IntArray) =
        a.indexOfFirst { cycle(it, a) } == -1

fun cycle(i: Int, a: IntArray): Boolean {
    val s = HashSet<Int>()
    var x = i
    while (x != 0) {
        if (s.contains(x)) return true
        s.add(x)
        x = a[x]
    }
    return false
}
