The manufacturer of a new fiberglass tire claims that its average life will 
be at least 40,000 miles. To verify this claim a sample of 11 tires is 
tested, with their lifetimes (in 1,000 of miles) being as follows:
 
### PREGUNTA 1 ### 
1. The null hypothesis is as follows:
H0: µ = µ0
 
Which should be the value of µ0?      
 
40000/1000 = 40
 
 

### PREGUNTA 2 ### 
# We want to test the claim from the user's point of view (who suspects about
# the tire's quality). What is the correct direction to take into account
# this point of view?
# 1 one-sided (to the right, >)
# 2 one-sided (to the left, <)
# 3 two-sided (!=)
# Right: the user has real doubts about the claim, and this test can prove
# that the manufacturer is exaggerating the tires performance.
 
sum = c(32.7,37.4,42.5,36.7,39.1,45.7,32.3,32.1,37.7,39.5,38.8,40.5,43.9,44.7,40.9)
mean(sum) = 38.96667

# como la media es inferior a 40, queda a la izquierda, la respuesta es 2
# (si es suspects, si es spects seria 3)
 


### PREGUNTA 3 ### 
# Which is the sample estimation of the mean life for the new tires?
 
mean(sum)
 


### PREGUNTA 4 ###  
# Find the value of the test statistic (three figures).
 
P4 = (mean(sum)-40)/(sd(sum)/sqrt(length(sum))) 
P4 


### PREGUNTA 5 ###  
# Compute the p-value of the test data (three figures).
 
P5 = 1-pt(abs(P4),length(sum)-1)
P5 	# si P5 pequeño es P5
	# sino es pt(abs(P4),length(sum)-1)




### PREGUNTA 6 ###  
# Find a 99 percent confidence interval for the mean life of the tires tested
# (two figures of accuracy).      

porcent = 99
p1 = mean(sum)-qt(1-((1-porcent/100)/2),length(sum)-1)*(sd(sum)/sqrt(length(sum)))
p2 = mean(sum)+qt(1-((1-porcent/100)/2),length(sum)-1)*(sd(sum)/sqrt(length(sum)))
 
p1
p2
 



### PREGUNTA 7 ###  
# Compute the standard deviation of the preceding data, up to an accuracy
# of 1 mile (but answer with the unit in thousands of miles).
 
sd(sum)
 
 

### PREGUNTA 8 ### 
# Find a 99 percent confidence interval for the variance of the tires life
# (two figures of accuracy)
 
porcent = 99
top = sd(sum)^2 * (length(sum)-1)
risk = 1 - porcent/100
paste(top/qchisq(1-risk/2, length(sum)-1), top/qchisq(risk/2, length(sum)-1))



.