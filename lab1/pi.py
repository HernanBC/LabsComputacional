#!/usr/bin/env python

# Esta es una función para integrar con método de Suma de Riemann,
# para usarla se requiere definir la función del integrando.

# Función integrando
# x corresponde a la variable independiente de la función
def integrando(x):
    f = 4 /(1+x**2)
    return f

# Función Suma de Riemann
# Integrando -> Función a integrar
# x_inf  -> Limite inferior de la integral
# x_sup -> Limite superior de la integral
# NumeroCuadros -> Numero de rectangulos  usandos en la aproximación
def SumaRiemann(integrando,x_inf,x_sup,NumeroCuadros):
    h = (x_sup-x_inf)/NumeroCuadros #Distancia entre pasos

    I = 0
    for i in range(NumeroCuadros):
        I += integrando(x_inf+(i+0.5)*h)*h 
    return I
    

print(SumaRiemann(integrando, 0,1,100))


