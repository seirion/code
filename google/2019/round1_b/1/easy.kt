
fun main(args: Array<String>) {
    val t = readLine()!!.toInt()
    repeat(t) {
        solve(it)
    }
}

fun solve(num: Int) {
    val (P, Q) = readLine()!!.split(" ").map { it.toInt() }

    val xValues = IntArray(Q + 2) { 0 }
    val yValues = IntArray(Q + 2) { 0 }
    repeat(P) {
        val (xx, yy, d) = readLine()!!.split(" ")
        val x = xx.toInt()
        val y = yy.toInt()

        when (d) {
            "W" -> put(xValues, 0, x)
            "E" -> put(xValues, x + 1, Q + 1)
            "S" -> put(yValues, 0, y)
            else -> put(yValues, y + 1, Q + 1)
        }
    }

    var best = 0
    var bestX = 0
    var bestY = 0
    for (x in 0..Q) {
        for (y in 0..Q) {
            if (best < xValues[x] + yValues[y]) {
                best = xValues[x] + yValues[y]
                bestX = x
                bestY = y
            }
        }
    }

    println("Case #${num + 1}: $bestX $bestY")
}

fun put(array: IntArray, from:Int, to: Int) {
    (from until to).forEach { array[it]++ }
}

