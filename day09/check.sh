#!/bin/sh

if [ "$1" == "" ];
then
	norminette -R CheckForbiddenSourceHeader
else
	cd $1
	norminette -R CheckForbiddenSourceHeader
	echo --------------------------------------------------
	gcc -Wall -Wextra -Werror $(ls | grep _dev.c)
	./a.out "preSidENt\0    " "udfgdgfd g" "ggfg"
fi
