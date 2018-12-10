#!/bin/sh

if [ "$1" == 'gcc' ]
then
    gcc main.c -o main.o 
    gcc tree.c -o tree.o

else
    ./main.o
fi