
/* Constants and Variables */
print("---------------Constants and Variables---------------")
let maximumNumberOfLoginAttempts = 10   // constant
var currentLoginAttempt = 0   // variable

var x = 0.0, y = 0.0, z = 0.0   // declare multiple variables or 
let a = 77, b = 88, c = 99      // constants on a single line

print(x, y, z)
print(a, b, c)

/* Type Annotations */
print("---------------Type Annotations---------------")
var welcomeMessage: String
welcomeMessage = "Hello"
print(welcomeMessage)

var red, green, blue: Double   // define multiple related variables of the same type on a single line
red = 1.2; green = 1.3; blue = 1.4
print(red, green, blue)

/* Naming Constants and Variables */
print("---------------Naming Constants and Variables---------------")
let π = 3.14159
let 你好 =  "你好世界"
print(你好)

//var 1i = 77   // names of variables and constants can't begin with a number

var friendlyWelcome = "Hello!"
friendlyWelcome = "Bonjour!"
print(friendlyWelcome)

let languageName = "Swift"
//languageName = "Swift++"   // constant cannot be changed after declared


/* Printing Constants and Variables */
print("---------------Printing Constants and Variables---------------")
let multiplier = 3
let message = "\(multiplier) times 2.5 is \(Double(multiplier) * 2.5)"   // type cast: Int -> Double
print(message)

print(#"Write an interpolated string in Swift using \(multiplier)"#)
// Prints "Write an interpolated string in Swift using \(multiplier)"

print("6 times 7 is \(6 * 7)")
// Prints "6 times 7 is 42"
print(#"6 times 7 is \#(6 * 7)"#)
// Prints "6 times 7 is 42"


/* Comments */
// This is a comment.   // single line comment

/* This is also a comment 
 * but is written over multiple lines */

/* This is the start of the first multiline comment.
 /* This is the second, nested multiline comment. */
 * This is the end of the first multiline comment. */


/* Semicolons(;) */

/* Integers */
print("---------------Integers---------------")
let minValue = UInt8.min   // minValue is equal to 0, and is of type UInt8
let maxValue = UInt8.max   // maxValue is equal to 255, and is of type UInt8
print(minValue, maxValue)

/* Type Safety and Type Inference */

/* Numeric Literals */
print("---------------Numeric Literals---------------")
let decimalInteger = 17         // decimal
let binaryInteger = 0b10001     // 17 in binary notation
let octalInteger = 0o21         // 17 in octal notation
let hexadecimalInteger = 0x11   // 17 in hexadecimal notation
print(decimalInteger, binaryInteger, octalInteger, hexadecimalInteger)


/* Numeric Type Conversion */
print("---------------Numeric Type Conversion---------------")

/* Integer Conversion */
let twoThousand: UInt16 = 2_000
let one: UInt8 = 1
let twoThousandAndOne = twoThousand + UInt16(one)
print(twoThousandAndOne)

/* Integer and Floating-Point Conversion */
let three = 3
let pointOneFourOneFiveNine = 0.14159
let pi = Double(three) + pointOneFourOneFiveNine
print(pi)

let integerPi = Int(pi)
print(integerPi)

/* Type Alias */
print("---------------Type Alias---------------")
typealias AudioSample = UInt16
var maxAmplitudeFound = AudioSample.min   // AudioSample.min is equal to UInt16.min
print(maxAmplitudeFound)

/* Booleans */
print("---------------Booleans---------------")
let orangesAreOrange = true
let turnipsAreDelicious = false

if turnipsAreDelicious {
    print("Mmm, tasty turnips!")
} else {
    print("Eww, turnips are horrible!")
}

/* Tuples */
print("---------------Tuples---------------")
let http404Error = (404, "Not Found")   // create a tuple of (Int, String)
print(http404Error)

let (statusCode, statusMessage) = http404Error    // decompose a tuple
print(statusCode)
print(statusMessage)

let (justTheStatusCode, _) = http404Error    // get only '404', ignore 'Not Found' by using a underscore (_)
print("The status code is \(justTheStatusCode)")

print("The status code is \(http404Error.0)")    // access the individual element values in a tuple
print("The status message is \(http404Error.1)") // using index numbers starting at **zero**

let http200Status = (statusCode: 200, description: "OK")    // name the individual elements in a tuple
print("The status code is \(http200Status.statusCode)")
print("The status code is \(http200Status.0)")
print("The status message is \(http200Status.description)")
print("The status message is \(http200Status.1)")

/* Optionals */
print("---------------Optionals---------------")
let possibleNumber = "123"
let convertedNumber1 = Int(possibleNumber)    // return an optional
print(convertedNumber1!)

if convertedNumber1 != nil {    // find out whether an optional contains a value by comparing the optional against 'nil'
    print("convertedNumber1 contains some integer value.")
}

if convertedNumber1 != nil {    
    print("convertedNumber1 has an integer value of \(convertedNumber1!)")    // use an exclamation point(!) to the end of the optional's name
}

/* Optional Binding */
if let actualNumber = Int(possibleNumber) {
    print("The string \"\(possibleNumber)\" has an integer value of \(actualNumber)")
} else {
    print("The string \"\(possibleNumber)\" couldn't be converted to an integer")
}

if let firstNumber = Int("4"), let secondNumber = Int("42"), firstNumber < secondNumber && secondNumber < 100 {
    print("Including as many optional binding and Boolean conditions in a single 'if' statement: ")
    print("\(firstNumber) < \(secondNumber) < 100")
}

if let firstNumber = Int("4") {
    if let secondNumber = Int("42") {
        if firstNumber < secondNumber && secondNumber < 100 {
            print("many optional bindings and Boolean conditions separated into multiple 'if' statement: ")
            print("\(firstNumber) < \(secondNumber) < 100")
        }
    }
}

//print("\(firstNumber) < \(secondNumber) < 100")    // test firstNumber and secondNumber whether can be used outside the if block which it is defined: Can't

/* guard */
guard let firstNumber = Int("4") else {
    print("guard else statements ... ")
    fatalError("guard else", file: "main.swift", line: 181) 
}
print("guard: firstNumber has a value of \(firstNumber)")


/* nil */
var serverResponseCode: Int? = 404
print(serverResponseCode!)
serverResponseCode = nil

/* implicitly unwrapped optional */
let possibleString: String? = "An optional string"
let forcedString: String = possibleString!    // requires an exclamation point

let assumedString: String! = "An implicitly unwrapped optional string"
let implicitString: String = assumedString    // no need for an exclamation point
print("implicitString: \(implicitString)")

let optionalString = assumedString
print("optionalString!: \(optionalString!)")

if assumedString != nil {    // check whether an implicitly unwrapped optional by comparing against nil optional binding
    print("assumedString!: \(assumedString!)")
}

if let defineString = assumedString {    // check whether an implicitly unwrapped optional by optional binding
    print("defineString: \(defineString)")
}

/* Error Handling */
print("---------------Error Handling---------------")
/* Debugging with Assertion */
let age = -3
//assert(age >= 0, "A person's age can't be less than zero.")
//assert(age >= 0)    // can omit the assertion message

if age > 10 {
    print("You can ride the roller-coaster or the ferris wheel. ")
} else if age >= 0 {
    print("You can ride the ferris wheel.")
}/* else {
    //assertionFailure("A person's age can't be less than zero.")
}*/
/* Enforcing Preconditions */
let index = -6
//precondition(index > 0, "Index must be greater than zero.")
if index < 0 {
    preconditionFailure("Index must be greater than zero")
}
