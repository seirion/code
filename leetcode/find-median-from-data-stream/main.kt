// https://leetcode.com/problems/find-median-from-data-stream
import java.util.*

class MedianFinder() {
    private val lower = PriorityQueue<Int>(Collections.reverseOrder())
    private val upper = PriorityQueue<Int>()

    fun addNum(num: Int) {
        lower.add(num)
        upper.add(lower.poll())
        if (lower.size != upper.size) {
            lower.add(upper.poll())
        }
    }

    fun findMedian(): Double {
        return if (lower.size == upper.size) (lower.peek().toDouble() + upper.peek()) / 2
        else lower.peek().toDouble()
    }
}

fun main(args: Array<String>) {
    val m = MedianFinder()
    m.addNum(1)
    m.addNum(2)
    m.addNum(3)
    println(m.findMedian())
}
