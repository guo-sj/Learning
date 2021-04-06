
/* protocol ExampleProtocol */
protocol ExampleProtocol {
    var simpleDescription: String { get }   // TODO: What is meaning of 'get'?
    mutating func adjust()
    mutating func beforeAdjust()
}

/* class SimpleClass */
class SimpleClass: ExampleProtocol {
    var simpleDescription: String = "A very simple class."
    var anotherProperty: Int = 69105

    func adjust() {
        simpleDescription += " Now 100% adjust."
    }

    func beforeAdjust() {
        simpleDescription = "A very simple class."
    }
}

var a = SimpleClass()
a.adjust()
let aDescription = a.simpleDescription
print("adjust: \(aDescription)")  

a.beforeAdjust()
let aBeforeDescription = a.simpleDescription
print("beforeAdjust: \(aBeforeDescription)")

/* struct SimpleStructure */
struct SimpleStructure: ExampleProtocol {
    var simpleDescription: String = "A simple structure"

    mutating func adjust() {   // 'mutating' is to declare that this func can modify the structure's member, simpleDescription here.
        simpleDescription += " (adjusted)"
    }

    mutating func beforeAdjust() {
        simpleDescription = "A simple structure"
    }
}

var b = SimpleStructure()
b.adjust()
let bDescription = b.simpleDescription
print("adjust: \(bDescription)")

b.beforeAdjust()
let bBeforeDescription = b.simpleDescription
print("beforeAdjust: \(bBeforeDescription)")

/* extension to Int */
extension Int: ExampleProtocol {
    var simpleDescription: String {
        return "The number \(self)"
    }

    mutating func adjust() {
        self += 42
    }

    mutating func beforeAdjust() {}
}

print(7.simpleDescription)

/* protocol AbsoluteValueProtocol */
protocol AbsoluteValueProtocol {
    var simpleDescription: String { get }
    mutating func getAbsoluteValue()
}

/* extension to Double */
extension Double: AbsoluteValueProtocol {
    var simpleDescription: String {
        return "The Double Value is \(self)."
    } 

    mutating func getAbsoluteValue() {
        let absoluteValue = abs(self)
        print("Its absolute value is \(absoluteValue).")
    }
}

var doubleValue = -7.7
print(doubleValue.simpleDescription)

doubleValue.getAbsoluteValue()

/* use protocol 'ExampleProtocol' like any other named type */
let protocolValue: ExampleProtocol = a   // 'a' is a SimpleClass type variable
print(protocolValue.simpleDescription)
//print(protocolValue.anotherProperty)   // fatal error: value of type 'ExampleProtocol' has no member 'anotherProperty'
