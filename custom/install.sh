#!/bin/bash
dir="/usr/local/bin/"
for i in my*
do
    if [ $i -nt "$dir/$i" ];then
        chmod u+x $i
        sudo cp $i $dir/${i%*.*}
    fi
done
