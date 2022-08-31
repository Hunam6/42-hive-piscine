#!/bin/sh

if [ "$1" == "" ];
then
	norminette
else
	cd $1
	norminette
	echo --------------------------------------------------
	gcc -Wall -Wextra -Werror $(ls | grep _dev.c)
	./a.out
fi
