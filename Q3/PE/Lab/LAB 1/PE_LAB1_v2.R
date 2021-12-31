k = c(2,4,6,8,10)
p = c(0.01,0.01,0.01,0.01,0.96)
sum(p)
mean(p)
median(p)
E = sum(k*p)
E

V = sum(((k - E)^2)*p)
o = sqrt(V)

p3 = sum(p[1],p[2],p[3],p[4],p[5],p[6],p[7],p[8],p[9])

const = 1.87
p4 = 1/const

t1 = 93.5/60
t2 = 17
p5 = -exp(-const*t2)-(-exp(-const*t1))
