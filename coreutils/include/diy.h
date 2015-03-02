#ifndef _DIY_H
#define _DIY_H

#include <errno.h>
#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/utsname.h>

//打印版本信息时的每个命令的网址
#define WEBSITE "https://github.com/guodongxiaren/LinuxCmdDIY/wiki/"
//打印版本信息时的作者的标识
#define AUTHOR "\n由guodongxiaren编写\n" \
               "博客地址  ：http://blog.csdn.net/guodongxiaren\n" \
               "GitHub地址：https://github.com/guodongxiaren"
//版本信息打印函数
void __version(float versionid,char *name);

#endif
