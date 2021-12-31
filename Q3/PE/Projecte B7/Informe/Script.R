Este <- read.csv("C:/Users/rguix/Desktop/Este.csv", header=FALSE)
Oeste <- read.csv("C:/Users/rguix/Desktop/Oeste.csv", header=FALSE)

#ANÀLISI DESCRIPTIU

#ESTE

Bulgaria <- data.frame(Este[Este$V3 == "Bulgaria", 2]); colnames(Bulgaria)<- c("Idioma")
siBulgaria <- length(Bulgaria[Bulgaria$Idioma == "s bulgaro", ])
diffBulgaria = length(unique(Bulgaria)$Idioma)

Rusia <- data.frame(Este[Este$V4 == "Rusia", 2]); colnames(Rusia)<- c("Idioma")
siRusia <- length(Rusia[Rusia$Idioma == "s ruso", ])
diffRusia = length(unique(Rusia)$Idioma)

Ucrania <- data.frame(Este[Este$V5 == "Ucrania", 2]); colnames(Ucrania)<- c("Idioma")
siUcrania <- length(Ucrania[Ucrania$Idioma == "s ucraniano", ])
diffUcrania = length(unique(Ucrania)$Idioma)

Eslovaquia <- data.frame(Este[Este$V6 == "Eslovaquia", 2]); colnames(Eslovaquia)<- c("Idioma")
siEslovaquia <- length(Eslovaquia[Eslovaquia$Idioma == "s eslovaco", ])
diffEslovaquia = length(unique(Eslovaquia)$Idioma)

Rumania <- data.frame(Este[Este$V7 == "Rumania", 2]); colnames(Rumania)<- c("Idioma")
siRumania <- length(Rumania[Rumania$Idioma == "s rumano", ])
diffRumania = length(unique(Rumania)$Idioma)


Hungria <- data.frame(Este[Este$V8 == "Hungria", 2]); colnames(Hungria)<- c("Idioma")
siHungria <- length(Hungria[Hungria$Idioma == "s hungaro", ])
diffHungria = length(unique(Hungria)$Idioma)

Polonia <- data.frame(Este[Este$V9 == "Polonia", 2]); colnames(Polonia)<- c("Idioma")
siPolonia <- length(Polonia[Polonia$Idioma == "s polaco", ])
diffPolonia = length(unique(Polonia)$Idioma)

RepCheca <- data.frame(Este[Este$V10 == "Republica Checa", 2]); colnames(RepCheca)<- c("Idioma")
siRepCheca <- length(RepCheca[RepCheca$Idioma == "s checo", ])
diffRepCheca = length(unique(RepCheca)$Idioma)

Letonia <- data.frame(Este[Este$V11 == "Letonia", 2]); colnames(Letonia)<- c("Idioma")
siLetonia <- length(Letonia[Letonia$Idioma == "s leton", ])
diffLetonia = length(unique(Letonia)$Idioma)

Lituania <- data.frame(Este[Este$V12 == "Lituania", 2]); colnames(Lituania)<- c("Idioma")
siLituania <- length(Lituania[Lituania$Idioma == "s lituano", ])
diffLituania = length(unique(Lituania)$Idioma)

Estonia <- data.frame(Este[Este$V13 == "Estonia", 2]); colnames(Estonia)<- c("Idioma")
siEstonia <- length(Estonia[Estonia$Idioma == "s estonio", ])
diffEstonia = length(unique(Estonia)$Idioma)


#OESTE

Alemania <- data.frame(Oeste[Oeste$V4 == "Alemania", 2]); colnames(Alemania)<- c("Idioma")
siAlemania <- length(Alemania[Alemania$Idioma == "s aleman", ])
diffAlemania = length(unique(Alemania)$Idioma)

Austria <- data.frame(Oeste[Oeste$V5 == "Austria", 2]); colnames(Austria)<- c("Idioma")
siAustria <- length(Austria[Austria$Idioma == "s aleman", ])
diffAustria = length(unique(Austria)$Idioma)

Belgica <- data.frame(Oeste[Oeste$V6 == "Belgica", 2]); colnames(Belgica)<- c("Idioma")
siBelgica <- length(Belgica[Belgica$Idioma == "s frances", ]) + length(Belgica[Belgica$Idioma == "s neerlandes", ]) + length(Belgica[Belgica$Idioma == "s aleman", ])
diffBelgica = length(unique(Belgica)$Idioma)

Dinamarca <- data.frame(Oeste[Oeste$V7 == "Dinamarca", 2]); colnames(Dinamarca)<- c("Idioma")
siDinamarca <- length(Dinamarca[Dinamarca$Idioma == "s danes", ])
diffDinamarca = length(unique(Dinamarca)$Idioma)

España <- data.frame(Oeste[Oeste$V8 == "esp", 2]); colnames(España)<- c("Idioma")
siEspaña <- length(España[España$Idioma == "s español", ])
diffEspaña = length(unique(España)$Idioma)

Finlandia <- data.frame(Oeste[Oeste$V9 == "Finlandia", 2]); colnames(Finlandia)<- c("Idioma")
siFinlandia <- length(Finlandia[Finlandia$Idioma == "s finlandes", ])
diffFinlandia = length(unique(Finlandia)$Idioma)

Francia <- data.frame(Oeste[Oeste$V10 == "Francia", 2]); colnames(Francia)<- c("Idioma")
siFrancia <- length(Francia[Francia$Idioma == "s frances", ])
diffFrancia = length(unique(Francia)$Idioma)

Grecia <- data.frame(Oeste[Oeste$V11 == "Grecia", 2]); colnames(Grecia)<- c("Idioma")
siGrecia <- length(Grecia[Grecia$Idioma == "s griego", ])
diffGrecia = length(unique(Grecia)$Idioma)

Irlanda <- data.frame(Oeste[Oeste$V12 == "Irlanda", 2]); colnames(Irlanda)<- c("Idioma")
siIrlanda <- length(Irlanda[Irlanda$Idioma == "s ingles", ])
diffIrlanda = length(unique(Irlanda)$Idioma)

Islandia <- data.frame(Oeste[Oeste$V13 == "Islandia", 2]); colnames(Islandia)<- c("Idioma")
siIslandia <- length(Islandia[Islandia$Idioma == "s islandes", ])
diffIslandia = length(unique(Islandia)$Idioma)

Italia <- data.frame(Oeste[Oeste$V14 == "Italia", 2]); colnames(Italia)<- c("Idioma")
siItalia <- length(Italia[Italia$Idioma == "s italiano", ])
diffItalia = length(unique(Italia)$Idioma)

Luxemburgo <- data.frame(Oeste[Oeste$V20 == "Luxemburgo", 2]); colnames(Luxemburgo)<- c("Idioma")
siLuxemburgo <- length(Luxemburgo[Luxemburgo$Idioma == "s aleman", ]) + length(Luxemburgo[Luxemburgo$Idioma == "s frances", ])
diffLuxemburgo = length(unique(Luxemburgo)$Idioma)

Noruega <- data.frame(Oeste[Oeste$V15 == "Noruega", 2]); colnames(Noruega)<- c("Idioma")
siNoruega <- length(Noruega[Noruega$Idioma == "s noruego", ])
diffNoruega = length(unique(Noruega)$Idioma)

PaisesBajos <- data.frame(Oeste[Oeste$V16 == "Paises Bajos", 2]); colnames(PaisesBajos)<- c("Idioma")
siPaisesBajos <- length(PaisesBajos[PaisesBajos$Idioma == "s neerlandes", ])
diffPaisesBajos = length(unique(PaisesBajos)$Idioma)

Portugal <- data.frame(Oeste[Oeste$V3 == "Portugal", 2]); colnames(Portugal)<- c("Idioma")
siPortugal <- length(Portugal[Portugal$Idioma == "s portugues", ])
diffPortugal = length(unique(Portugal)$Idioma)

ReinoUnido <- data.frame(Oeste[Oeste$V17 == "Reino Unido", 2]); colnames(ReinoUnido)<- c("Idioma")
siReinoUnido <- length(ReinoUnido[ReinoUnido$Idioma == "s ingles", ])
diffReinoUnido = length(unique(ReinoUnido)$Idioma)

Suecia <- data.frame(Oeste[Oeste$V18 == "Suecia", 2]); colnames(Suecia)<- c("Idioma")
siSuecia <- length(Suecia[Suecia$Idioma == "s sueco", ])
diffSuecia = length(unique(Suecia)$Idioma)

Suiza <- data.frame(Oeste[Oeste$V19 == "Suiza", 2]); colnames(Suiza)<- c("Idioma")
siSuiza <- length(Suiza[Suiza$Idioma == "s aleman", ]) + length(Suiza[Suiza$Idioma == "s frances", ]) + length(Suiza[Suiza$Idioma == "s italiano", ])
diffSuiza = length(unique(Suiza)$Idioma)



#RESULTOSxd

#ESTE
siEste = c(siBulgaria,siEslovaquia,siEstonia,siHungria,siLetonia,siLituania,siPolonia,siRepCheca,siRumania,siRusia,siUcrania)
diffEste = c(diffBulgaria,diffEslovaquia,diffEstonia,diffHungria,diffLetonia,diffLituania,diffPolonia,diffRepCheca,diffRumania,diffRusia,diffUcrania)

summary(siEste); sd(siEste) #desviación típica
summary(diffEste); sd(diffEste)

hist(siEste, main = "Histograma Canciones lengua oficial Europa Este")
hist(diffEste, main = "Histograma Idiomas diferentes Europa Este")

#OESTE
siOeste = c(siAlemania,siAustria,siBelgica,siDinamarca,siEspaña,siFinlandia,siFrancia,siGrecia,siIrlanda,siIslandia,
            siItalia,siLuxemburgo,siNoruega,siPaisesBajos,siPortugal,siReinoUnido,siSuecia,siSuiza)
diffOeste = c(diffAlemania,diffAustria,diffBelgica,diffDinamarca,diffEspaña,diffFinlandia,diffFrancia,diffGrecia,diffIrlanda,diffIslandia,
              diffItalia,diffLuxemburgo,diffNoruega,diffPaisesBajos,diffPortugal,diffReinoUnido,diffSuecia,diffSuiza)

summary(siOeste); sd(siOeste) ##desviación típica
summary(diffOeste); sd(diffOeste)

hist(siOeste, main = "Histograma Canciones lengua oficial Europa Oeste")
hist(diffOeste, main = "Histograma Idiomas diferentes Europa Oeste")

#ESTE vs OESTE

boxplot(siEste,siOeste, main = "BoxPlot Este/Oeste",col = "darkgrey", names = c("Este", "Oeste"), ylab = "Canciones en la lengua oficial")

boxplot(diffEste,diffOeste, main = "BoxPlot Este/Oeste",col = "darkgrey", names = c("Este", "Oeste"), ylab = "Cantidad de idiomas")


#ANÀLISI INFERENCIAL
n1 = length(siOeste);n1
n2 = length(siEste);n2
sd1 = sd(siOeste);sd1
sd2 = sd(siEste);sd2
var1 = var(siOeste);var1
var2 = var(siEste);var2


s2 = (((n1-1)*sd1^2)+((n2-1)*sd2^2))/(n1+n2-2);s2
s = sqrt(s2);s
se = s*sqrt((1/n1)+(1/n2));se

t = (mean(siOeste)-mean(siEste))/se;t

#T.TEST

t.test(siOeste, siEste, alternative = "greater", var.equal = TRUE)

qt(0.975,27)


#RELACION CANTIDAD IDIOMAS/CANCIONES

CancionesLenguaOficial = c(siOeste, siEste)
CantidadIdiomas = c(diffOeste, diffEste)
n = length(CancionesLenguaOficial)
muy = mean(CancionesLenguaOficial)
muz = mean(CantidadIdiomas)
sdy = sd(CancionesLenguaOficial)
sdz = sd(CantidadIdiomas)
syz = ((sum(CancionesLenguaOficial*CantidadIdiomas)-sum(CancionesLenguaOficial)*sum(CantidadIdiomas))/n)/(n-1)
r = syz/(sdy*sdz);r
b1 = syz/sdy^2;b1
b0 = muy-b1*muz;b0
lm(CancionesLenguaOficial~CantidadIdiomas)
mod = lm(CancionesLenguaOficial~CantidadIdiomas)
summary(mod)

par(cex.lab=1.2,cex.axis=1.2,las=1,font.lab=2,font.axis=3)
plot(CancionesLenguaOficial~CantidadIdiomas,pch=19,col=8,cex=1.2)
abline(mod,col=2,lwd=3)







abline(lm((totaly)~(totalz)))

