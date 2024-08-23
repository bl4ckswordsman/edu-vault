fn main() {
    // todo!() macro is used to generate a compile-time error message.
    // Since it causes a panic, any code within the scope after it, will not run
    //todo!("Display the message by using println!() macro.");

    // println!() macro
    println!("Goodbye world!");

    // Call println! with three arguments: a string, a value, a value
    println!(
        "The first letter of the English alphabet is {} and the last letter is {}.",
        'A', 'Z'
    );
}
