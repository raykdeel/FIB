## ==============================
## Probabilitat i Estadística
## Grupo 20, Bloque 3, 20.10.2020
## ==============================

## I. Representación gráfica de las funciones de probabilidad
##    y distribución de una distribución Binomial.
## ----------------------------------------------------------
# X~B(20, 0.5); Y~B(20, 0.8)
# Valores de X
k <- 0:20

# Valores de P(X = k) y P(X <= k)
px <- dbinom(k, 20, 0.5) #prob de q x=k si hi ha 20 elements i cada un te 0.5 chance
px[1]
fx <- pbinom(k, 20, 0.5)
r <- 0:18
R <- pbinom(r,18, 0.5)
R

P <- 0.5
E = sum(k*P)
E

# Valores de P(Y = k) y P(Y <= k)
py <- dbinom(k, 20, 0.8)
fy <- pbinom(k, 20, 0.8)

# Los 4 gráficos
# --------------
windows(width = 16, height = 12)
par(mfcol = c(2, 2), las = 1, font = 2, font.axis = 2, font.lab = 4)
plot(k, px, t = "h", ylim = c(0, 0.22), main = "X~B(20, 0.5)", xlab = "k",
     ylab = "P(X = k)", lwd = 2)
axis(1, at = k)
plot(k, py, t = "h", ylim = c(0, 0.22), main = "Y~B(20, 0.8)", xlab = "k",
     ylab = "P(Y = k)", lwd = 2)
axis(1, at = k)
plot(k, fx, t = "S", main = "X~B(20, 0.5)", xlab = "k",
     ylab = expression(bolditalic(P(X <= k))), lwd = 2)
axis(1, at = k)
plot(k, fy, t = "S", main = "Y~B(20, 0.8)", xlab = "k",
     ylab = expression(bolditalic(P(X <= k))), lwd = 2)
axis(1, at = k)


## II. Comparación de las distribuciones binomial y Poisson.
## ---------------------------------------------------------
# (i)  X1 ~ B(10, 0.5);  Y1 ~ Po(5)
# (ii) X2 ~ B(100, 0.1); Y2 ~ Po(10)

# Valores de P(X1 = k) y P(Y1 = k)
k1 <- 0:13
px1 <- dbinom(k1, 10, 0.5)
py1 <- dpois(k1, 5)

# Valores de P(X2 = k) y P(Y2 = k)
k2 <- 0:21
px2 <- dbinom(k2, 100, 0.1)
py2 <- dpois(k2, 10)

windows(width = 8, height = 10)
par(mfrow = c(2, 1), mar = c(5, 4, 1, 1), las = 1, font = 2, font.axis = 2,
    font.lab = 4)
plot(k1 - 0.08, px1, t = "h", ylim = c(0, 0.25), xlab = "k", ylab = "P(k)",
     lwd = 2)
points(k1 + 0.08, py1, t = "h", col = "red", lwd = 2)
legend("topright", c("B(10, 0.5)", "Po(5)"), lty = 1, col = c("black", "red"),
       lwd = 2, bty = "n")
plot(k2 - 0.08, px2, t = "h", ylim = c(0, 0.13), xlab = "k", ylab = "P(k)",
     lwd = 2)
points(k2 + 0.08, py2, t = "h", col = "red", lwd = 2)
legend("topright", c("B(100, 0.1)", "Po(10)"), lty = 1, col = c("black", "red"),
       lwd = 2, bty = "n")

# (iii)  X3 ~ B(250, 0.9);  Y1 ~ Po(225)
# (iv)   X4 ~ B(250, 0.1);  Y2 ~ Po(25)
windows(width = 12, height = 6)
par(mfrow = 1:2, las = 1, font = 2, font.lab = 4, font.axis = 3)
curve(pbinom(x, 250, 0.9), from = 190, to = 250, type = "s", lwd = 3,
      xlab = "k", ylab = "F(k)")
curve(ppois(x, 250 *.9), from = 190, to = 250, lwd = 3, col = 2,
      add = TRUE, type = "s")
title("Número de alumnos que aprueban el Parcial 1")
legend("topleft", c("Bin(250, 0.9)", "Poisson(225)"), col = 1:2, lwd = 3,
       bty = "n")

curve(pbinom(x, 250, 0.1), from = 0, to = 50, type = "s", lwd = 2,
      xlab = "k", ylab = "F(k)")
curve(ppois(x, 250 *.1), from = 0, to = 50, lwd = 2, col = 2,
      add = TRUE, type = "s")
title("Número de alumnos que suspenden el Parcial 1")
legend("topleft", c("Bin(250, 0.1)", "Poisson(25)"), col = 1:2, lwd = 3,
       bty = "n")



d <- 1:10
e <- dgeom(d,0.05, log = false)
e

y <- dgeom(10, prob=.05)
y

x <- 1:10
u <- dnbinom(10,3, 0.6, log=FALSE)
u
