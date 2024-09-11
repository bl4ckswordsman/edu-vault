fn main() {
    if 1 == 2 {
        println!("True, the numbers are equal."); //
    } else {
        println!("False, the numbers are not equal.");
    }

    let formal = true;
    // if used here as an expression
    let greeting = if formal {
        "Good day to you." // return a String
    } else {
        "Hey!" // return a String
    };
    println!("{}", greeting); // prints "Good day to you."

    let num = 500; // num variable can be set at some point in the program
    let out_of_range: bool;
    if num < 0 {
        out_of_range = true;
    } else if num == 0 {
        out_of_range = true;
    } else if num > 512 {
        out_of_range = true;
    } else {
        out_of_range = false;
    }
}
