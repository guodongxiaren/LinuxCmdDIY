#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
int main(int argc,char **argv)
{
    char *filename = argv[1];
    if(!access(filename,F_OK))
    {
        fprintf(stderr,"mkfifo：无法创建先进先出文件\"%s\"：文件已存在\n",
                filename);
        exit(1);
    }
    mode_t mode=0664;
    if(mkfifo(filename,mode)!=0)
    {
        
    }
}

