// https://leetcode.com/problems/merge-k-sorted-lists

import java.util.*

/**
 * Example:
 * var li = ListNode(5)
 * var v = li.`val`
 * Definition for singly-linked list.
 * class ListNode(var `val`: Int) {
 *     var next: ListNode? = null
 * }
 */

class ListNode(var `val`: Int) {
    var next: ListNode? = null

    override fun toString(): String {
        val out = ArrayList<Int>()
        var i: ListNode? = this
        while (i != null) {
            out.add(i.`val`)
            i = i.next
        }
        return out.joinToString(" -> ")
    }
}

class Solution {
    data class Data(val value: Int, val index: Int) : Comparable<Data> {
        override fun compareTo(other: Data): Int {
            return value.compareTo(other.value)
        }
    }

    fun mergeKLists(lists: Array<ListNode?>): ListNode? {
        val candidate = ArrayList<ListNode?>()
        candidate.addAll(lists)

        val q = PriorityQueue<Data>()
        lists.forEachIndexed { i, v ->
            if (v != null) {
                q.add(Data(v.`val`, i))
                candidate[i] = v.next
            }
        }

        val root = ListNode(0)
        var out: ListNode? = root
        while (q.isNotEmpty()) {
            val top = q.poll()
            out!!.next = ListNode(top.value)
            out = out.next

            candidate[top.index]?.let {
                q.add(Data(it.`val`, top.index))
                candidate[top.index] = it.next
            }
        }
        return root.next
    }
}
