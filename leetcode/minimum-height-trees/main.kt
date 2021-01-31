class Solution {
    fun findMinHeightTrees(n: Int, edges: Array<IntArray>): List<Int> {
        val g = HashMap<Int, HashSet<Int>>()
        repeat(n) { g[it] = HashSet() }
        edges.forEach { (a, b) ->
            g[a]!!.add(b)
            g[b]!!.add(a)
        }

        while (g.size > 2) {
            g.filter { it.value.size == 1 }.forEach {
                g[it.key]!!.forEach { v ->
                    g[v]!!.remove(it.key)
                }
                g.remove(it.key)
            }
        }

        return g.map { it.key }
    }
}
