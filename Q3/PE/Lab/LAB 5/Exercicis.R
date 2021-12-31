n <- 3
p <- 0.7
par(mfrow = c(1, 2))
plot(0:n, dbinom(0:n, n, p),type = "h", main = "Funció de probabilitat")
plot(0:n, pbinom(0:n, n, p),type = "s", main = "Funció de distribució")
1-pbinom(1,3,0.7)


lambda <- 4
xmax <- qpois(0.99, lambda) # Valor fins on arriba el gràfic
par(mfrow = c(1, 2))
plot(0:xmax, dpois(0:xmax, lambda), type = "h", main = "Funció de probabilitat")
plot(0:xmax, ppois(0:xmax, lambda), type = "s", main = "Funció de distribució")

dpois(0, 2)
1-dpois(2, 2)
1-dpois(3, 2)

ppois(0.9, 2)
n <- 100
p <- 0.05
lambda <- n * p
xmax <- qpois(0.99, lambda)
par(mfrow = c(1, 1))
plot(0:xmax - 0.1, dbinom(0:xmax, n, p), type = "h", main = "Funció de probabilitat")
points(0:xmax + 0.1, dpois(0:xmax, lambda), type = "h", col = "red")

pbinom(3, 100, 0.02)
ppois(3, 2)

lambda <- 10
xmax <- qexp(0.99, lambda)
par(mfrow = c(1, 2))
curve(dexp(x, lambda), 0, xmax, main = "Funció de densitat")
curve(pexp(x, lambda), 0, xmax, main = "Funció de distribució")


1-pexp(0.25,4)
pexp(1,4)
pexp(0.25,4)

pnorm(3.5,5,1.5)




