// part 1
fun main() {
	var out = 0
	while (true) {
		val input  = readLine() ?: break
		val (a, b) = input.split(",").map { it.split("-").map { it.toInt() } }

		if (fullyIncludes(a, b) || fullyIncludes(b, a)) out++
	}
	println(out)
}

fun fullyIncludes(a: List<Int>, b: List<Int>): Boolean {
	return (b[0]..b[1]).let {
		a[0] in it && a[1] in it
	}
}

// part 2
fun main() {
	var out = 0
	while (true) {
		val input  = readLine() ?: break
		val (a, b) = input.split(",").map { it.split("-").map { it.toInt() } }
		if (!(a[1] < b[0] || b[1] < a[0])) out++
	}
	println(out)
}
