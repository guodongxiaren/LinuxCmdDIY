#include<stdio.h>
#include<getopt.h>
#include<string.h>
#include<errno.h>
#include<sys/stat.h>
#include<sys/types.h>
int main(int argc,char **argv)
{
    if(argc==1)
    {
        puts("mkdir:缺少操作数");
        puts("尝试'mkdir --help'获取更多信息");
        return;
    }
    char *pathname=argv[1];
    const struct option long_options[]=
    {
        {"mode",0,NULL,'m'},
        {"parent",0,NULL,'p'},
        {"verbose",0,NULL,'v'},
        {NULL,0,NULL,0}
    };
    int next_option;
    do
    {
        next_option = getopt_long(argc,argv,"mp:v",long_options,NULL);
        //puts(optarg);
        switch(next_option)
        {
        case 'm':
            break;
        case 'p':
            if(mkdir(optarg,0775)!=0)
            {
                printf("%s\n",strerror(errno));
            }
            break;
        case 'v':
            break;
        }
    }
    while(next_option!=-1);
}

