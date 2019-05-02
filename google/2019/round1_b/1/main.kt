import java.util.*

fun main(args: Array<String>) {
    val t = readLine()!!.toInt()
    repeat(t) { solve(it) }
}

data class Input(val x: Int, val y: Int, val c: Char)

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

    data.forEach { inputData ->
        when (inputData.c) {
            'W' -> put(xValues) { it < inputData.x }
            'E' -> put(xValues) { it > inputData.x }
            'S' -> put(yValues) { it < inputData.y }
            else -> put(yValues) { it > inputData.y }
        }
    }

    val xMax = xValues.maxBy { it.value }!!
    val yMax = yValues.maxBy { it.value }!!
    println("Case #${num + 1}: ${xMax.key} ${yMax.key}")
}

fun put(m: MutableMap<Int, Int>, predicate: (Int) -> Boolean) {
    m.map { it.key }
            .filter(predicate = predicate)
            .forEach { m[it] = m[it]!! + 1 }
}

