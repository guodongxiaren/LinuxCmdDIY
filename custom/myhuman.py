#!/usr/bin/env python
# coding=utf-8
import sys,getopt,string
def seconds(s):
    rr=''
    if s>=3600:
        r=s/3600
        s%=3600
        rr='%d' %r
        rr+='h'
    if s>=60:
        r=s/60
        s%=60
        rr+='%d'%r
        rr+='m'
    rr+='%d'%s
    rr+='s'
    print rr
    
opts,args = getopt.getopt(sys.argv[1:],"b:s:")
for op,value in opts:
    if op =='-s':
        s=string.atoi(value)
        seconds(s)

