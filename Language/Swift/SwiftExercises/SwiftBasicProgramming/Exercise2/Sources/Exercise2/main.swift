/* Write a Swift program to compute and return the absolute difference of n
 * and 51, if n is over 51 return double the absolute difference */

 func computeAbsoluteDifference(_ integer: Int) -> Int {
    if (integer - 51 <= 0) {
        return 51 - integer
    } else {
        return 2 * (integer - 51)
    }
}

let under51 = 44
let over51 = 57
print("The difference of \(under51) and 51 is \(computeAbsoluteDifference(under51))")
print("The double difference of \(over51) and 51 is \(computeAbsoluteDifference(over51)) ")
