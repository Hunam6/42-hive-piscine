#!/bin/sh

idx=0

ls -l | while read line
do
    if [ $((idx%2)) -eq 0 ];
    then
        echo $line
    fi
    idx=$((idx+1))
done
