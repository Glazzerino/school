#[allow(unused_imports)]
#[allow(unused_variables)]
#[allow(dead_code)]
mod flight;
mod user;
use std::fs::OpenOptions;
use std::io::BufReader;
use std::io::BufRead;
use std::io::stdin;
use std::path::Path;

fn main() {
    //Path relative to target directory
    let mut users_file = Path::new("../../textfiles/data.txt");
    let mut file = OpenOptions::new().read(true).open(users_file).unwrap(); 
    let mut flight = flight::Flight::new(12546);
    flight.load_users(&file);
    flight.show_users();
}
