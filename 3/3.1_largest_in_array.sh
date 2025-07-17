#!/bin/bash

read -p "Enter array elements (space-separated): " -a arr

echo "You entered: ${arr[@]}"

largest=${arr[0]}
for i in ${arr[@]}; do
    if ((largest < arr[i])); then 
        largest=${arr[i]}
    fi
done


echo "Largest = $largest"
