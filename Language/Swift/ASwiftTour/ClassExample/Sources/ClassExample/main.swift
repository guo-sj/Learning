
import Darwin

/* SuperClass NamedShape */
class NamedShape {
    var numberOfSides: Int = 0;
    var name: String;

    init(name: String) {
        self.name = name;
    }

    func simpleDescription() -> String {
        return "A shape with \(numberOfSides) sides.";
    }

    func detailDescription() -> String {
        return "\(name): A shape with \(numberOfSides) sides.";
    }

    deinit {
            // perform the deinitialization
        }
}

/* SuperClass NamedShape print info */
/* 
var myNamedShape = NamedShape(numberOfSides: 3, name: "Triangle");   // declaration
print(myNamedShape.simpleDescription());
print(myNamedShape.detailDescription());

var yourNamedShape = NamedShape.init(numberOfSides: 4, name: "rectangle");   // initializer
print(yourNamedShape.simpleDescription());
print(yourNamedShape.detailDescription());*/

/* SubClass Square */
class Square: NamedShape {
    var sideLength: Double;

    init(sideLength: Double, name: String) {
        self.sideLength = sideLength;
        super.init(name: name);
        numberOfSides = 4;
    }

    func area() -> Double {
        return sideLength * sideLength;
    }

    override func simpleDescription() -> String {
        return "A square with sides of length \(sideLength). ";
    }
}

/* SubClass Square print info */
let test = Square(sideLength: 5.2, name: "my test square");
print(test.area());
print(test.simpleDescription());


/* SubClass Circle */
class Circle: NamedShape {
    var radius: Double;

    init(radius: Double, name: String) {
        self.radius = radius;
        super.init(name: name);
        numberOfSides = 1;
    }

    func area() -> Double {
        return (Double.pi * sqrt(radius));
    }

    override func simpleDescription() -> String {
        return "A circle with radius \(radius). ";
    }
}

/* SubClass Circle print info */
let myCircle = Circle(radius: 2.0, name: "my test circle");
print(myCircle.area());
print(myCircle.simpleDescription());

/* SubClass EquilateralTriangle */
class EquilateralTriangle: NamedShape {
    var sideLength: Double = 0.0;

    init(sideLength: Double, name: String) {
        self.sideLength = sideLength;
        super.init(name: name);
        numberOfSides = 3;
    }

    var perimeter: Double {
        get {
            return 3.0 * sideLength;
        }
        set {
            sideLength = newValue / 3.0;
        }
    }

    override func simpleDescription() -> String {
        return "An equilateral triangle with sides of length \(sideLength)";
    }
}

/* SubClass EquilateralTriangle print info */
var triangle = EquilateralTriangle(sideLength: 3.1, name: "a triangle");
print(triangle.perimeter);
triangle.perimeter = 9.9;
print(triangle.sideLength);

/* SuperClass TriangleAndSquare */
class TriangleAndSquare {
    var triangle: EquilateralTriangle {
        willSet {
            square.sideLength = newValue.sideLength;
        }
    }

    var square: Square {
        willSet {
            triangle.sideLength = newValue.sideLength;
        }
    }

    init(size: Double, name: String) {
        square = Square(sideLength: size, name: name);
        triangle = EquilateralTriangle(sideLength: size, name: name);
    }
}

/* SuperClass TriangleAndSquare print info */
var triangleAndSquare = TriangleAndSquare(size: 10, name: "another test shape");
print(triangleAndSquare.square.sideLength);
print(triangleAndSquare.triangle.sideLength);

triangleAndSquare.square = Square(sideLength: 50, name: "larger square");
print(triangleAndSquare.triangle.sideLength);

let optionalSquare: Square? = Square(sideLength: 2.5, name: "optional square");   // optional constant
let sideLength = optionalSquare?.sideLength;   // write a '?' before a method


