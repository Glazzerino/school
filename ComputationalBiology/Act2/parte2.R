db <- load("Multi_Cancer_Data.RData")
all <- as.data.frame(multi_cancer_data)
cancercols <- grepl("Tumor",colnames(all))
normal_cases <- grepl("Normal",colnames(all))
cancer <- all[cancercols]
print(all[normal_cases])


