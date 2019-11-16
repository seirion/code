fun <T : Comparable<T>> List<T>.upperBound(element: T, fromIndex: Int = 0, toIndex: Int = this.size): Int {
    var l = fromIndex
    var r = toIndex
    while (l < r) {
        val mid = (l + r) / 2
        if (element >= this[mid]) {
            l = mid + 1
        } else {
            r = mid
        }
    }
    return l
}

fun <T : Comparable<T>> List<T>.lowerBound(element: T, fromIndex: Int = 0, toIndex: Int = this.size): Int {
    var l = fromIndex
    var r = toIndex
    while (l < r) {
        val mid = (l + r) / 2
        if (element <= this[mid]) {
            r = mid
        } else {
            l = mid + 1
        }
    }
    return r
}
