// part 1 / 2
fun main() {
    val a = readLine() ?: return
    val m = HashMap<Char, Int>()
    val distinctNumber = 14 // 4
    a.forEachIndexed { i, c ->
        m[c] = (m[c] ?: 0) + 1
        if (i >= distinctNumber) {
            val k = a[i - distinctNumber]
            m[k] = m[k]!! - 1
            if (m[k] == 0) m.remove(k)
        }
        if (m.size == distinctNumber) {
            println(i + 1)
            return
        }
    }
}
