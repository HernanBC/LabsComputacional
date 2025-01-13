#!/usr/bin/env python3
#Gabriel Alvarez Castrillo C00368
#Vamos a resolver la integral de 4/(1+x**2) de 0 a 1 para encontrar pi
#Espacio de Funciones
def Int_Riemann(func,x_inf,x_sup,steps):
    h = (x_sup-x_inf)/steps #Distancia entre pasos
    I = 0
    for i in range(steps):
        I += func(x_inf+(i+0.5)*h)*h #Evaluamos la func. en cada paso
    return I
#Función a Integrar
def func_integrar(x):
    return 4/(1+x**2)

#Main code
step = 1000
x_inf = 0
x_sup = 1
print(Int_Riemann(func_integrar,x_inf,x_sup,step))




