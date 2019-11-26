// https://leetcode.com/problems/snakes-and-ladders
import java.util.*

class Solution {
    data class Data(val cost: Int, val index: Int)
    fun snakesAndLadders(board: Array<IntArray>): Int {
        val size = board.size * board.size
        val jump = board.reversed()
                .mapIndexed { i, b -> if (i % 2 == 0) b.toList() else b.reversed() }
                .flatten()
                .mapIndexed { i, v -> if (v == -1) i else v - 1 } // zero-based indexing

        val q: Queue<Data> = LinkedList()
        val visit = BooleanArray(size) { false }
        q.add(Data(0, 0))
        visit[0] = true

        while (q.isNotEmpty()) {
            val from = q.poll()
            if (from.index == size - 1) return from.cost
            (1..6).map { from.index + it }
                    .filter { it in 0 until size }
                    .map { jump[it] }
                    .filterNot { visit[it] }
                    .forEach { to ->
                        visit[to] = true
                        q.add(Data(from.cost + 1, to))
                    }
        }
        return -1
    }
}

fun main(args: Array<String>) {
    val input = arrayOf(
            intArrayOf(-1, -1, -1, -1, -1, -1),
            intArrayOf(-1, -1, -1, -1, -1, -1),
            intArrayOf(1, -1, -1, -1, -1, -1),
            intArrayOf(1, 35, -1, -1, 13, -1),
            intArrayOf(1, -1, -1, -1, -1, -1),
            intArrayOf(1, 15, -1, -1, -1, -1)
    )
    println(Solution().snakesAndLadders(input))

    val input2 = arrayOf(
            intArrayOf(-1, -1, -1, -1, 48, 5, -1),
            intArrayOf(12, 29, 13, 9, -1, 2, 32),
            intArrayOf(-1, -1, 21, 7, -1, 12, 49),
            intArrayOf(2, 37, 21, 40, -1, 22, 12),
            intArrayOf(2, -1, 2, -1, -1, -1, 6),
            intArrayOf(9, -1, 35, -1, -1, 39, -1),
            intArrayOf(1, 36, -1, -1, -1, -1, 5)
    )
    println(Solution().snakesAndLadders(input2))
}

