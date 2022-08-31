#!/bin/sh

norminette sastantua_dev.c
echo --------------------------------------------------
gcc -Wall -Wextra -Werror sastantua_dev.c
./result $1 > 1.txt
./a.out $1 > 2.txt
diff 1.txt 2.txt
