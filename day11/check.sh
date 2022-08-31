#!/bin/sh

if [ "$1" == "" ];
then
	norminette
else
	cd $1
	norminette
	echo --------------------------------------------------
	gcc $(ls | grep _dev.c)
	./a.out first two three
fi
