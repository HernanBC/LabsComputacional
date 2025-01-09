#!/usr/bin/env python

import numpy as np

def integrando(x):
    f = 1 /(1+x**2)
    return f

def SumaRiemann(integrando,x_inf,x_sup,NumeroCuadros):
    h = (x_sup - x_inf)/NumeroCuadros
    
    centro_rectangulo = h/2

    x = np.linspace(x_inf + centro_rectangulo,x_sup,NumeroCuadros)

    aux = integrando(x)*h
    
    I =4*np.sum(aux)
    
    return I

print(SumaRiemann(integrando, 0,1,100))

