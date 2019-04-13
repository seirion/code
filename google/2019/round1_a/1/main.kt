import java.util.*

fun main(args: Array<String>) {
    repeat(readLine()!!.toInt()) {
        print("Case #${it + 1}: ")
        solve()
    }
}

fun solve() {
    val n = readLine()!!.toInt()
    val input = ArrayList<String>()
    repeat(n) { input.add(readLine()!!.reversed()) }
    input.sort()

    val t = Trie('_') // root
    input.forEach { t.put(it) }
    println("${n - t.unused()}")
}

data class Trie(
        val c: Char,
        val root: Boolean = (c == '_'),
        var terminal: Boolean = false,
        val child: ArrayList<Trie> = ArrayList()
) {
    fun put(str: String, index: Int = 0) {
        val c = str[index]
        if (child.isEmpty() || child.last().c != c) {
            child.add(Trie(c))
        }

        if (str.length == index + 1) {
            child.last().terminal = true
        } else {
            child.last().put(str, index + 1)
        }
    }

    fun unused(): Int {
        if (child.isEmpty()) return 1

        var r = child.map { it.unused() }.sum()
        if (terminal) r++

        if (!root && r >= 2) r -= 2
        return r
    }
}

