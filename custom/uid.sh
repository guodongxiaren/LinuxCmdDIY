#!/bin/bash
# 根据id查询用户
# id命令指定根据用户查询id
grep $1 /etc/passwd|awk -F: '{print $1}'
