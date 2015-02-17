#include "diy.h"
static char *name(char *filename){
    char *buf;
    buf = (char *)malloc(10);
    sscanf(filename,"%[^.]",buf);
    return buf;
}

void __version(float versionid,char *filename){
    printf("版本：%.2f\n",versionid);
    printf("待完善功能及bug请查看<%s%s>\n",WEBSITE,name(filename));
    printf("%s\n",AUTHOR);
}

