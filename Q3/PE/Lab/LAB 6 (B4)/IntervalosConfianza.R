## =====================================
## Probabilitat i Estadística
## Grupo 20, Bloque 4, 17.11.2020
## Intervalos de confianza para la media
## =====================================

## Función de densidad de una N(1000, 10)
## ======================================
windows(width = 10)
par(font.lab = 4, font.axis = 2, las = 1, font = 2)
curve(dnorm(x, 1000, 10), from = 970, to = 1030, lwd = 4, xlab = "X",
      ylab = "f(t)")
segments(qnorm(0.025, 1000, 10), 0, qnorm(0.025, 1000, 10),
         dnorm(qnorm(0.025, 1000, 10), 1000, 10), lwd = 4)
segments(qnorm(0.975, 1000, 10), 0, qnorm(0.975, 1000, 10),
         dnorm(qnorm(0.975, 1000, 10), 1000, 10), lwd = 4)
text(978, 0.0015, "2.5%", cex = 1)
text(1022, 0.0015, "2.5%", cex = 1)
text(1000, 0.02, "95%", cex = 2)
title("Función de densidad de una distribución N(1000, 10)")


## Función de densidad de la media de 100
## variables aleatorias con dist. N(1000, 10)
## ==========================================
windows(width = 10, height = 10)
par(mfrow = c(2, 1), font.lab = 4, font.axis = 2, las = 1)
curve(dnorm(x, 1000, 10), from = 970, to = 1030, lwd = 4, xlab = "X",
      ylab = "f(t)")
segments(qnorm(0.025, 1000, 10), 0, qnorm(0.025, 1000, 10),
         dnorm(qnorm(0.025, 1000, 10), 1000, 10), lwd = 4)
segments(qnorm(0.975, 1000, 10), 0, qnorm(0.975, 1000, 10),
         dnorm(qnorm(0.975, 1000, 10), 1000, 10), lwd = 4)
text(1000, 0.02, "95%", cex = 2)
title("Función de densidad de una distribución N(1000, 10)")
axis(1, at = 995, cex = 1, col.axis = "red", lwd = 3, col.ticks = 2)
plot(seq(970, 1030, 0.1), dnorm(seq(970, 1030, 0.1), 1000, 1), type = "l",
     xlab = "X", ylab = "f(t)", lwd = 3)
segments(qnorm(0.025, 1000, 1), 0, qnorm(0.025, 1000, 1),
         dnorm(qnorm(0.025, 1000, 1), 1000, 1), lwd = 3, col.ticks = 5)
segments(qnorm(0.975, 1000, 1), 0, qnorm(0.975, 1000, 1),
         dnorm(qnorm(0.975, 1000, 1), 1000, 1), lwd = 3, col.ticks = 5)
text(1000, 0.1, "95%", cex = 1)
title("Función de densidad de una distribución N(1000, 1)")
axis(1, at = 995, cex = 1, col.axis = "red", col.ticks = 2, lwd = 3)


## Ilustración de intervalos de confianza
## ======================================
# install.packages("TeachingDemos")
library(TeachingDemos)
windows(width = 10)
par(las = 1, font.lab = 2, font.axis = 2, font = 2)
ci.examp(1000, 10, 100)
windows(width = 10)
par(las = 1, font.lab = 2, font.axis = 2, font = 2)
ci.examp(1000, 10, 100, conf.level = 0.99)


## ¿Cuál es el intervalo de confianza de la variable
## "Horas de deporte semanales" en estudiantes de la FIB?
## ------------------------------------------------------
load("Grupo20.RData")
summary(grup20)
mean(grup20$Esport)
sd(grup20$Esport)

windows(width = 9)
par(las = 1, font.lab = 2, font.axis = 3)
hist(grup20$Esport, breaks = 15, col = "steelblue", xlab = "Hours",
     main = "PE, Group 20: Hours per week dedicated to (active) sports")



## La distribución t (de Student)
## ==============================
# X1, ..., X10 ~ N(1000, 10)
# ¿Cuál es la distribucíón de (Xn - mu) / (s / sqrt(n))?
set.seed(1711)
x10matrix <- matrix(rnorm(10 * 100000, 1000, 10), nc = 100000)
xmean10 <- colMeans(x10matrix)
sdmean10 <- apply(x10matrix, 2, sd)
tsample <- (xmean10 - 1000)/(sdmean10 / sqrt(10))

windows(width = 10)
par(las = 1, font.axis = 2, font.lab = 4)
hist(tsample, breaks = 100, freq = FALSE,
     main = "A sample of size 100000 from a t distribution", xlab = "", col.axis="green")
curve(dnorm(x), from = -5, to = 5, lwd = 2, add = T)

## Varias distribuciones t
## -----------------------
windows(width = 10)
par(font = 2, font.lab = 2, las = 1, font.axis = 4)
curve(dnorm(x), from = -4, to = 4, lwd = 2, xlab = "X", ylab = "f(t)")
curve(dt(x, 2), from = -4, to = 4, lwd = 2, col = 4, add = T)
curve(dt(x, 10), from = -4, to = 4, lwd = 2, col = 3, add = T)
curve(dt(x, 30), from = -4, to = 4, lwd = 2, col = 2, add = T)
legend("topleft", c("Standard Normal", paste("t distribution:", c(30, 10, 2),
                                             "d.f.")),
       lwd = 2, col = 1:4, bty = "n")
title("Density functions of several t distributions")


## El intervalo de confianza para mu en caso que sigma sea desconocida
## ===================================================================
mu <- mean(grup20$Esport)
si <- sd(grup20$Esport)
en <- sum(complete.cases(grup20$Esport))
## Cálculo a mano (IC del 95%)
round(mu + qt(c(0.025,0.975), en-1) * si / sqrt(en), 3)
t.test(grup20$Esport)
round(t.test(grup20$Esport)$conf.int, 3)

## IC del 90%
round(t.test(grup20$Esport, conf.level = 0.9)$conf.int, 3)

round(mu + qnorm(0.95)*si/sqrt(en),3)
##IC(u,0.95) X("mean(vector)") = 5
n <- 9;
sigma <- 1;
l1 <- 5 - qnorm(0.995)*sigma/sqrt(n) ## 5 = mean(nterm)
l2 <- 5 + qnorm(0.995)*sigma/sqrt(n)
