
/* enum PrinterError */
enum PrinterError: Error {
    case outOfPaper
    case noToner
    case onFire
}

/* func send */
func send(jobs: Int, toPriter printerName: String) throws -> String {
    if (printerName == "Never Has Toner") {
        throw PrinterError.noToner
    } else if (printerName == "onFire") {
        throw PrinterError.onFire
    } else if (printerName == "outOfPaper") {
        throw PrinterError.outOfPaper
    }

    return "Job sent"
}

/* use 'do-catch' to catch an error */
let sendCollection = ["Bi Sheng", "Never Has Toner", "onFire", "outOfPaper"]
var printerResponse = String()   // create an empty string by using initializer syntax; It is equivalent to 'var printerResponse = ""'

for i in 0...3 {
    do {
        printerResponse = try send(jobs: 1040, toPriter: sendCollection[i])   // 'try' mark code that can throw an error
        print(printerResponse)
    } catch PrinterError.onFire {
        print("I'll just put this over here, with the rest of the fire. ")
    } catch let printError as PrinterError {   // TODO: What's the meaning of 'let-as' here?
        print("Printer error: \(printError).")
    } catch {
        print(error)
    }
}

/* use 'try?' to convert the result to an optional 
 * 1 If throw error, specified error is discarded and return nil 
 * 2 Else the result is an optional containing the value that the function returned */
let printerSuccess = try? send(jobs: 1884, toPriter: "Mergenthaler")   // TODO: Warning: string interpolation produces a debug description for an optional value
let printerFailure = try? send(jobs: 1885, toPriter: "Never Has Toner")
print("printerSuccess: \(printerSuccess)")
print("printerFailure: \(printerFailure)")

/* use 'defer' */
var fridgeIsOpen = false
let fridgeContent = ["milk", "eggs", "leftevers"]

func fridgeContains(_ food: String) -> Bool {
    fridgeIsOpen = true
    defer {
        fridgeIsOpen = false
    }

    //let result = fridgeContent.contains(food)
    let result = fridgeIsOpen;
    return result
}

fridgeContains("banana")
print(fridgeIsOpen)

print(fridgeContains("banana"))   // Prints "true"
