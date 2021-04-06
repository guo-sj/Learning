
/* let names = ["Chris", "Alex", "Ewa", "Barry", "Daniella"];

var reversedNames = names.sorted(by: { (s1: String, s2: String) -> Bool in return s1 < s2});

print(reversedNames); */

var numbers = [20, 19, 7, 12]
var mapResult1 = numbers.map( { (number: Int) -> Int in 
    let result = 3 * number;
    return result;
});

let mapResult2 = numbers.map( { (number: Int) -> Int in
    if (number%2 != 0) {
            return 0;
        } else {
                return number;
            }
})

let mapResult3 = numbers.map( {number in 4*number});

let mapResult4 = numbers.sorted { $0 > $1 }

//print(mapResult1);
//print(mapResult2);
//print(mapResult3);
print(mapResult4);

