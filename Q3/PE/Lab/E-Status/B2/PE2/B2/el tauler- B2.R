# Vector de probabilidades de la suma de dos dados regulares
# dices[i] = probabilidad de que dos dados regulares sumen i
dices <- c(0, 1/36, 2/36, 3/36, 4/36, 5/36, 6/36,
		5/36, 4/36, 3/36, 2/36, 1/36)


############################################################
# Pregunta 1
# En primer lloc, recordi?ns alguna cosa sobre la distribuci? de probabilitat
# de la suma de dos daus. Quina ?s la probabilitat que sigui $intervalo$? intervalo = 1:2 # Ejemplo
# sum(dices[intervalo])

#resposta pregunta 1:
t <- sum(dices[1:7])


###########################################################
# Datos del problema
# Introduce el tablero, 1 -> en blanco, probabilidad nula
data <- c(	7, 9, 2, 10, 1,
		1, 1, 1, 11, 1,
		1, 1, 1, 8, 4,
		12, 5, 1, 3, 6,
		1, 1, 1, 1, 1	)

# Creamos el tablero a partir de los datos
board = matrix(data, ncol=5, nrow=5, byrow=T)
show(board)
# 2. Respecte la funci? de probabilitat conjunta de T i G, es vol saber quines
# s?n les probabilitats que apareixen per a latitud $lat$.
# Escrigui tots els nombres (inclosos els zeros) separats per espais.
# Pot donar la resposta amb dos decimals, arrodonint el segon al nombre
# m?s proper.
lat = 1
t <- dices[board[3-lat,]]

#############################################################

# 3. La mateixa q?esti?, per? per a la longitud $lon$.
# Compte: poseu els n?meros per a longituds creixents (-2, -1, 0, ...)
lon = -2
t <-rev(dices[board[,lon+3]])

###########################################################
# 4. Trobi la funci? de probabilitat de la variable latitud.
# Ara, almenys tres decimals correctes. Com abans, separi els nombres
# amb espais.
p4 <- c(1:5)
for(i in 1:5)
	p4[i] = sum(dices[board[i,]])

T <- rev(p4)
T

# 4. Trobi la funci? de probabilitat de la variable longitud.
# Ara, almenys tres decimals correctes. Com abans, separi els nombres
# amb espais.
p4 <- c(5:1)
for(i in 1:5)
	p4[i] = sum(dices[board[,i]])

L <- p4
L


###########################################################
# 5. Suposem que a una jugada sabem que la fitxa es mou des de la casella
# central cap al Sud (inclosos moviments diagonals). Trobi la funci? de
# probabilitat de la variable G tenint en compte aquesta informaci?.
# Tres decimals de precisi? almenys.	

#cas sud#
pn = sum(dices[board[-1:-2,]])
p5 <- c(1:5)

for(j in 1:5)
	p5[j] = sum(dices[board[-2:-1,j]]) / pn

p5


0.2, 0.25, 0.55, 0, 0

#cas nord#
pn = sum(dices[board[1:2,]])
p5 <- c(1:5)
 
for(j in 1:5)
        p5[j] = sum(dices[board[1:2,j]]) / pn
 
p5

########################################################
# 6. Calculi el valor esperat del moviment d'una jugada,
# en el sentit de la latitud.	
G <- c(1:5)
for(j in 1:5)
	G[j] = sum(dices[board[j,]])

eG = sum(c(2:-2)*G)
eG

# 6. Calculi el valor esperat del moviment d'una jugada,
# en el sentit de la longitud.	
G <- c(1:5)
for(j in 1:5)
	G[j] = sum(dices[board[,j]])

eG = sum(c(-2:2)*G)
eG
#########################################################

# 7. Seguidament, indiqui el valor de la desviaci? tipus,
# per al sentit de la latitud.
eT = sum(c(-2:2)*T)
vT = sum((c(-2:2)-eT)^2*T)
sqrt(vT)

# 7. Seguidament, indiqui el valor de la desviaci? tipus,
# per al sentit de la longitud.
eL = sum(c(-2:2)*L)
vL = sum((c(-2:2)-eL)^2*L)
sqrt(vL)

#########################################################
# 8. Quin ?s el valor de la covari?ncia entre el moviment de longitud i
# el moviment de latitud?
# Respongui amb tres decimals de precisi?.	
p8 = 0
for(i in -2:2)
	for(j in -2:2)
		p8 = p8 + (i - eT) * (j - eG) * dices[board[3-i,j+3]]

p8

