#!/bin/bash

read -p "Enter a number: " input

rev=0
num=$input 

while (( num > 0 )); do
    d=$((num % 10))
    num=$((num / 10))
    rev=$((rev*10 + d))
done

if [ "$input" = "$rev" ]; then
    echo "$input is a palindrome"
else
    echo "$input is not a palindrome"
fi
