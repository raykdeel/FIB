## ==========================================
## Probabilitat i Estadística, Grup 20
## Clase de laboratorio 2: 6.10.2020
## Análisis descriptivo bivariado: Ejercicios
## ==========================================

## 1. Cargar el área de trabajo Grupo20.RData. ¿Qué objetos contiene?
## ------------------------------------------------------------------
load("Grupos20.RData")
ls()
class(grup20)
summary(grup20)


## 2. Estudiar la relación entre las variables Windows y Futbol mediante una
##    tabla de contingencia y un gráfico de mosaicos. ¿Qué observáis?
## -------------------------------------------------------------------------
library(descr)
with(grup20, CrossTable(SO, Futbol, prop.c = FALSE, prop.t = FALSE,
                        prop.chisq = FALSE, format = "SPSS")) ##?

windows()
par(las = 1, font.lab = 2, font.axis = 2)
mosaicplot(Windows ~ Futbol, data = grup20, col = 1:4, ylab = "Futbol",
           main = "Relación entre Windows y Futbol") #?


  ## 3. Usad la función tapply para calcular la media y desviación
##    estándar de la variable Casa2FiB2 en función de la variable Barcelona.
## -------------------------------------------------------------------------

tapply(grup20$Casa2Fib2, grup20$Barcelona, mean) #same
with(grup20, tapply(grup20$Casa2Fib2, grup20$Barcelona, mean))
tapply(grup20$Casa2Fib2, grup20$Barcelona, median)
tapply(grup20$Casa2Fib2, grup20$Barcelona, sd)
tapply(grup20$Casa2Fib2, grup20$Barcelona, IQR)
tapply(grup20$Casa2Fib2, grup20$Barcelona, range)

## 4. Dibujad gráficos de dispersión de Pols versus
##    horas de deporte semanales y Pols versos altura.
##    ¿Se observa alguna relación? ¿Cuáles son los valores de las correlaciones?


windows(height = 15, width = 15)
par(mfrow = c(1, 2), las = 1, font.lab = 2, font.axis = 3, cex.lab = 1,
    cex.axis = 1.3)
with(state77, plot(grup20$Pols, grup20$Esport, pch = 20, col = 5, cex = 1.5, ylab="Esport", xlab="Pols", main="Gràfic dispersió Pols - Esport"))
with(state77, plot(grup20$Pols, grup20$Altura, pch = 20, col = 5, cex = 1.5, ylab="Altura", xlab="Pols", main="Gràfic dispersió Pols - Altura"))

## -----------------------------------------------------------------------------
