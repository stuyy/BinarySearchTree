#!/bin/sh

if [ "$1" == 'gcc' ]
then
    gcc main.c -o main.o

else
    ./main.o
fi