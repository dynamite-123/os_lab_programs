#!/bin/bash

#generate fibonacci series upto a limit

read -p "Enter the limit: " limit


n1=0
n2=1

echo "Fibonacci series: "
echo -n "$n1 $n2 "

n3=$((n1 + n2))
while (( n1+n2 < limit )); do
    n3=$((n1 + n2))
    n1=$n2
    n2=$n3
    echo -n "$n3 "
done
