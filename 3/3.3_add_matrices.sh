#!/bin/bash

declare -A A
declare -A B
declare -A C

read -p "Enter the size of the square matrix: " size

echo "please enter the digit and hit on <enter>"
echo "Enter matrix A:"

for ((i=0; i<size; i++)); do
    for ((j=0; j<size; j++)) do
        read A[$i,$j]
    done
done

echo "Enter matrix B:"

for ((i=0; i<size; i++)); do
    for ((j=0; j<size; j++)) do
        read B[$i,$j]
    done
done


echo "Resultant Matrix:"
for ((i=0; i<size; i++)); do
    for ((j=0; j<size; j++)) do
        C[$i,$j]=$((B[$i,$j] + A[$i,$j]))
        echo -n "${C[$i,$j]} "
    done
    echo ""
done


