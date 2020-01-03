#[allow(unused_imports)]
#[allow(unused_variables)]
#[allow(dead_code)]
mod flight;
mod user;
use std::fs::OpenOptions;
use std::io::BufReader;
use std::io::prelude::*;
use std::io::BufRead;
use std::collections::HashMap;
use std::io::stdin;
use std::path::Path;

fn make_flights(file : &std::fs::File) -> HashMap<u32, flight::Flight> {
    let buf = BufReader::new(file);
    let mut flightpool = HashMap::new();
    for i in buf.lines() {
        let line = i.unwrap();
        let mut flight = flight::Flight::from(line);
        if flightpool.contains_key(&flight.get_id()) {
            panic!("Duplicate in flight IDs found!");
        }
        flightpool.insert(flight.get_id(), flight);
    }
    flightpool
}
pub fn load_users(map: &mut HashMap<u32,flight::Flight>, file : &std::fs::OpenOptions) -> Result<String,String> {
    
}
fn main() {
    //Path relative to target directory
    let users_file = Path::new("../../textfiles/data.txt");
    let flights_file = Path::new("../../textfiles/flights.txt");
    let users = OpenOptions::new().read(true).open(users_file).unwrap(); 
    let flights = OpenOptions::new().read(true).open(flights_file).unwrap();

}
