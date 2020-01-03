#[derive(Clone)]
pub struct User {
    name: String,
    destiny: String,
    origin: String,
    id: u32,
    flight_id: u32,
}
#[allow(dead_code)]
impl User {
    pub fn new(name: String, id: u32) -> Self {
        User {
            name: name,
            destiny: String::from("default"),
            origin: String::from("default"),
            id: id,
            flight_id: 0,
        }
    }
    pub fn from(string: String) -> Result<Self,String> {
        //Silvia_Salazar MTY CDM 0982 9283
        let data: Vec<String> = string.split_whitespace().map(|x| x.to_string()).collect();
        if data.len() != 5 {
            let err_line = format!("Invalid line: Number of items must be 5 \n 
            dump: {}", string);
            return Err(err_line);
        } 
       let user = User {
            name: data[0].to_string(),
            destiny: data[1].to_string(),
            origin: data[2].to_string(),
            id: data[3].parse::<u32>().unwrap(),
            flight_id: data[4].parse::<u32>().unwrap(),
        };
        println!("USer from: {}", &user.getFlightId());
        Ok(user)
    }
    pub fn setDestiny(self: &mut Self, dest: String) {
        self.destiny = dest;
    }
    pub fn setName(self: &mut Self, name: String) {
        self.name = name;
    }
    pub fn setOrigin(self: &mut Self, origin: String) {
        self.origin = origin;
    }
    pub fn setId(self: &mut Self, id: u32) {
        self.id = id;
    }
    pub fn setFlightId(self: &mut Self, id: u32) {
        self.flight_id = id;
    }
    pub fn getFlightId(self: &Self) -> u32 {
        self.flight_id
    }
    pub fn getId(self: &Self) -> u32 {
        self.id
    }
    pub fn getName(self: &Self) -> String {
        self.name.clone()
    }
    pub fn getDestiny(self: &Self) -> String {
        self.destiny.clone()
    }
    pub fn getOrigin(self: &Self) -> String {
        self.origin.clone()
    }
}
