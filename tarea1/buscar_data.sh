#! /bin/bash

numero_archivos=$(ls rand_*.dat | wc -l) # Para saber cuantos archivos con números aleatorios hay

paste $(ls rand_*.dat | sort -V) > rand_${numero_archivos}.dat # Para poner las columnas de cada archivo una al lado de la otra en un nuevo archivo en orden

