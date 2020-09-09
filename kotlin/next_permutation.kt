// https://leetcode.com/problems/next-permutation

fun nextPermutation(nums: IntArray): Unit {
    nums.reverse()
    var to = nums.zip(nums.drop(1))
            .indexOfFirst { it.first > it.second }
            .let { if (it == -1) nums.lastIndex else it }
    if (to < nums.lastIndex) {
        val s = nums.indexOfFirst { nums[to + 1] < it }
        nums.swap(s, to + 1)
    }
    var from = 0
    while (from < to) {
        nums.swap(from++, to--)
    }
    nums.reverse()
}

fun IntArray.swap(a: Int, b: Int) {
    val temp = this[a]
    this[a] = this[b]
    this[b] = temp
}
