class Solution {
    fun openLock(deadends: Array<String>, target: String): Int {
        val q: Queue<Pair<Int, String>> = LinkedList()
        val visit = deadends.toMutableSet()
        if (visit.contains("0000")) return -1

        q.add(0 to "0000")
        visit.add("0000")
        while (q.isNotEmpty()) {
            val (cost, s) = q.poll()
            if (s == target) return cost
            next(s).filter { !visit.contains(it) }.forEach {
                q.add(cost + 1 to it)
                visit.add(it)
            }
        }
        return -1
    }

    fun next(s: String) =
        (0 until 4).map { rotate(s, it) }.flatten()
    
    private fun rotate(s: String, i: Int) = listOf(
        StringBuilder(s).also { it[i] = left(it[i]) }.toString(),
        StringBuilder(s).also { it[i] = right(it[i]) }.toString()
    )

    private fun left(c: Char) = if (c == '0') '9' else c - 1
    private fun right(c: Char) = if (c == '9') '0' else c + 1
}
