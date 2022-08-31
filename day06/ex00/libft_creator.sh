#!/bin/sh

gcc -c *.c
ar cr libft.a *.o
rm *.o