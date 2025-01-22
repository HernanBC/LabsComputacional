#! /bin/bash

for i in $(seq 0 ${1}); do
	touch rand_${i}_${2}.dat
	for j in $(seq 1 ${2}); do
		out=$(./random.sh)
		first_number=$(echo "$out" | grep -E '^[1-9]+$' | head -n 1)
		echo "$first_number" >> rand_${i}_${2}.dat
	done
done
