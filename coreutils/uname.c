#include "diy.h"
#include "uname.h"

const struct option long_opts[] = {
    {"all",no_argument,0,'a'},
    {"kernel-name",no_argument,0,'s'},
    {"nodename",no_argument,0,'n'},
    {"kernel-release",no_argument,0,'r'},
    {"kernel-version",no_argument,0,'v'},
    {"machine",no_argument,0,'m'},
    {"processor",no_argument,0,'p'},
    {"hardware-platform",no_argument,0,'i'},
    {"operating-system",no_argument,0,'o'},
    {"help",no_argument,0,0},
    {"version",no_argument,0,0},
    {0,0,0,0}
};
char *arguments = "asnrvmpio"; 
int main(int argc,char **argv){
    int c;
    int index = 0;
    struct utsname _uname;
    if(uname(&_uname) < 0){
        
    }
    if(argc == 1){
        uname_s(&_uname);
        puts("");
        exit(EXIT_SUCCESS);
    }
    while((c = getopt_long(argc,argv,arguments,long_opts,&index)) != -1){
        switch(c){
            case 0:
                if(strcmp("help",long_opts[index].name) == 0)
                    uname_help();
                else if(strcmp("version",long_opts[index].name) == 0)
                    uname_version();
                break;
            case 'a':
                uname_a(&_uname);
                break;
            case 's':
                uname_s(&_uname);
                break;
            case 'n':
                uname_n(&_uname);
                break;
            case 'r':
                uname_r(&_uname);
                break;
            case 'v':
                uname_v(&_uname);
                break;
            case 'm':
                uname_m(&_uname);
                break;
        }
        puts("");
    }
}

void uname_a(struct utsname* _uname){
    
   printf("%s ",_uname->sysname); 
   printf("%s ",_uname->nodename); 
   printf("%s ",_uname->release); 
   printf("%s ",_uname->version); 
   printf("%s ",_uname->machine); 
}

void uname_s(struct utsname* _uname){
   printf("%s ",_uname->sysname); 
}

void uname_n(struct utsname* _uname){
   printf("%s ",_uname->nodename); 
}

void uname_r(struct utsname* _uname){
   printf("%s ",_uname->release); 
}

void uname_v(struct utsname* _uname){
   printf("%s ",_uname->version); 
}

void uname_m(struct utsname* _uname){
   printf("%s ",_uname->machine); 
}

void uname_help(){
    printf("用法：uname [选项]...\n"
  "输出一组系统信息。如果不跟随选项，则视为只附加-s 选项。\n"

  "  -a, --all                     以如下次序输出所有信息。其中若-p 和\n"
  "                                -i 的探测结果不可知则被省略：\n"
  "  -s, --kernel-name             输出内核名称\n"
  "  -n, --nodename                输出网络节点上的主机名\n"
  "  -r, --kernel-release          输出内核发行号\n"
  "  -v, --kernel-version          输出内核版本\n"
  "  -m, --machine                 输出主机的硬件架构名称\n"
  "  -p, --processor               输出处理器类型或\"unknown\"\n"
  "  -i, --hardware-platform       输出硬件平台或\"unknown\"\n"
  "  -o, --operating-system        输出操作系统名称\n"
  "      --help                    显示此帮助信息并退出\n"
  "      --version                 显示版本信息并退出\n");
}

void uname_version(){
/*    printf("版本:%.2f\n",1.00);
    printf("未完善的功能及bug请查看<%s>\n",WEBSITE(uname));
    printf("%s\n",AUTHOR);
    */
    __version(1.00,__FILE__);
}
