
/* create generic type <Item> */
func makeArray<Item>(repeating item: Item, numberOfTimes: Int) -> [Item] {
    var result = [Item]()

    for _ in 0..<numberOfTimes {
        result.append(item)
    }

    return result
}

/* Item is equivalent to String */
let retValue1 = makeArray(repeating: "knock", numberOfTimes: 4)
print(retValue1)

/* Item is equivalent to Double */
let retValue2 = makeArray(repeating: 7.7, numberOfTimes: 4)
print(retValue2)

/* Reimplement the Swift standard library's optional type */
enum OptionalValue<Wrapped> {
    case none
    case some(Wrapped)   // TODO: What's meaning of '()' here?
}

var possibleInteger: OptionalValue<Int> = .none
possibleInteger = .some(100)
print(possibleInteger)

/* use where */
func anyCommonElements<T: Sequence, U: Sequence>(_ lhs: T, _ rhs: U) -> Bool   // Sequence protocol
    where T.Element: Equatable, T.Element == U.Element {   // TODO: What's meaning of 'where'?
    for lhsItem in lhs {
        for rhsItem in rhs {
            if lhsItem == rhsItem {
                return true
            }
        }
    }

    return false
}

print(anyCommonElements([1, 2, 3], [3]))

/* returnCommonElementArray: return an array of the elements that any two sequences have in common */
func returnCommonElementArray<T: Sequence, U: Sequence>(_ lhs: T, _ rhs: U) -> T
    where T.Element: Equatable, T.Element == U.Element {
    var tArray: T
    for lhsItem in lhs {
        for rhsItem in rhs {
            if lhsItem == rhsItem {
                tArray.append(lhsItem)   // TODO: How to add elements to a sequence?
            }
        }
    }

    return tArray
}

