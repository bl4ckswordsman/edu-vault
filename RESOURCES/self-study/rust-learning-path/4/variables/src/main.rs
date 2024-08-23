fn main() {
    // Declare a variable
    let a_number;

    // Declare a second variable and bind the value
    let a_word = "Ten";

    // Bind a value to the first variable
    a_number = 10;

    // Variables immutable by default, this gives comp err
    //a_number = 15;

    println!("The number is {}.", a_number);
    println!("The word is {}.", a_word);

    // The `mut` keyword lets the variable be changed
    let mut a_number_new = 10;
    println!("The number(mut) is {}.", a_number_new);

    // Change the value of an immutable variable
    a_number_new = 15;
    println!("Now the number(mut) is {}.", a_number_new);
}
