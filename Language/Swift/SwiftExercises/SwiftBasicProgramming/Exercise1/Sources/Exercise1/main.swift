/* Write a Swift program to compute the sum of the two integers. 
 * If the values are equal return the triple their sum */

 func computeSum(a: Int, b: Int) -> Int {
    if (a == b) {
        return 3 * (a + b)
    }

    return a + b
}

let inta = 10
let intb = 7
print("\(inta) + \(intb) = \(computeSum(a: inta, b: intb))")
print("the triple of (\(intb) + \(intb)) is \(computeSum(a: intb, b: intb))")

