import java.util.*

fun main(args: Array<String>) {
    val n = readLine()!!.toInt()
    repeat(n) {
        print("Case #${it + 1}: ")
        solve(readLine()!!)
    }
}

fun isValue(c: Char) = (c == 'x' || c == 'X' || c == '0' || c == '1')
fun isOp(c: Char) = (c == '&' || c == '|' || c == '^')


fun solve(s: String) {
    val operator = Stack<Char>() // stack
    val operand = Stack<Char>() // stack

    s.forEach {
        when {
            isValue(it) -> operand.add(it)
            it == '(' -> operator.add(it)
            it == ')' -> calUntilClosing(operator, operand)
            else -> operator.add(it)
        }
    }
    while (operator.isNotEmpty()) {
        val op = operator.pop()
        val b = operand.pop()
        val a = operand.pop()
        operand.push(evaluate("$a$op$b"))
    }

    val out = operand.pop()
    if (out == '1' || out == '0') println("0")
    else println("1")
}

fun calUntilClosing(operator: Stack<Char>, operand: Stack<Char>) {
    while (true) {
        val op = operator.pop()
        if (op == '(') return

        val b = operand.pop()
        val a = operand.pop()

        operand.push(evaluate("$a$op$b"))
    }
}

val m = hashMapOf(
        "0&0" to '0', "0&1" to '0', "0&x" to '0', "0&X" to '0',
        "1&0" to '0', "1&1" to '1', "1&x" to 'x', "1&X" to 'X',
        "x&0" to '0', "x&1" to 'x', "x&x" to 'x', "x&X" to '0',
        "X&0" to '0', "X&1" to 'X', "X&x" to '0', "X&X" to 'X',

        "0|0" to '0', "0|1" to '1', "0|x" to 'x', "0|X" to 'X',
        "1|0" to '1', "1|1" to '1', "1|x" to '1', "1|X" to '1',
        "x|0" to 'x', "x|1" to '1', "x|x" to 'x', "x|X" to '1',
        "X|0" to 'X', "X|1" to '1', "X|x" to '1', "X|X" to 'X',

        "0^0" to '0', "0^1" to '1', "0^x" to 'x', "0^X" to 'X',
        "1^0" to '1', "1^1" to '1', "1^x" to 'X', "1^X" to 'x',
        "x^0" to 'x', "x^1" to 'X', "x^x" to '0', "x^X" to '1',
        "X^0" to 'X', "X^1" to 'x', "X^x" to '1', "X^X" to '0'
)

fun evaluate(s: String) = m[s]!!

