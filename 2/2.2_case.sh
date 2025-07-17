#!/bin/bash

#generate fibonacci series upto a limit

read -p "Enter two numbers: " n1 n2

read -p "Enter the operand + - * /: " op

case "$op" in
    "+")
        echo "Anser = $(( n1 + n2 ))"
        ;;
    "-")
        echo "Anser = $(( n1 - n2 ))"
        ;;
    "*")
        echo "Anser = $(( n1 * n2 ))"
        ;;
    "/")
        echo "Anser = $(( n1 / n2 ))"
        ;;
    *)
        echo "Unknown operand"
        ;;
esac
