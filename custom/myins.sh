#!/bin/bash
if [ -z $1 ];then
    echo "缺少参数"
else
    sudo apt-get install $1
fi

