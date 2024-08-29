fn main() {
    // Declare array, initialize all values, compiler infers length = 7
    let days = [
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday",
        "Sunday",
    ];

    // Declare array, initialize all values to 0, length = 5
    let bytes = [0; 5];

    // Get the first day of the week
    let first = days[0];
    println!("The first day: {} \n", first);

    // Get the second day of the week
    let second = days[1];
    println!("The second day: {} \n", second);

    // Get the seventh day of the week using the wrong index - should be 6
    //let seventh = days[7];
}
