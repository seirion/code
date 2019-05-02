import java.util.*

fun main(args: Array<String>) {
    val t = readLine()!!.toInt()
    repeat(t) { solve(it) }
}

data class Input(
        val x: Int,
        val y: Int,
        val c: Char
)

fun solve(num: Int) {
    val (P, _) = readLine()!!.split(" ").map { it.toInt() }

    val xValues = TreeMap<Int, Int>()
    val yValues = TreeMap<Int, Int>()
    val data = ArrayList<Input>()
    repeat(P) {
        val (xx, yy, d) = readLine()!!.split(" ")
        val x = xx.toInt()
        val y = yy.toInt()

        data.add(Input(x, y, d[0]))
        xValues[x] = 0
        yValues[y] = 0
        when (d[0]) {
            'W' -> xValues[x - 1] = 0
            'E' -> xValues[x + 1] = 0
            'S' -> yValues[y - 1] = 0
            else -> yValues[y + 1] = 0
        }
    }
    xValues[0] = 0
    yValues[0] = 0

    data.forEach {
        when (it.c) {
            'W' -> putLess(xValues, it.x)
            'E' -> putGreater(xValues, it.x)
            'S' -> putLess(yValues, it.y)
            else -> putGreater(yValues, it.y)
        }
    }

    val xMax = xValues.maxBy { it.value }!!
    val yMax = yValues.maxBy { it.value }!!
    println("Case #${num + 1}: ${xMax.key} ${yMax.key}")
}

fun putLess(m: MutableMap<Int, Int>, v: Int) {
    m.map { it.key }
            .filter { it < v }
            .forEach { m[it] = m[it]!! + 1 }
}

fun putGreater(m: MutableMap<Int, Int>, v: Int) {
    m.map { it.key }
            .filter { it > v }
            .forEach { m[it] = m[it]!! + 1 }
}

