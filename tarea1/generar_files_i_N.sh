#! /bin/bash

for i in $(seq 0 ${1}); do # Recorrer el ciclo para la cantidad de archivos solicitados
	touch rand_${i}_${2}.dat # Crear los archivos segun el formato de nombre solicitado
	for j in $(seq 1 ${2}); do # Con este ciclo se llena cada archivo según la cantidad de números aleatorios solicitados
		out=$(./random.sh) # Se corre el bash script dado y se almacena el resultado
		first_number=$(echo "$out" | grep -E '^[0-9]+$' | head -n 1) # Filtrando para obtener solo el primer número del ootput del punto anterior
		echo "$first_number" >> rand_${i}_${2}.dat # Concatenando el número obtenido en el respectivo archivo
	done # cierro ciclo
done # cierro ciclo
