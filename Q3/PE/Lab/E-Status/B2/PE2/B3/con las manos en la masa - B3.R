#### CON LAS MANOS EN LA MASA ####
Cecilia es una aficionada a la pintura, a la fotograf�a y al cine en general, 
pero lo que m�s le gusta es guardarse los v�deos de cocina de Karlos Argui�ano 
para inspirarse en sus obras, esperando que un d�a sean conocidas por el mundo
entero. Ya se ha dado cuenta de que Argui�ano pierde el sentido del tiempo 
mientras explica sus recetas, y que la duraci�n de estos v�deos es 
considerablemente variable. Lo que es cierto es que un v�deo, en promedio, 
dura 5.9 minutos, y que la duraci�n de uno es independiente de la de los dem�s.
Cecilia archiva sus recetas en colecciones de 70 v�deos.

######################
##### Pregunta 1 #####
######################
# Suponga que la distribuci�n de la duraci�n de un v�deo es exponencial. 
# �Cu�nto vale su variancia?

promedio = 5.9
lambda = 1/(promedio)
esp = 1/lambda
var = 1/(lambda^2)	# esquivalente: var = esp^2
var	


### Suponga que la distribuci�n de la duraci�n de un v�deo es uniforme, 
### con extremo inferior = 4.7 minutos. �Cu�nto vale su variancia?
### usamos: ((b-a)^2)/12
      #promedio = 5.9
	#a = 4.7 	# extremo inferior
	#b = (promedio-a)+promedio
	#var = ((b-a)^2)/12
	#var   



######################
##### Pregunta 2 #####    0.3805637
######################
# �Probabilidad de que un v�deo dure por lo menos 5.17 minutos?

x = 5.17   #promedio por hora
lambda
p = 1 - pexp(x,lambda) 	# probabilidad de que dure por lo menos x
p
r = pexp(x,lambda)	# probabilidad de que dure menos de x
r


######################
##### Pregunta 3 #####
######################
# �Probabilidad de que Argui�ano emplee en una receta un tiempo 
# superior a 9.57  minutos?

x = 9.57 
p = 1-pexp(x, lambda)  	# probabilidad de que dure mas de x
p
r = pexp(x, lambda)	# probabilidad de que dure menos de x
r


######################
##### Pregunta 4 #####
######################
# Cada colecci�n de 70 v�deos es grabada en un DVD con capacidad de 4.3 GB
# (1GB = 1024MB). Teniendo en cuenta que aproximadamente un minuto de
# grabaci�n se corresponde con 9.9 MB de espacio en disco, calcule la
# probabilidad de que Cecilia no pueda grabar todos esos v�deos en un DVD
# porque excede su capacidad.	


promedio = 5.9 
MBxMIN = 9.9
VIDxCOL = 70
capacidadmax = 4.3 * 1024 / MBxMIN
promedio2 = promedio * VIDxCOL
sd2 = sqrt(var) * sqrt(VIDxCOL)
Z = (capacidadmax - promedio2) / sd2
1 - pnorm(Z) #RESULTADO


######################
##### Pregunta 5 #####
######################
# �Cu�l es el tama�o m�ximo en MB (con probabilidad 99%) que puede alcanzar
# una colecci�n? (Redondee al entero m�s pr�ximo).

prob = 0.99
pvalor = qnorm(prob)
pvalor2 = (pvalor*sd2) + promedio2
pvalor2 * MBxMIN #RESULTADO (coger el entero m�s cercano)


######################
##### Pregunta 6 #####
######################
# �Cu�ntos v�deos deber�a incluir una colecci�n para tener una seguridad del
# 95% de que cabr� en un DVD? (Redondee el resultado a un entero por defecto).

# Este lo he hecho probando resultados. Sorry por ser cutre
    promedioa = promedio * (VIDxCOL+0) 
    promediob = promedio * (VIDxCOL+1)
    promedioc = promedio * (VIDxCOL+2)
    promediod = promedio * (VIDxCOL+3)
    promedioe = promedio * (VIDxCOL+4)
    promediof = promedio * (VIDxCOL+5)
promediog = promedio * (VIDxCOL-1)
promedioh = promedio * (VIDxCOL-2)
promedioi = promedio * (VIDxCOL-3)
promedioj = promedio * (VIDxCOL-4)

    sda = sqrt(var) * sqrt((VIDxCOL+0))
    sdb = sqrt(var) * sqrt((VIDxCOL+1))
    sdc = sqrt(var) * sqrt((VIDxCOL+2))
    sdd = sqrt(var) * sqrt((VIDxCOL+3))
    sde = sqrt(var) * sqrt((VIDxCOL+4))
    sdf = sqrt(var) * sqrt((VIDxCOL+5))
sdg = sqrt(var) * sqrt((VIDxCOL-1))
sdh = sqrt(var) * sqrt((VIDxCOL-2))
sdi = sqrt(var) * sqrt((VIDxCOL-3))
sdj = sqrt(var) * sqrt((VIDxCOL-4))
     
    prob2 = 0.95
    pvalor3 = qnorm(prob2)

    pvalora = (pvalor3*sda) + promedioa
    pvalora * MBxMIN
    pvalorb = (pvalor3*sdb) + promediob
    pvalorb * MBxMIN
    pvalorc = (pvalor3*sdc) + promedioc
    pvalorc * MBxMIN
    pvalord = (pvalor3*sdd) + promediod
    pvalord * MBxMIN
    pvalore = (pvalor3*sde) + promedioe
    pvalore * MBxMIN
    pvalorf = (pvalor3*sdf) + promediof
    pvalorf * MBxMIN
pvalorg = (pvalor3*sdg) + promediog
pvalorg * MBxMIN
pvalorh = (pvalor3*sdh) + promedioh
pvalorh * MBxMIN
pvalori = (pvalor3*sdi) + promedioi
pvalori * MBxMIN
pvalorj = (pvalor3*sdj) + promedioj
pvalorj * MBxMIN

     
    #COMPARAR RESULTADOS Y COGER EL QUE MAS SE ACERQUE A 4.3*1024=4403.2,
    # EN MI CASO VIDxCOL -8 = 70-8 = 62
    # caso para 70-7:
        	# promedioj = promedio * (VIDxCOL-7)
		# sdj = sqrt(var) * sqrt((VIDxCOL-7))
		# pvalorj = (pvalor3*sdj) + promedioj
		# pvalorj * MBxMIN
    		#caso para 70-8:
		# promedioj = promedio * (VIDxCOL-8)
		# sdj = sqrt(var) * sqrt((VIDxCOL-8))
		# pvalorj = (pvalor3*sdj) + promedioj
		# pvalorj * MBxMIN



