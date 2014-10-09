#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<sys/stat.h>
#include<sys/types.h>
int main(int argc,char **argv)
{
    char *pathname=argv[1];
    if(mkdir(pathname,0775)!=0)
    {
        printf("%s\n",strerror(errno));
    }
}

