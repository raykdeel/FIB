## ===================================
## Probabilitat i Estadística, Grup 20
## Clase de laboratorio 2: 29.9.2020
## Análisis descriptivo univariado
## ===================================

## 1. Importar los datos de Grup20.txt con la función read.table().
## ----------------------------------------------------------------
read.table("Grup20.txt", sep = "\t", na.strings = "", dec = ",")
grup20 <- read.table("Grup20.txt", sep = "\t", na.strings = "", dec = ",",header = TRUE)

## El objeto creado es un data frame:
class(grup20)

## Exploración de grup 20:
## -----------------------
str(grup20)
head(grup20)
summary(grup20)

## Alternativas para la importación de datos:
## ------------------------------------------
# grup20 <- read.delim("Grup20.txt", header = TRUE, na.strings = "", dec = ",")
# grup20 <- read.csv("Grup20.csv", na.strings = "", sep = ";")


## 2. Creación del subconjunto grup22:
## -----------------------------------
grup22 <- grup20[grup20$Grup == 22, ]
summary(grup22)

## Alternativa:
grup22 <- subset(grup20, Grup == 22)


## 3. ¿Cuáles son las medias, medianas y desviaciones estándar
##    de la edad y el tiempo desde la casa a la FIB?
## -----------------------------------------------------------
mean() ##edat = 20.19231, temps = 50.90385
median(...) ##edat = 19, temps = 40
sd(...) ##edat = 5.466613, temps = 26.45474
IQR(...) ##edat = 0.25, temps = 30
range(...) ##edat = 18 53, temps = 15 120


## 4. ¿Cuáles son la media, la mediana y la desviación estándar
##    de la altura?
## ------------------------------------------------------------
? mean



## 5. Histogramas de las variables Altura y Casa2Fib2.
##    ¿Qué observáis?
## ---------------------------------------------------
windows(width = 12)             # Usar quarz() en Mac o x11() en Linux.
par(las = 1, font.lab = 4, font.axis = 2)
hist(grup20$Altura, xlab = "Altura [cm]",
     main = "Histograma de la altura [Grupo 20]")
hist(grup20$Casa2Fib2, xlab = "Minutos",
     main = "Tiempo desde la casa a la FIB")

# Más colores:
colors()

## 6. Boxplots de las variables Altura y Casa2Fib2.
## ------------------------------------------------
windows(width = 12)
par(mfrow = 1:2, las = 1, font.lab = 2, font.axis = 2)
boxplot(grup20$Altura, ylab = "Altura [cm]",
        main = "Boxplot de la altura [Grupo 20]", col = 3)
boxplot(grup20$Casa2Fib2, ylab = "Minutos",
        main = "Boxplot del Tiempo desde la casa a la FIB", col = "steelblue")


## 7. Diagrama de barras de la variable Número de hermanos.
## --------------------------------------------------------
table(grup20$Germans)
windows()
par(mfrow = 1:2, las = 1, font.lab = 2, font.axis = 2)
barplot(grup20$Germans)


## 8. ¿Cuál es el porcentaje de los seguidores del Barça en el Grupo 20?
## ---------------------------------------------------------------------
# install.packages("descr")
library(descr)
freq(grup20$Equip, plot = FALSE) ##32.69%


## 9. Tabla de frecuencia de los meses de nacimiento.
## --------------------------------------------------
freq(grup20$Mes, plot = FALSE)
grup20$Mes <- freq(grup20$Mes, levels = c("Gener", "Febrer", "Març",
                                            "Abril", "Maig", "Juny",
                                            "Juliol", "Agost", "Setembre",
                                            "Octubre", "Novembre", "Desembre"))
freq(grup20$Mes)


## 10. Guardad el data frame "grup20" en un área de trabajo de R.
## --------------------------------------------------------------
