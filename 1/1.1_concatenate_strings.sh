#!/bin/bash

#Concatenation of two strings

read -p "Enter two strings: " str1 str2

res=$str1$str2

echo "Concatenated string: ${res}"
