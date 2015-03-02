#include "diy.h"
#include "mkdir.h"

const char *arguments = "m:p:";
const struct option long_opts[]=
{
    {"mode",required_argument,NULL,'m'},
    {"parent",required_argument,NULL,'p'},
    {"help",no_argument,NULL,0},
    {"verbose",no_argument,NULL,0},
    {"version",no_argument,NULL,0},
    {NULL,0,NULL,0}
};
int main(int argc,char **argv){
    if(argc==1){
        puts("mkdir:缺少操作数");
        puts("尝试'mkdir --help'获取更多信息");
        return 1;
    }
    char *pathname=argv[1];
    int option,index;
    while((option = getopt_long(argc,argv,arguments,long_opts,&index)) != -1){
        switch(option){
            case 0:
                if(strcmp("help",long_opts[index].name) == 0)
                    mkdir_help();
                else if(strcmp("verbose",long_opts[index].name) == 0) 
                    mkdir_verbose();
                else if(strcmp("version",long_opts[index].name) == 0) 
                    mkdir_version();
                break;
            case 'm':
                mkdir_m();
                break;
            case 'p':
                mkdir_p();
                break;
            default:
            printf("%s\n",argv[1]);
        }
    }
}

void mkdir_m(){

}
void mkdir_p(){
    if(mkdir(optarg,0775)!=0){
        printf("%s\n",strerror(errno));
    }
}
void mkdir_help(){

}
void mkdir_verbose(){
    
}
void mkdir_version(){
    __version(0.50,__FILE__);
}
