use crate::user::User;
use std::io::BufReader;
use std::io::BufRead;
#[derive(Clone)]
pub struct Flight {
    users: Vec<User>,
    destiny: String,
    origin: String,
    id: u32,
}

impl Flight {
    pub fn new(id: u32) -> Self {
        Flight {
            users: Vec::new(),
            destiny: String::from("000"),
            origin: String::from("000"),
            id: id,
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
        self.users.push(new_user);
        Ok(true)
    }
    pub fn load_users(self: &mut Self, file: &std::fs::File) -> Result<bool, String> {
        let bufread = BufReader::new(file);
        for line in bufread.lines() {
            let new_user = User::from(line.unwrap())?;
            self.add_user(new_user);
        }
        return Ok(true);
    }
    pub fn show_users(self: &Self) {
        let mut j = 1;
        println!("Passengers with flight id no. {}", self.get_id());
        for i in &self.users {
            println!("Name: {} | Origin: {} | Destination: {} | ID: {} |",
            i.getName(),i.getOrigin(),i.getDestiny(), i.getId());
        }
    }
}
