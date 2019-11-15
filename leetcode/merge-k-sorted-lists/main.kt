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
class Solution {
    fun mergeKLists(lists: Array<ListNode?>): ListNode? {
        val q = PriorityQueue<ListNode> { a, b -> a.`val` - b.`val` }
        q.addAll(lists.filterNotNull())

        val root = ListNode(0)
        var current: ListNode? = root
        while (q.isNotEmpty()) {
            val top = q.poll()
            current?.next = ListNode(top.`val`)
            current = current?.next

            top.next?.let {
                q.add(it)
            }
        }
        return root.next
    }
}
