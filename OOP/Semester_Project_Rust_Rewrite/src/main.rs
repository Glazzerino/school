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
        println!("{}", &flight.get_id());
        flightpool.insert(flight.get_id(), flight);
    }
    flightpool
}
pub fn load_users(map: &mut HashMap<u32,flight::Flight>, file: &std::fs::File) -> Result<String,String> {
    let buf = BufReader::new(file);
    for i in buf.lines() {
        let line = i.unwrap();
        let user = user::User::from(line.clone())?;
        let mut ctx = map.get_mut(&user.getFlightId());
        if ctx.is_none() {
            return Err("flight ID does not match any ID".to_string());
        } else {
            ctx.unwrap().add_user(user);
        }
    }
    Ok("Users loaded".to_string())
}
fn main() {
    //Path relative to target directory
    let users_file = Path::new("../../textfiles/data.txt");
    let flights_file = Path::new("../../textfiles/flights.txt");
    let users = OpenOptions::new().read(true).open(users_file).unwrap(); 
    let flights = OpenOptions::new().read(true).open(flights_file).unwrap();
    let mut flight_pool = make_flights(&flights);
    for i in flight_pool.values() {
        println!("Flight with number: {}", i.get_id());
    }
    match load_users(&mut flight_pool, &users) {
        Ok(o) => println!("{}",o),
        Err(e) => panic!(e),
    }
    for i in flight_pool.values() {
        i.show_users();
    }
}
