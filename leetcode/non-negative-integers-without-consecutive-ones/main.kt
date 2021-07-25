class Solution {
    val m = HashMap<Int, Int>()
    fun findIntegers(n: Int): Int {
        if (n == 0) return 1
        if (m.containsKey(n)) return m[n]!!
        val i = 32 - Integer.numberOfLeadingZeros(n)
        if (i == 1) return 2 // 0, 1

        val k0 = 1 shl (i - 1)
        val k1 = 1 shl (i - 2)
        val a = findIntegers(k0 - 1)
        val b = findIntegers(if (n.check(i - 2)) k1 - 1 else n - k0)
        m[n] = a + b
        return a + b
    }
}

fun Int.check(i: Int) = (this and (1 shl i) != 0)
