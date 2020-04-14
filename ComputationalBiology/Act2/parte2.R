
load("Multi_Cancer_Data.RData")
all <- as.data.frame(multi_cancer_data)
cancercols <- grepl("Tumor",colnames(all))
normal_cases <- all[grepl("Normal",colnames(all))]
cancer <- all[cancercols]
# Muestra de una linea de los casos normales
cat("Ejemplo de set con casos de cancer: \n")
print(format(cancer[1,1:3]))
# Muestra de una linea de casos tumorales
cat("//////////////////////////////////////\n")
cat("Ejemplo de set con casos normales: \n")
print(format(normal_cases[1,1:3]))

means_c <- mean(rowMeans(cancer))
means_n <- mean(rowMeans(normal_cases))
print(means_c - means_n)
means_breast <- colMeans(normal_cases[,grepl("Breast",colnames(cancer))])

#Promedio de expresion genetica de tejidos normales en la glandula mamaria
print(paste("Promedio de expresion genetica de tejidos normales en la glandula mamaria",mean(means_breast)))
#Promedio de expreison genetica de tejidos cancer
gaba_normal <- normal_cases["GABAa receptor alpha-3 subunit_A28102_at",]
gaba_cancer <- cancer["GABAa receptor alpha-3 subunit_A28102_at",]
print(paste("Expresion de GABAa en tejidos normales: ",mean(rowMeans(gaba_normal))))
print(paste("En tejidos con cancer: ", mean(rowMeans(gaba_cancer))))

#se calcula la diferencia entre los promedios de expresion 
# es ambos casos sobre la expresion del gen GABAa 
GABAa_colon_normal <- normal_cases["GABAa receptor alpha-3 subunit_A28102_at", grepl("Colo", colnames(gaba_normal))]
GABAa_colon_cancer <- cancer["GABAa receptor alpha-3 subunit_A28102_at", grepl("Tumor__Colorectal_", colnames(gaba_cancer))]
means_diff <- t.test(GABAa_colon_normal,GABAa_colon_cancer)
print("Prueba T de ambos sets: ")
print(means_diff)


