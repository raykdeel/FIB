## ===================================
## Probabilitat i Estadística, Grup 20
## Clase de laboratorio 2: 6.10.2020
## Análisis descriptivo bivariado
## ===================================

## Apartado 1
## ----------
? state
View(state.x77)
str(state.x77)
state.region
state77 <- data.frame(state.x77, state.region)
head(state77)
summary(state77)
names(state77)[c(4, 6, 9)] <- c("LifeExp", "HSGrade", "Region")
names(state77)


## Apartado 2
## ----------
windows(height = 10, width = 10)
par(las = 1)
pairs(state77[, 1:8], pch = 16)

windows(height = 6, width = 18)
par(mfrow = c(1, 3), las = 1, font.lab = 2, font.axis = 3, cex.lab = 1.4,
    cex.axis = 1.3)
with(state77, plot(Illiteracy, LifeExp, pch = 15, col = 2, cex = 1.5))
with(state77, plot(Illiteracy ~ Income, pch = 16, col = 3, cex = 1.5))
plot(LifeExp ~ Frost, data = state77, pch = 17, col = 4,
     ylab = "Life expectancy", cex = 1.5)


## Apartado 3
## ----------
cor(state77)
round(cor(state77[, 1:8]), 3)
with(state77, round(cor(Area, Illiteracy), 3))
with(state77, round(cor(LifeExp, Illiteracy), 3))


## Apartado 4
## ----------
cut(state77$Income, c(0, 4000, 4500, 5000, 10000))
state77$Income.cat <- cut(state77$Income, c(0, 4000, 4500, 5000, 10000),
                          labels = c("<= 4000", "4001--4500", "4501--5000",
                                     "> 5000"))
head(state77, 10)


## Apartado 5
## ----------
with(state77, table(Region, Income.cat))
# install.packages("descr")  # nom?s si no est? instal?lat el paquet
library(descr)
with(state77, CrossTable(Region, Income.cat, prop.c = FALSE, prop.t = FALSE,
                         prop.chisq = FALSE, format = "SPSS"))


## Apartado 6
## ----------
windows()
par(las = 1, font.lab = 2, font.axis = 2)
mosaicplot(Region ~ Income.cat, data = state77, col = 1:4, ylab = "Income",
           main = "Income per region")

