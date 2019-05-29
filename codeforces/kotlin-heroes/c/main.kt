fun main(args: Array<String>) {
    val q = readLine()!!.toInt()
    repeat(q) { solve() }
}

fun solve() {
    val s1 = readLine()!!
    val s2 = readLine()!!

    var a = 0
    var b = 0

    while (a < s1.length && b < s2.length) {
        if (s1[a] == s2[b]) {
            a++
            b++
        } else if (s1[a] == '+') {
            break
        } else {
            a++
            if (a >= s1.length || s1[a] != '-') break
            a++
            b++
        }
    }

    println(if (a == s1.length && b == s2.length) "YES" else "NO")
}
