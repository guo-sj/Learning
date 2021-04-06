
/* enum Rank */
enum Rank: Int, CaseIterable {
    case ace = 1
    case two, three, four, five, six, seven, eight, nine, ten
    case jack, queen, king

    func simpleDescription() -> String {
        switch self {
        case .ace:
            return "ace"

        case .jack:
            return "jack"

        case .queen:
            return "queen"

        case .king:
            return "king"

        default:
            return String(self.rawValue)
        }
    }

}

/* compares two Rank values by comparing their raw values */
func compareByRawValue(_ name1: Rank, _ name2: Rank) -> Rank {
    if (name1.rawValue >= name2.rawValue) {
        return name1
    } else {
        return name2
    }
}

/* enum Rank print info */
let ace = Rank.ace
let aceRawValue = ace.rawValue
print("ace: \(ace) \naceRawValue: \(aceRawValue)")

let two = Rank.two
print("The bigger one between two(2) and ace(1) is \(compareByRawValue(ace, two))")

if let convertedRank = Rank(rawValue: 1) {   // equivalent to 'let convertedRank = Rank.ace'
    let threeDescription = convertedRank.simpleDescription()
    print(threeDescription)
}

/* enum Suit */
enum Suit: CaseIterable {
    case spades, hearts, diamonds, clubs

    func simpleDescription() -> String {
        switch self {
        case .spades:
            return "spades"

        case .hearts:
            return "hearts"

        case .diamonds:
            return "diamonds"

        case .clubs:
            return "clubs"
        }
    }

    func color() -> String {
        switch self {
        case .spades, .clubs:
            return "black"

        case .hearts, .diamonds:
            return "red"
        }
    }
}

/* enum Suit print info */
let hearts = Suit.hearts
let heartsDescription = hearts.simpleDescription()
let heartsColor = hearts.color()
print("hearts: \(hearts) heartsDescription: \(heartsDescription) heartsColor: \(heartsColor)")

/* enum ServerResponse 
 * Note: This type enumeration does have property 'rawValue' */
enum ServerResponse {
    case result(String, String)
    case failure(String)
    case greeting(String)
}

/* enum ServerResponse print info */
var success = ServerResponse.result("6:00 am", "8:09 pm")
let failure = ServerResponse.failure("Out of Cheese.")
success = ServerResponse.failure("6:00 am")
success = ServerResponse.greeting("Welcome")

switch success {   // TODO: Does 'success' here have a '.failure' method?
case let .result(sunrise, sunset):   // TODO: What does 'let' do here?
    print("Sunrise is at \(sunrise) and sunset is at \(sunset)")

case let .failure(message):
    print("Failure... \(message)")

case let .greeting(message):
    print("Greeting from server: \(message)")
}

/* struct Card */
struct Card {
    var rank: Rank
    var suit: Suit

    func simpleDescription() -> String {
        return "The \(rank.simpleDescription()) of \(suit.simpleDescription())"
    }

    /* a function that returns an array containing a full deck of cards
     * with one card of each combination of rank and suit */
     func returnFullDeckOfCards() -> [Card] {
         var fullDeckOfCards = [Card]()
         for rank in Rank.allCases {
             for suit in Suit.allCases {
                 let tmpCards = Card(rank: rank, suit: suit)
                 print(tmpCards.simpleDescription())   // for debug
                 fullDeckOfCards.append(tmpCards)
             }
         }
         return fullDeckOfCards
     }
}

/* struct Card print info */
let threeOfSpades = Card(rank: .three, suit: .spades)
let threeOfSpadesDescription = threeOfSpades.simpleDescription()
print(threeOfSpadesDescription)

print("--------------debug Info--------------")
let fullDeckOfCards = threeOfSpades.returnFullDeckOfCards()

