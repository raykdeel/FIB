#Competencia gasolinera
#Valores.
G<-c(1.509,1.439,1.507,1.572,1.579,1.508,1.502,1.494,1.47,1.455)
H<-c(1.446,1.462)
 
#1.
sd(G)
 
#2.
sd(H)
 
#3.
if(var(G) > var(H)){
temp = 1
estadistico = var(G)/var(H)
estadistico
}else{
temp = 0
estadistico = var(H)/var(G)
estadistico
}
 
#4.
if(temp == 1){
df1 = length(G)-1
df2 = length(H)-1
}else{
df1 = length(H)-1
df2 = length(G)-1
}
df1
df2
 
#5.
qf(0.975,9,1)
 
#6.
qf(0.025,9,1)
 
#7.
pvalor = 2*(1- pf(estadistico,df1,df2))
pvalor
 
#8.
if(pvalor > 0.05) "2.no hemos hallado evidencias de que las dos marcas difieran en dispersión del precio."
if(pvalor < 0.05) "1.hemos conseguido demostrar que el coste de G y H no es el mismo."
if(pvalor == 0.05) "3.tenemos pruebas de que las dos variancias pueden ser idénticas."
 
#9.
prob = 0.337
glib1 = 12
glib2 = 12
qf((1-prob),glib1,glib2)