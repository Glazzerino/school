# install.packages("stringr")

# library(MASS)
nuevos_pacientes <- read.csv("E:/Code/school/ComputationalBiology/Act2/NUEVO_INGRESO.csv")
# Revisa si los datos cargados son del tipo DataFrame
ans <- "no"
if (is.data.frame(nuevos_pacientes)) {
    ans <-"si"
} 
print(paste("El archivo ", ans, " es DataFrame\n"));
cat(paste("Observaciones: ", nrow(nuevos_pacientes)),"\n")
cat(paste("Variables: ", nrow(nuevos_pacientes) * ncol(nuevos_pacientes)),"\n")
enfermedades <- levels(nuevos_pacientes$DESCRIPCION.DIAGNOSTICO)
cat(paste("Numero de padecimientos oncologicos: ", length(enfermedades)),"\n")

# Obtenemos los estados con mayor cantidad de incidencias 
print(levels(nuevos_pacientes$ESTADO))
cat(paste("Estados con mayores incidencias: \n"))
print(summary(nuevos_pacientes$ESTADO,10))
cat(paste("Ciudades con mayores incidencias: \n"))
print(summary(nuevos_pacientes$MUNICIPIO,10))
cat(paste("Cantidad de estados: ", length(unique(nuevos_pacientes$ESTADO)),"\n"))

# Despliegue de los primeros 6 pacientes

print(head(nuevos_pacientes,6))

