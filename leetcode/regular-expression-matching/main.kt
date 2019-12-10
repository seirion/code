// https://leetcode.com/problems/regular-expression-matching
class Solution {
    fun isMatch(s: String, p: String): Boolean {
        return isMatch(s, 0, p, 0)
    }
    private fun isMatch(s: String, sIndex: Int, p: String, pIndex: Int): Boolean {
        if (s.length == sIndex && p.length == pIndex) return true
        if (p.length == pIndex) return false

        val star = (pIndex + 1 < p.length && p[pIndex + 1] == '*')

        if (star) {
            if (p[pIndex] == '.') {
                return (sIndex .. s.length).any {
                    isMatch(s, it, p, pIndex + 2)
                }
            } else {
                return (sIndex .. s.length)
                        .takeWhile {
                            it == sIndex || s[it - 1] == p[pIndex]
                        }
                        .any {
                            isMatch(s, it, p, pIndex + 2)
                        }
            }
        } else {
            if (s.length == sIndex) return false
            if (p[pIndex] == '.' || s[sIndex] == p[pIndex]) {
                return isMatch(s, sIndex + 1, p, pIndex + 1)
            }
        }
        return false
    }
}

fun main(args: Array<String>) {
    println(Solution().isMatch("aa", "a")) // false
    println(Solution().isMatch("aa", "a*")) // true
    println(Solution().isMatch("ab", ".*")) // true
    println(Solution().isMatch("aab", "c*a*b")) // true
    println(Solution().isMatch("mississippi", "mis*is*p*.")) // false

    println(Solution().isMatch("ab", ".*c")) // false
}

