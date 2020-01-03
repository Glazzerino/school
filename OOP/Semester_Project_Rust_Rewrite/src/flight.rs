use crate::user::User;
use std::io::BufReader;
use std::io::BufRead;
#[derive(Clone,Default)]
pub struct Flight {
    users: Vec<User>,
    destiny: String,
    origin: String,
    hour: String,
    duration: String,
    minutes: String,
    id: u32,
}

impl Flight {
    pub fn new(id: u32) -> Self {
        Flight {
            id: id,
            ..Default::default()
        }
    }
    pub fn from(line : String) -> Self {
        let data = line.split_whitespace();     
        let data: Vec<String> = data.map(|x| x.to_string()).collect();
        Flight {
            origin: data[0],
            destiny: data[1],
            duration : data[2],
            id: data[3].parse::<u32>().unwrap(),
            hour : data[4],
            minutes: data[5],
            ..Default::default()
        }   
    }
    pub fn get_users(self: &Self) -> Vec<User> {
        self.users.clone()
    }
    pub fn get_id(self: &Self) -> u32 {
        self.id
    }
    pub fn add_user(self: &mut Self, new_user: User) -> Result<bool, String> {
        for i in &self.users {
            if i.getId() == new_user.getId() {
                return Err("Error: Duplicate found!".to_string());
            }
        }
        if new_user.getFlightId() == self.get_id() {
            self.users.push(new_user);
        } else {
            return Err("User skipped; flight ID mismatch".to_string());
        }
        Ok(true)
    }
    // pub fn load_users(self: &mut Self, file: &std::fs::File) -> Result<bool, String> {
    //     let bufread = BufReader::new(file);
    //     for line in bufread.lines() {
    //         let new_user = User::from(line.unwrap())?;
    //         self.add_user(new_user)?;
    //     }
    //     return Ok(true);
    // }
    pub fn show_users(self: &Self) {
        println!("Passengers with flight id no. {}", self.get_id());
        for i in &self.users {
            println!("Name: {} | Origin: {} | Destination: {} | ID: {} |",
            i.getName(),i.getOrigin(),i.getDestiny(), i.getId());
        }
    }
    
}
