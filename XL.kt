fun main() {
    // take a input
    val input = readLine()!!.toInt()
    // run a while loop until the input is 0
    while (input != 0) {
        // take long a input for array size
        val arraySize = readLine()!!.toInt()
        // take long array of n size integers from the input
        val arr = readLine()!!.split(" ").map { it.toLong() }.toLongArray()
        // call a biary search function
        println(binarySearch(array, input))
    }
}
// write a binary function 
fun binarySearch(arr: LongArray, x: Long): Int {
    // take a start and end index
    var start = 0
    var end = 300000000
    var ans = -1
    // run a while loop until start and end index are equal
    while (start <= end) {
        val mid = (start + end) / 2
        //  run a for loop to check if abs(a[i] - mid) > k or not;
    }
    return ans
}