## ==========================================
## Probabilitat i Estadística, Grup 20
## Clase de laboratorio 2: 6.10.2020
## Análisis descriptivo bivariado: Soluciones
## ==========================================

## 1. Cargar el área de trabajo Grupo20.RData. ¿Qué objetos contiene?
## ------------------------------------------------------------------
load("Grupo20.RData")
ls()
class(grup20)
summary(grup20)


## 2. Dibujar gráficos de dispersión de la variable Pols versus
##    horas de deporte semanales y Pols versos altura.
##    ¿Se observa alguna relación? ¿Cuáles son los valores de las correlaciones?
## -----------------------------------------------------------------------------
windows(width = 12)
par(mfrow = 1:2, las = 1, font.lab = 2, font.axis = 2)
plot(Pols ~ Esport, data = grup20, pch = 19, xlab = "Horas de deporte",
     ylab = "Pulsaciones por minuto", cex = 1.5)
title("Pulso en función de la actividad deportiva")
plot(Pols ~ Altura, data = grup20, pch = 19, xlab = "Altura [cm]",
     ylab = "Pulsaciones por minuto", cex = 1.5)
title("Pulso en función de la altura")

with(grup20, cor(Pols, Esport))
with(grup20, cor(Pols, Altura, use = "complete.obs"))


## 3. Estudiar la relación entre las variables Windows y Futbol mediante una
##    tabla de contingencia y un gráfico de mosaicos. ¿Qué observáis?
## -------------------------------------------------------------------------
library(descr)
with(grup20, CrossTable(...))

windows()
par(las = 1, font.lab = 2, font.axis = 2)
mosaicplot(...)


## 4. Usar la función tapply para calcular la media y desviación
##    estándar de la variable Casa2FiB2 en función de la variable Barcelona.
## -------------------------------------------------------------------------
? tapply
