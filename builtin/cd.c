#define _GNU_SOURCE
#include<stdio.h>
#include<error.h>
#include<unistd.h>
int main(int argc,char **argv)
{
    if(chdir(argv[1])!=0)
    {
        perror(argv[1]);
    }
        //printf("%s\n",get_current_dir_name());
}
