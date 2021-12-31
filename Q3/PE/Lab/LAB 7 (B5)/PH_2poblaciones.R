## =========================================
## Probabilitat i Estadística
## Grupo 20, Bloque 5, 1.12.2020
## Pruebas de hipótesis para dos poblaciones
## =========================================

## Entre los estudiantes de la FIB,
## ¿practican más deporte los amantes del fútbol o no?
## ===================================================
## 1. Dibujar un boxplot que compare las horas de deporte en estudiantes
##    a los que les gusta el fútbol y a los que no.
## ---------------------------------------------------------------------
load("Grupo20.RData")
summary(grup20)

windows(width = 6)
par(las = 1, font.lab = 2, font.axis = 3)

boxplot(Esport ~ Futbol, grup20, col = 5:3, ylab = "Hores", xlab = "Futbol", pch = 16)
title("PE GRUP20 Esport-Futbol")


## 2. Contrastar la hipótesis que no hay relación entre las dos variables.
## -----------------------------------------------------------------------
t.test(Esport ~ Futbol, grup20, var.equal = TRUE)

## ¿Cuál es el intervalo de confianza de la diferencia de las medias del 90%?

t.test(Esport ~ Futbol, grup20, var.equal = TRUE, conf.level = 0.9)$conf.int


## 3. El ejemplo de las transparencias 31 y 32 del B5.
## ---------------------------------------------------
datos <- data.frame(A = c(23.05, 39.06, 21.72, 24.47, 28.56, 27.58),
                    B = c(20.91, 37.21, 19.29, 19.95, 25.32, 24.07))
datos

## Incorrecto:
t.test(datos$A, datos$B)

## Correcto:
t.test(datos$A, datos$B, paired = TRUE)

#file: AVÍS 22 NOV GRUP30
#EX1

#Bilateral

dataA <- c(10.5, 13, 15, 11, 10, 12.5, 11.5, 12, 10, 10.5)
dataB <- c(18.5, 13.5, 15, 17, 13.5, 16.5, 13.5, 14, 11, 15) 
dataA
dataB

n.dataA <- length(dataA)
n.dataB <- length(dataB)

#CÀLCUL S

s2 <- ((n.dataA-1)*var(dataA)+(n.dataB-1)*var(dataB))/(n.dataA+n.dataB-2)
s <- sqrt(s2);
s

#CÀLCUL ESTADÍSTIC

m.dataA <- mean(dataA)
m.dataB <- mean(dataB)
se <- (s*sqrt(1/n.dataA+1/n.dataB))
se
t<- (m.dataA-m.dataB)/se
t

#CÀLCUL P-VALOR

p.valor <- 2*pt(t,n.dataA+n.dataB-2)
p.valor

##Es pot rebutjar H0? Si pq p-valor inferior a 0.05 o pq estadistic menor q punt crític
gt(c(0.025),18)
#-2.100922

#CÀLCUL IC

IC.LI <- m.d - gt(0.975,9)*se
IC.LS <- m.d + gt(0.975,9)*se
IC.LI;IC.LS
#El IC(95%) va de -4.92 a -1.37

#EASY MODE
t.test(dataA, dataB, equal=TRUE)


#EX2

#Bilateral
#T-Estudent amb 9 graus de llibertat, MAS, mostra aparellada, normalitat de la diferència.

dataA <- c(10.5, 13, 15, 11, 10, 12.5, 11.5, 12, 10, 10.5)
dataB <- c(18.5, 13.5, 15, 17, 13.5, 16.5, 13.5, 14, 11, 15) 

#CÀLCUL ESTADÍSTIC

d <- dataB-dataA
m.d <- mean(d)
s.d <- sd(d)
se <- (s.d*sqrt(1/10))
t <- (m.d-0)/se
t

#CÀLCUL P-VALOR

p.valor <- 2*(1-pt(t,9))
p.valor

##Es pot rebutjar H0? Si pq p-valor inferior a 0.05 o pq estadistic superior q punt crític
gt(0.025,9)
#-2.100922

#CÀLCUL IC
IC.LI <- m.d - gt(0.975,9)*
IC.LS <- m.d - gt(0.975,9)*
IC.LI;IC.LS
#El IC(95%) va de -4.92 a -1.37

#EASY MODE
t.test(dataA, dataB, paired=TRUE)

  