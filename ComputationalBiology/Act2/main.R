# install.packages("stringr")
library(stringr)
nuevos_pacientes <- read.csv("E:/Code/school/ComputationalBiology/Act2/NUEVO_INGRESO.csv")
# Revisa si los datos cargados son del tipo DataFrame
ans <- "no"
if (is.data.frame(nuevos_pacientes)) {
    ans <-"si"
} 
print(paste("El archivo ", ans, " es DataFrame\n"));
cat(paste("Observaciones: ", nrow(nuevos_pacientes)),"\n")
cat(paste("Variables: ", nrow(nuevos_pacientes) * ncol(nuevos_pacientes)),"\n")
enfermedades <- unique(nuevos_pacientes$DESCRIPCION.DIAGNOSTICO)
relevantes <- vector()
counter <- 0
# filtrado para obtener solamente los padecimientos oncológicos
for(str in enfermedades) {
    if (str_detect(str,"OMA") || str_detect(str, "TUMOR") || str_detect(str, "HODGKIN")) {
        counter <- counter + 1;
        relevantes[counter] <- str
    }
}
cat(paste("Numero de padecimientos oncologicos: ", length(relevantes)),"\n")

# Obtenemos los estados con mayor cantidad de incidencias 
top10estados <- tail(names(sort(table(nuevos_pacientes$ESTADO))), 10)
top10ciudades <- tail(names(sort(table(nuevos_pacientes$MUNICIPIO))), 10)
cat(paste("Estados con mayores incidencias: \n"))
print(top10estados)
cat(paste("Ciudades con mayores incidencias: \n"))
print(top10ciudades)

