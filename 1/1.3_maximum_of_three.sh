#!/bin/bash

#Maximum of three numbers

read -p "Enter three numbers: " n1 n2 n3

large=$n1

if [ $n2 -gt $large ]; then
    large=$n2
fi

if [ $n3 -gt $large ]; then
    large=$n3
fi

echo "Largest number: $large"
