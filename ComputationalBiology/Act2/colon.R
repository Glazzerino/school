
data <- read.csv("colon.csv")
print(data$ï..age)

mean_by_Paper <- data %>% 
  group_by(data$ï..age) %>% 
  summarize(averaged.ES = mean(selectedES.prepost))