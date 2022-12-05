// part 1
fun main() {
	val abc = "ABC"
	val xyz = "XYZ"
	var out = 0
	while (true) {
		val input = readLine() ?: break
		val (a, b) = input.split(" ").map { it.first() }
		out += score(abc.indexOf(a), xyz.indexOf(b))
	}
	println(out)
}

fun score(a: Int, b: Int): Int {
	return (1 + b) + if (a == b) 3
		else if (b == (a + 1) % 3) 6
			else 0
}

// part 2
fun main() {
	val abc = "ABC"
	var out = 0
	while (true) {
		val input = readLine() ?: break
		val (a, b) = input.split(" ").map { it.first() }

		val aa = abc.indexOf(a)
		val bb = if (b == 'X') (aa + 2) % 3 // lose
			else if (b == 'Y') aa // draw
			else (aa + 1) % 3 // win

		out += score(aa, bb)
	}
	println(out)
}

fun score(a: Int, b: Int): Int {
	return (1 + b) + if (a == b) 3
		else if (b == (a + 1) % 3) 6
			else 0
}
