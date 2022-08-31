#!/bin/sh

start=$FT_LINE1
end=$FT_LINE2
idx=0
every_other=""
echo $every_other
 
cat /etc/passwd | while read line
do
    if [ "${line::1}" != "#" ] && [ $(($idx%2)) -ne 0 ];
    then
        every_other="${every_other}\n${line}"
    fi
    idx=$(($idx+1))
done

echo $every_other
echo end

idx=0
portion=""



for line in $every_other
do
    if [ $idx -ge $start ] && [ $idx -le $end ];
    then
        echo hey
        #portion+=$line
    fi
    echo idx
    idx=$(($idx+1))
done

echo $portion

# && [ $idx -ge $start ] && [ $idx -le $end ]