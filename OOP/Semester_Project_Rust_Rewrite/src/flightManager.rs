use crate::user::User;
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
    pub fn add_user(self: &mut Self, new_user: User) -> Result<bool, String> {
        for i in &self.users {
            if i.getId() == new_user.getId() {
                return Err(String::from("Duplicate found"));
            }
        }
        self.users.push(new_user);
        Ok(true)
    }
}
