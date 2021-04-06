/* Compute number's factorial, recursive version */
func factorialRe(n: Int) -> Int {
    if n <= 1 { return n }
    return n * factorialRe(n: n - 1)
}

/* Compute number's factorial, loop version */
func factorialLo(n: Int) -> Int {
    var f = n, i = n
    guard f > 1 else { return f }

    repeat {
        f *= (i - 1)
        i -= 1
    } while (i > 1)
    return f
}

let number = 1
print("\(number)! is equal to \(factorialRe(n: number))")    // recursive version
print("\(number)! is equal to \(factorialLo(n: number))")    // loop version
