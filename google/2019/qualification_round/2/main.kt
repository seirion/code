fun main(args: Array<String>) {
    val t = readLine()!!.toInt()
    (1..t).forEach { no ->
        print("Case #$no: ")
        readLine()!!.toInt()
        readLine()!!.map { if (it == 'E') 'S' else 'E' }
                .joinToString("")
                .let { println(it) }
    }
}
