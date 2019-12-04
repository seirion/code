// https://leetcode.com/problems/validate-binary-search-tree
/**
 * Example:
 * var ti = TreeNode(5)
 * var v = ti.`val`
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int) {
 *     var left: TreeNode? = null
 *     var right: TreeNode? = null
 * }
 */
import java.util.*
class Solution {
    fun isValidBST(root: TreeNode?): Boolean {
        val list = ArrayList<Int>()
        if (root != null) {
            inorderTraversal(list, root)
        }
        return list.zip(list.drop(1)).all { it.first < it.second }
    }

    private fun inorderTraversal(list: MutableList<Int>, tree: TreeNode) {
        tree.left?.let { inorderTraversal(list, it) }
        list.add(tree.`val`)
        tree.right?.let { inorderTraversal(list, it) }
    }
}
